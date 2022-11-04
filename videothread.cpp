#include "videothread.h"
#include <QDebug>
#include "wireless.h"


Wireless wl;


VideoThread::VideoThread(QString s) : name(s)
{
    qDebug() << "Thread " << this->name << " created";
}


void VideoThread::run()
{
    qDebug() << "Thread " << this->name << " running";

    wl.Init();

    while (1)
    {
        wl.Receive();
        QThread::msleep(10);
    }
}
