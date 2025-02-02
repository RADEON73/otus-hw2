#pragma once
#include <array>
#include <compare>

class IPAddress
{
private:
    std::array<int, 4> iPAddress;

public:
    // Конструктор по умолчанию
    IPAddress();

    // Конструктор для инициализации IP-адреса
    IPAddress(int a, int b, int c, int d);

    // Геттеры для получения значений
    int at(int index) const;

    // Оператор индексации для доступа к элементам массива
    int operator[](int index) const;
    int& operator[](int index);

    // Оператор для сравнения IP-адресов
    std::strong_ordering operator<=>(const IPAddress& other) const = default;

    // Методы begin() и end(), которые позволяют работать с итераторами
    std::array<int, 4>::iterator begin();
    std::array<int, 4>::iterator end();
    std::array<int, 4>::const_iterator cbegin() const;
    std::array<int, 4>::const_iterator cend() const;

    // Метод для вывода IP-адреса
    void print() const;
};
