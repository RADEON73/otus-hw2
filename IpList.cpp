#include "IpList.h"
#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <sstream>

void IPList::push_back(IPAddress const& value)
{
    iPList.push_back(value);
}

void IPList::pop_back()
{
    iPList.pop_back();
}

size_t IPList::size() const
{
    return iPList.size();
}

bool IPList::empty() const
{
    return iPList.empty();
}

IPAddress& IPList::operator[](size_t index)
{
    return iPList[index];
}

const IPAddress& IPList::operator[](size_t index) const
{
    return iPList[index];
}

void IPList::clear()
{
    iPList.clear();
}

std::vector<IPAddress>::iterator IPList::begin()
{
    return iPList.begin();
}

std::vector<IPAddress>::const_iterator IPList::begin() const
{
    return iPList.begin();
}

std::vector<IPAddress>::iterator IPList::end()
{
    return iPList.end();
}

std::vector<IPAddress>::const_iterator IPList::end() const
{
    return iPList.end();
}

std::vector<IPAddress>::iterator IPList::insert(std::vector<IPAddress>::const_iterator position, IPAddress value)
{
    return iPList.insert(position, value);
}

std::vector<IPAddress>::iterator IPList::erase(std::vector<IPAddress>::const_iterator position)
{
    return iPList.erase(position);
}

const IPAddress& IPList::at(const size_t pos)
{
    return iPList.at(pos);
}

void IPList::fill(std::istream& file)
{
    std::string line;
    while (getline(file, line)) {
        if (auto pos = line.find('\t'); pos != std::string::npos) {
            auto ipStr = line.substr(0, pos);
            iPList.push_back(parse(ipStr));
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

IPAddress IPList::parse(const std::string& ipStr)
{
    IPAddress result;
    std::istringstream iss(ipStr);
    std::string segment;
    for (auto i = 0; i < 4; ++i) {
        std::getline(iss, segment, '.');
        result[i] = std::stoi(segment);
    }
    return result;
}

void IPList::reverse()
{
    std::sort(iPList.begin(), iPList.end(), std::greater<IPAddress>());
}

void IPList::print() const
{
    for (auto const& it : iPList)
        it.print();
}
void IPList::print_if(std::function<bool(IPAddress&)>& condition)
{
    for (auto& ip : iPList) {
        if (condition(ip))
            ip.print();
    }
}