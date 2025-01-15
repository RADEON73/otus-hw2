#pragma once
#include <vector>

struct IPAddress : public std::vector<int>
{
    void print() const;
};
