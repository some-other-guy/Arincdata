#ifndef DATA_HDLR_H_
#define DATA_HDLR_H_

#include <stdint.h>

class DataHdlr
{
public:
    static uint8_t extract_label( uint32_t data );
    static double extract_double( uint32_t data, uint32_t start, uint32_t stop, double scale, uint32_t sign );
};
#endif /* DATA_HDLR_H_ */
