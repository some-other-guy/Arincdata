#include <iostream>
#include "arinc_mgr.h"

int main( int argc, char** argv )
{
    std::string filename;
    if( 2 == argc )
    {
        filename = argv[1];
    }
    else
    {
        std::cout << "Data file to process: ";
        std::cout.flush();
        std::cin >> filename;
    }
    ArincMgr arinc_mgr( filename );
    return 0;
}
