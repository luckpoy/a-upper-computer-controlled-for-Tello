#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostAddress>
#include <QUdpSocket>
#include <QMessageBox>
#include <QMutex>

QMutex mutex;
AVPicture  pAVPicture;
AVFormatContext *pAVFormatContext;
AVCodecContext *pAVCodecContext;
AVFrame *pAVFrame;
SwsContext * pSwsContext;
AVPacket pAVPacket;

QUdpSocket* UDPServer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("logo.ico"));
    setWindowTitle(tr("Tello Control Terminal Of PC"));

    qDebug() <<avcodec_configuration();
    unsigned version = avcodec_version();
    QString ch = QString::number(version,10);
    qDebug() <<"version:"<<version;


    UDPServer = new QUdpSocket();
    sendport = ui->send_port->text().toInt();
    recvport = ui->recv_Port->text().toInt();

    bool bindResult = UDPServer->bind(/*QHostAddress("192.168.10.1"), */recvport);   //接收数据时，需要将SOCKET与接收端口绑定在一起
    if(!bindResult)
    {
        QMessageBox::information(this, "消息提示", "bind失败！");
        return;
    }

    av_register_all();//注册库中所有可用的文件格式和解码器
    avformat_network_init();//初始化网络流格式,使用RTSP网络流时必须先执行
    pAVFormatContext = avformat_alloc_context();//申请一个AVFormatContext结构的内存,并进行简单初始化
    pAVFrame=av_frame_alloc();

    //connect slot
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendData())); //绑定发送
    connect(UDPServer, SIGNAL(readyRead()), this, SLOT(recvData()));    //绑定接收
}


MainWindow::~MainWindow()
{
    avformat_free_context(pAVFormatContext);
    av_frame_free(&pAVFrame);
    sws_freeContext(pSwsContext);
    delete ui;
}

//发送函数
void MainWindow::sendData()
{
    QString sendStr = ui->sendline->text();
    if(sendStr.isEmpty())
    {
        return;
    }

    //QHostAddress::Broadcast,指定向广播地址发送
    int length = UDPServer->writeDatagram(sendStr.toUtf8(), QHostAddress("192.168.10.1"),sendport);        //向指定端口发送数据
    if(length != sendStr.length())
    {
        QMessageBox::information(this, "消息提示", "发送失败！");
        return;
    }
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



    }
}
