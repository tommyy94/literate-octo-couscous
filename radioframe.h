#ifndef RADIOFRAME_H
#define RADIOFRAME_H

#include <stdint.h>

#define WINC3400_BUFFER_SIZE      (1400)
#define RADIO_FRAME_HEADER_SIZE   (8)
#define RADIO_FRAME_PAYLOAD_SIZE  (WINC3400_BUFFER_SIZE - RADIO_FRAME_HEADER_SIZE)


typedef struct
{
    /* Header */
    uint32_t  length;
    uint8_t   sequenceId;
    uint8_t   uniqueId;
    uint8_t   padding;

    /* Payload */
    char      data[RADIO_FRAME_PAYLOAD_SIZE];
} RadioFrame_t;


void BuildRadioFrame(
    RadioFrame_t  *frame,
    char          *data,
    uint32_t       len,
    uint8_t        sequenceId);

void DecodeRadioFrame(
    RadioFrame_t  *frame,
    char          *data);


#endif /* RADIOFRAME_H */
