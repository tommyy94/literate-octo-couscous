#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include <QString>


class VideoThread : public QThread
{
public:
    // constructor
    // set name using initializer
    explicit VideoThread(QString s);

    // overriding the QThread's run() method
    void run();
private:
    QString name;
};


#endif /* VIDEOTHREAD_H */
