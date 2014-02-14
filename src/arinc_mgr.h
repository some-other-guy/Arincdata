#ifndef ARINC_MGR_H_
#define ARINC_MGR_H_

#include <map>
#include <string>
#include <fstream>
#include <stdint.h>
#include <boost/function.hpp>

class ArincMgr
{
public:
    typedef std::map<uint8_t, boost::function<void()> > ParserContainer_t;

    ~ArincMgr();
    ArincMgr( std::string filename );

    void process();
    void load_parsers();
    void open_out_stream( std::string& filename );

private:
    ParserContainer_t _parsers;
    std::ifstream _arinc_data_stream;
    std::ofstream _arinc_data_stream_out;
};
#endif /* ARINC_MGR_H_ */
