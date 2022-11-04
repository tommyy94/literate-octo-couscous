#include "mainwindow.h"
#include "videothread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    VideoThread vThread("video");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    vThread.start(QThread::NormalPriority);

    return a.exec();
}
