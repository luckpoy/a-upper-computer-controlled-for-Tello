#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qffmpeg.h"
#include "rtspthread.h"

#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <QDebug>
#include <QHostAddress>
#include <QUdpSocket>
#include <QMessageBox>
#include <QMutex>
#include <QBuffer>
#include <QTime>
#include <QDateTime>
#include <QFile>
using namespace cv;

QUdpSocket* UDPServer;
QFile file("C:\\Users\\mob\\Desktop\\time.txt");

QFFmpeg* ffmpeg;
void sleep(unsigned int msec);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("logo.ico"));
    setWindowTitle(tr("Tello Control Terminal Of PC"));
    QPixmap pixmap = QPixmap(":/image/back/beijing.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    UDPServer = new QUdpSocket();

    connect(ui->Connect, SIGNAL(clicked()), this, SLOT(myconnect()));
}

MainWindow::~MainWindow()
{
    file.close();
    delete ui;
}

void MainWindow::send(QString str)
{
    if(str.isEmpty())
    {
        return;
    }
    //QHostAddress::Broadcast,指定向广播地址发送
    int length = UDPServer->writeDatagram(str.toUtf8(), QHostAddress("192.168.10.1"),sendport);        //向指定端口发送数据
    if(length != str.length())
    {
        QMessageBox::information(this, "消息提示", "发送失败！");
        return;
    }
    ui->showSendtext->append(str);
}

void MainWindow::myconnect()
{
    sendport = ui->send_port->text().toInt();
    recvport = ui->recv_Port->text().toInt();

    bool bindResult = UDPServer->bind(/*QHostAddress("0.0.0.0"),*/ recvport);   //接收数据时，需要将SOCKET与接收端口绑定在一起
    if(!bindResult)
    {
        QMessageBox::information(this, "消息提示", "bind失败！");
        return;
    }

    //connect slot
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendData())); //绑定发送
    connect(ui->replace_recvport, SIGNAL(clicked()), this, SLOT(streamon()));
    connect(UDPServer, SIGNAL(readyRead()), this, SLOT(recvData()));    //绑定接收
    connect(ui->finit, SIGNAL(clicked()), this, SLOT(udp()));
    connect(ui->startcontrol, SIGNAL(clicked()), this, SLOT(controlstart()));
    send("command");
}

void MainWindow::udp()//解码初始化
{
    ffmpeg = new QFFmpeg(this);
    qDebug()<<"开始解码初始化";
    ffmpeg->SetUrl("udp://0.0.0.0:11111");
    if(ffmpeg->Init())
    {
        RtspThread *rtsp=new RtspThread(this);
        rtsp->setffmpeg(ffmpeg);
        rtsp->start();
    }
    qDebug()<<"解码初始化成功";
    connect(ffmpeg,SIGNAL(GetImage(QImage)),this,SLOT(SetImage(QImage)));
}

//发送函数
void MainWindow::sendData()
{
    QString sendStr = ui->sendline->text();
    send(sendStr);
}

//接收数据函数
void MainWindow::recvData()
{
    while(UDPServer->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(UDPServer->pendingDatagramSize());
        UDPServer->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.data();
        ui->showRecvtext->append(msg);
        qDebug()<<msg.toUtf8();
    }
}

void MainWindow::streamon()
{
    QString sendStr = "streamon";
    send(sendStr);
}

void MainWindow::SetImage(const QImage &image)
{
    if(image.height()>0){//显示原图
        QImage image2 = image.mirrored(false, true);
        QPixmap pix = QPixmap::fromImage(image2.scaled(211,151));
        ui->imglable->setPixmap(pix);

        //处理图片
        Mat mat=Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        //cv::cvtColor(mat, mat, CV_BGR2RGB);
        cv::resize(mat,mat,Size(211,151));
        //边缘检测
        GaussianBlur(mat, mat, Size(3, 3), 0, 0, BORDER_DEFAULT);
        Canny(mat, mat, 100, 150, 3);

        int g1=130,g2=50;
        Mat dst=mat;
        int i=0,j=0;
        for(;i<211;i++){
            if(dst.at<uchar>(g1, i)==255){
                break;
            }
        }
        for(;j<211;j++){
            if(dst.at<uchar>(g2, j)==255){
                break;
            }
        }

        chazhi=((float)(i-j)/(float)(g1-g2));
        chazhi1=(int)((i+j-211)/3);
        qDebug()<<"偏差值："<<chazhi;
        emit contorl();
        //转格式绘图
        cvtColor(dst, dst, CV_GRAY2RGB);
        line(dst, Point(0,g1), Point(211,g1), Scalar(0, 255, 0), 1, 0);
        circle(dst,Point(i,g1), 10, Scalar(0, 0, 150));
        line(dst, Point(0,g2), Point(211,g2), Scalar(0, 255, 0), 1, 0);
        circle(dst,Point(j,g2), 10, Scalar(0, 0, 150));
        line(dst, Point(i,g1), Point(j,g2), Scalar(0, 255, 100), 1, 0);
        cv::cvtColor(dst,dst,CV_RGB2BGR);

        //显示处理结果
        const uchar *pSrc = (const uchar*)dst.data;     //复制像素
        QImage image1(pSrc, dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
        image1 = image1.mirrored(false, true);
        QPixmap pix1 = QPixmap::fromImage(image1.scaled(211,151));
        ui->srcimglable->setPixmap(pix1);
    }
}

void MainWindow::controlsend()
{
    QString str=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")+"\n";
    QByteArray bytes = str.toUtf8();
    file.write(bytes);
    int t=(int)(chazhi*250);
    if(t>40)
        t=100;
    else if(t<-40)
        t=-100;
    /*else if(t>50)
        t=80;
    else if(t<-50)
        t=-80;
    else if(t>30)
        t=50;
    else if(t<-30)
        t=-50;*/
    QString s;
    s="rc "+QString::number(chazhi1)+" 30 0 "+QString::number(t);
    send(s);
}

void MainWindow::controlstart()
{
    send("takeoff");
    sleep(1000);
    connect(this,SIGNAL(contorl()),this,SLOT(controlsend()));
    file.open(QIODevice::WriteOnly | QIODevice::Text);
}


void drawhouph(vector<Vec2f> & lines , Mat & img, int x)
{
    //这里得到的lines是包含rho和theta的，而不包括直线上的点，所以下面需要根据得到的rho和theta来建立一条直线
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0]; //就是圆的半径r
        float theta = lines[i][1]; //就是直线的角度
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000 * (a));

        line(img, pt1, pt2, Scalar(0, x, 0), 1, 0); //Scalar函数用于调节线段颜色，就是你想检测到的线段显示的是什么颜色
        qDebug()<<"draw lines!";
    }
}

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
