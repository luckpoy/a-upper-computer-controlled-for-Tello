#-------------------------------------------------
#
# Project created by QtCreator 2019-04-29T13:58:05
#
#-------------------------------------------------

QT       += core gui
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tello
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:\Qt_opencv\install\include\
INCLUDEPATH += D:\Qt_opencv\install\include\opencv\
INCLUDEPATH += D:\Qt_opencv\install\include\opencv2\

LIBS += D:\Qt_opencv\install\x86\mingw\lib\libopencv_*.a

RC_ICONS = logo.ico

RESOURCES += \
    image.qrc

INCLUDEPATH+=D:/FFMPEG/dev/include
LIBS+=D:/FFMPEG/dev/lib/libavcodec.dll.a\
      D:/FFMPEG/dev/lib/libavdevice.dll.a\
      D:/FFMPEG/dev/lib/libavfilter.dll.a\
      D:/FFMPEG/dev/lib/libavformat.dll.a\
      D:/FFMPEG/dev/lib/libavutil.dll.a\
      D:/FFMPEG/dev/lib/libswresample.dll.a\
      D:/FFMPEG/dev/lib/libswscale.dll.a\
      D:/FFMPEG/dev/lib/libpostproc.dll.a
