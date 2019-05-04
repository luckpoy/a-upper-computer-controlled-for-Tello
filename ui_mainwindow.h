/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *send_port;
    QLabel *label;
    QLineEdit *recv_Port;
    QLabel *label_2;
    QTextBrowser *showRecvtext;
    QPushButton *sendButton;
    QLineEdit *sendline;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *imglable;
    QPushButton *replace_recvport;
    QPushButton *finit;
    QLabel *srcimglable;
    QTextBrowser *showSendtext;
    QPushButton *startcontrol;
    QLabel *label_4;
    QPushButton *Connect;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(494, 315);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        send_port = new QLineEdit(centralWidget);
        send_port->setObjectName(QStringLiteral("send_port"));
        send_port->setGeometry(QRect(80, 10, 101, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 51, 20));
        recv_Port = new QLineEdit(centralWidget);
        recv_Port->setObjectName(QStringLiteral("recv_Port"));
        recv_Port->setGeometry(QRect(80, 40, 101, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 51, 20));
        showRecvtext = new QTextBrowser(centralWidget);
        showRecvtext->setObjectName(QStringLiteral("showRecvtext"));
        showRecvtext->setGeometry(QRect(10, 80, 111, 111));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(10, 200, 61, 23));
        sendline = new QLineEdit(centralWidget);
        sendline->setObjectName(QStringLiteral("sendline"));
        sendline->setGeometry(QRect(157, 200, 91, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 200, 51, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 260, 221, 51));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/image/logo/logo.png")));
        label_10->setScaledContents(true);
        imglable = new QLabel(centralWidget);
        imglable->setObjectName(QStringLiteral("imglable"));
        imglable->setGeometry(QRect(270, 0, 211, 151));
        imglable->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        replace_recvport = new QPushButton(centralWidget);
        replace_recvport->setObjectName(QStringLiteral("replace_recvport"));
        replace_recvport->setGeometry(QRect(10, 230, 61, 23));
        finit = new QPushButton(centralWidget);
        finit->setObjectName(QStringLiteral("finit"));
        finit->setGeometry(QRect(100, 230, 61, 23));
        srcimglable = new QLabel(centralWidget);
        srcimglable->setObjectName(QStringLiteral("srcimglable"));
        srcimglable->setGeometry(QRect(270, 160, 211, 151));
        srcimglable->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        showSendtext = new QTextBrowser(centralWidget);
        showSendtext->setObjectName(QStringLiteral("showSendtext"));
        showSendtext->setGeometry(QRect(140, 80, 111, 111));
        startcontrol = new QPushButton(centralWidget);
        startcontrol->setObjectName(QStringLiteral("startcontrol"));
        startcontrol->setGeometry(QRect(190, 230, 61, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 60, 61, 20));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(190, 20, 61, 31));
        Connect->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 60, 61, 20));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        send_port->setText(QApplication::translate("MainWindow", "8889", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "sendport:", Q_NULLPTR));
        recv_Port->setText(QApplication::translate("MainWindow", "1111", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "recvport:", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        sendButton->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
        sendline->setText(QApplication::translate("MainWindow", "land", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "sendline:", Q_NULLPTR));
        label_10->setText(QString());
        imglable->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        replace_recvport->setText(QApplication::translate("MainWindow", "streamon", Q_NULLPTR));
        finit->setText(QApplication::translate("MainWindow", "finit", Q_NULLPTR));
        srcimglable->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        startcontrol->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "recvtext:", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "sendtext:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
