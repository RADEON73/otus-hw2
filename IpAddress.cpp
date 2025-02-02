#include "IpAddress.h"
#include <iostream>
#include <stdexcept>

IPAddress::IPAddress() : iPAddress({ 0, 0, 0, 0 })
{
}

IPAddress::IPAddress(int a, int b, int c, int d) : iPAddress({ a, b, c, d })
{
}

int IPAddress::at(int index) const
{
    if (index >= 0 && index < 4)
        return iPAddress[index];
    else
        throw std::out_of_range("Index out of range");
}

int IPAddress::operator[](int index) const
{
    if (index >= 0 && index < 4)
        return iPAddress[index];
    else
        throw std::out_of_range("Index out of range");
}

int& IPAddress::operator[](int index)
{
    if (index >= 0 && index < 4)
        return iPAddress[index];
    else
        throw std::out_of_range("Index out of range");
}

std::array<int, 4>::iterator IPAddress::begin()
{
    return iPAddress.begin();
}

std::array<int, 4>::iterator IPAddress::end()
{
    return iPAddress.end();
}

std::array<int, 4>::const_iterator IPAddress::cbegin() const
{
    return iPAddress.begin();
}

std::array<int, 4>::const_iterator IPAddress::cend() const
{
    return iPAddress.end();
}

void IPAddress::print() const
{
    std::cout << iPAddress[0] << "." << iPAddress[1] << "." << iPAddress[2] << "." << iPAddress[3] << std::endl;
}