#ifndef RADIOPACKET_H
#define RADIOPACKET_H

#include <stdint.h>

#define WINC3400_BUFFER_SIZE      (1400)
#define RADIOPACKET_HEADER_SIZE   (8)
#define RADIOPACKET_PAYLOAD_SIZE  (WINC3400_BUFFER_SIZE - RADIOPACKET_HEADER_SIZE)


typedef struct
{
    /* Header */
    uint32_t  length;
    uint8_t   sequenceId;
    uint8_t   padding[2];

    /* Payload */
    char      data[RADIOPACKET_PAYLOAD_SIZE];
} RadioPacket_t;


void BuildRadioPacket(
    RadioPacket_t  *frame,
    char          *data,
    uint32_t       len,
    uint8_t        sequenceId);

void DecodeRadioPacket(
    RadioPacket_t  *frame,
    char          *data);


#endif /* RADIOPACKET_H */
