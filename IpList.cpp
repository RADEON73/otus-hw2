#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "IpList.h"

void IPList::fill(std::istream& file)
{
    std::string line;
    while (getline(file, line)) {
        if (auto pos = line.find('\t'); pos != std::string::npos) {
            auto ipStr = line.substr(0, pos);
            push_back(parse(ipStr));
        }
    }
}

void IPList::read(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file.is_open()) {
        fill(file);
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
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
void IPList::print_if(const std::function<bool(const IPAddress&)>& condition) const
{
    for (const auto& ip : *this) {
        if (condition(ip))
            ip.print();
    }
}
