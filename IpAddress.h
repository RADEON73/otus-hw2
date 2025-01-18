#pragma once
#include <vector>
#include <initializer_list>

struct IPAddress : public std::vector<int>
{
    void print() const;
};
