#include <iostream>
#include "arinc_mgr.h"
#include "arinc_common.h"
#include "data_hndlrs/data_hdlr.h"

ArincMgr::~ArincMgr(){}
ArincMgr::ArincMgr( std::string filename )
{
    if( !filename.empty() )
        _arinc_data_stream.open( filename.c_str(), std::ios::binary | std::ios::in );
    open_out_stream( filename );
    process();
}

void ArincMgr::process()
{
    std::cout << "Processing ";
    while( _arinc_data_stream.good() )
    {
        arinc::packet_t packet;
        _arinc_data_stream.read( packet.raw, sizeof( arinc::packet_t ));
        if( _arinc_data_stream.good() )
        {
            if( _arinc_data_stream_out.good() )
                _arinc_data_stream_out << std::dec << packet.arinc.time_sec << "," << packet.arinc.bus << ","
                    << packet.arinc.io << "," << std::oct << (uint32_t)DataHdlr::extract_label( packet.arinc.data ) << std::endl;
        }
    }
    _arinc_data_stream.close();
    _arinc_data_stream_out.close();
}

void ArincMgr::load_parsers()
{

}

void ArincMgr::open_out_stream( std::string& filename )
{
    std::string out_filename = filename.substr( 0, filename.find_first_of( "." ));
    out_filename += ".csv";
    _arinc_data_stream_out.open( out_filename.c_str(), std::ios::out );
    if( _arinc_data_stream_out.good() )
        _arinc_data_stream_out << "Timestamp,Bus,I/O,Label" << std::endl;
}
