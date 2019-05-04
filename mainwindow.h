#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif
using namespace std;
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
}

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int sendport;
    int recvport;
    float chazhi;
    int chazhi1;
    void send(QString str);
   // void encode();
   // bool Init();

private slots:
    void myconnect();
    void udp();
    void sendData();
    void recvData();
    void streamon();
    void SetImage(const QImage &image);
    void controlsend();
    void controlstart();

signals:
    void contorl();
};

#endif // MAINWINDOW_H
