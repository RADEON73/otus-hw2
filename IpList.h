#pragma once
#include <vector>
#include <string>
#include "IpAddress.h"


struct IPList : public std::vector<IPAddress>
{
    void fill();
    IPAddress parse(const std::string& ipStr) const;
    void reverse();
    void print() const;
};