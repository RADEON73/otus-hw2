#include "IpList.h"
#include <iostream>
#include <algorithm>
#include <sstream>

void IPList::fill()
{
    std::string line;
    while (getline(std::cin, line)) {
        if (auto pos = line.find('\t'); pos != std::string::npos) {
            auto ipStr = line.substr(0, pos);
            push_back(parse(ipStr));
        }
    }
}

IPAddress IPList::parse(const std::string& ipStr) const
{
    IPAddress result;
    std::istringstream iss(ipStr);
    std::string segment;
    while (std::getline(iss, segment, '.'))
        result.push_back(std::stoi(segment));
    return result;
}

void IPList::reverse()
{
    std::sort(begin(), end(), std::greater<IPAddress>());
}

void IPList::print() const
{
    for (auto const& it : *this)
        it.print();
}