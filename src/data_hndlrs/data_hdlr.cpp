#include "data_hdlr.h"

uint8_t DataHdlr::extract_label( uint32_t data )
{
    return ( data & 0xFF );
}

double DataHdlr::extract_double( uint32_t data, uint32_t start, uint32_t stop, double scale, uint32_t sign )
{

}
