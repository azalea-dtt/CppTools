#include <iostream>
#include "constant.h"

int main()
{
    int radius {50};
    double C = 2.0 * radius * constants::pi;
    std::cout << "The circumfence is: " << C << std::endl;
    return 0;
}