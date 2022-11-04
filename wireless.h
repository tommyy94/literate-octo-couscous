#ifndef WIRELESS_H
#define WIRELESS_H

#include <QObject>

class Wireless : public QObject
{
    Q_OBJECT
public:
    explicit Wireless(QObject *parent = nullptr);
    ~Wireless();
    void Init(void);
    void Receive(void);

signals:
    void TransmitImageToGUI(char *image, int size);
};

#endif // WIRELESS_H
