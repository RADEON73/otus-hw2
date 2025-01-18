#pragma once
#include <vector>
#include <string>
#include <functional>
#include "IpAddress.h"

struct IPList : public std::vector<IPAddress>
{
    void fill(std::istream& file = std::cin);
    void read(const std::string& filePath);
    IPAddress parse(const std::string& ipStr) const;
    void reverse();
    void print() const;
    void print_if(const std::function<bool(const IPAddress&)>& condition) const;
    //Template parameters should be preferred to "std::function" when configuring behavior at compile time

    template <typename Criterion>
    void print_if_cpp17(Criterion criterion) const
    {
        static_assert(std::is_invocable_r_v<bool, Criterion, IPAddress const&>);
        for (auto const& ip : *this) {
            if (criterion(ip))
                ip.print();
        }
    }

    template <std::predicate<IPAddress const&> Criterion>
    void print_if_cpp20(Criterion criterion) const {
        for (auto const& ip : *this) {
            if (criterion(ip))
                ip.print();
        }
    }
};