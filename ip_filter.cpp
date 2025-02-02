#include <iostream>
#include "IpList.h"

int main()
{
    std::array<int, 1> test;
    try {
        IPList ipList;
        ipList.fill(); //Для локального запуска вне тестов с тестовыми данными замените эту строку на "ipList.read("ip_filter.tsv");"
        ipList.reverse();
        ipList.print();

        auto firstByte1Filter = [](IPAddress& ip) {
            return ip.at(0) == 1;
            };
        ipList.print_if_cpp20(firstByte1Filter);

        auto firstByte46SecondByte70Filter = [](IPAddress& ip) {
            return ip.at(0) == 46 && ip.at(1) == 70;
            };
        ipList.print_if_cpp20(firstByte46SecondByte70Filter);

        auto any46Filter = [](IPAddress& ip) {
            return std::find(ip.begin(), ip.end(), 46) != ip.end();
            };
        ipList.print_if_cpp20(any46Filter);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}