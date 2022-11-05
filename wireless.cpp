#include "wireless.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <QDebug>
#include "radioframe.h"


#define WIFI_M2M_SERVER_IP        0xC0A80132    // 192.168.1.50
#define WIFI_M2M_PC_IP            0xC0A8010A    // 192.168.1.10
#define WIFI_M2M_CLIENT_IP        0xC0A80133    // 192.168.1.51

#define WIFI_M2M_VIDEO_PORT       (6666)
#define WIFI_M2M_SENSOR_PORT      (6667)
#define WIFI_M2M_CONTROL_PORT     (6668)


char remoteJpg[4954];

struct sockaddr_in  servaddr;
int                 sockfd;




Wireless::Wireless(QObject *parent)
    : QObject{parent}
{

}

Wireless::~Wireless()
{

}


void Wireless::Init(void)
{
    /* Creating socket file descriptor */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Wireless_Init: socket creation failed\r\n");
        exit(EXIT_FAILURE);
    }

    /* Filling server information */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(WIFI_M2M_VIDEO_PORT);
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.50");
    //servaddr.sin_addr.s_addr = htonl(WIFI_M2M_PC_IP);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Wireless_Init: bind failed\r\n");
        exit(EXIT_FAILURE);
    }
}


void Wireless::Receive(void)
{
    int32_t             len;
    uint32_t            idx;
    uint32_t            bytesRecv;
    RadioFrame_t        frame;

    /* Serialize the struct we build */
    char               *frameHdrPtr = (char *)&frame;

    idx = 0;
    len = 5447;
    while (len > 0)
    {
        qDebug() << "len = " << len;

        bytesRecv = recvfrom(sockfd, frameHdrPtr, WINC3400_BUFFER_SIZE, 0, NULL, NULL);
        DecodeRadioFrame(&frame, &remoteJpg[idx]);

        qDebug() << "recvfrom() " << bytesRecv << " bytes received";

        /* Ignore header */
        bytesRecv -= RADIO_FRAME_HEADER_SIZE;

        idx += bytesRecv;
        len -= bytesRecv;
    }

    qDebug() << "len @ end = " << len;

    emit TransmitImageToGUI(remoteJpg, 5447);
}
