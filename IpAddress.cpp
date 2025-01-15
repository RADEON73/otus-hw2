#include <iostream>
#include "IpAddress.h"

void IPAddress::print() const
{
    for (auto i = cbegin(); i != cend(); ++i) {
        if (i != cbegin())
            std::cout << '.';
        std::cout << *i;
    }
    std::cout << std::endl;
}