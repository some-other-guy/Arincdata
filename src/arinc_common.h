#ifndef ARINC_COMMON_H_
#define ARINC_COMMON_H_

namespace arinc
{

    struct arinc_packet_t
    {
        uint32_t bus       : 4;
        uint32_t notbus    : 4;
        uint32_t io        : 8;
        uint32_t time_ms   : 16;
        uint32_t time_sec  : 32;
        uint32_t data      : 32;
        uint32_t pad       : 24;
        uint32_t chksum    : 8;
    };

    union packet_t
    {
        char raw[sizeof( arinc_packet_t )];
        arinc_packet_t arinc;
    };
}
#endif /* ARINC_COMMON_H_ */
