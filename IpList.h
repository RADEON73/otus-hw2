#pragma once
#include <vector>
#include <string>
#include <functional>
#include "IpAddress.h"
#include <type_traits>
#include <iostream>
#include <concepts>

class IPList
{
private:
    std::vector<IPAddress> iPList;

public:
    // Метод для добавления последнего элемента вектора
    void push_back(IPAddress const& value);

    // Метод для удаления последнего элемента вектора
    void pop_back();

    // Метод для получения размера вектора
    size_t size() const;

    // Метод для проверки, пуст ли вектор
    bool empty() const;

    // Метод для доступа к элементу по индексу
    IPAddress& operator[](size_t index);

    // Константная версия метода для доступа к элементу по индексу
    const IPAddress& operator[](size_t index) const;

    // Метод для очистки вектора
    void clear();

    // Метод для получения итератора на начало вектора
    std::vector<IPAddress>::iterator begin();

    // Метод для получения константного итератора на начало вектора
    std::vector<IPAddress>::const_iterator begin() const;

    // Метод для получения итератора на конец вектора
    std::vector<IPAddress>::iterator end();

    // Метод для получения константного итератора на конец вектора
    std::vector<IPAddress>::const_iterator end() const;

    // Метод для вставки элемента в произвольное место вектора
    std::vector<IPAddress>::iterator insert(std::vector<IPAddress>::const_iterator position, IPAddress value);

    // Метод для удаления элемента из произвольного места вектора
    std::vector<IPAddress>::iterator erase(std::vector<IPAddress>::const_iterator position);

    const IPAddress& at(const size_t pos);

    void fill(std::istream& file = std::cin);
    void read(const std::string& filePath);
    IPAddress parse(const std::string& ipStr);
    void reverse();
    void print() const;

    void print_if(std::function<bool(IPAddress&)>& condition);
    //Template parameters should be preferred to "std::function" when configuring behavior at compile time

    template <typename Criterion>
    void print_if_cpp17(Criterion criterion)
    {
        static_assert(std::is_invocable_r_v<bool, Criterion, IPAddress&>);
        for (auto& ip : iPList) {
            if (criterion(ip))
                ip.print();
        }
    }

    template <std::predicate<IPAddress&> Criterion>
    void print_if_cpp20(Criterion criterion)
    {
        for (auto& ip : iPList) {
            if (criterion(ip))
                ip.print();
        }
    }
};