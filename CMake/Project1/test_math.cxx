#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#include "Config.h"
//#include "utility.h"
#ifdef UTIL_ON
#include "utility.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << TestMath_VERSION_MAJOR << "."
                << TestMath_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    
    const double inputValue = std::stod(argv[1]);

    // which square root function should we use?
#ifdef UTIL_ON
    const double outputValue = mysqrt(inputValue);
#else
    const double outputValue = sqrt(inputValue);
#endif

    
    std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
    return 0;
}