#include <iostream>
#include "IpList.h"

int main(int argc, char const* argv[])
{
    try {
        IPList ipList;
        ipList.fill(); //��� ���������� ������� ��� ������ � ��������� ������� �������� ��� ������ �� "ipList.read("ip_filter.tsv");"
        ipList.reverse();
        ipList.print();

        auto firstByte1Filter = [](const IPAddress& ip) {
            return ip.at(0) == 1;
            };
        ipList.print_if_cpp20(firstByte1Filter);

        auto firstByte46SecondByte70Filter = [](const IPAddress& ip) {
            return ip.at(0) == 46 && ip.at(1) == 70;
            };
        ipList.print_if_cpp20(firstByte46SecondByte70Filter);

        auto any46Filter = [](const IPAddress& ip) {
            return std::find(ip.begin(), ip.end(), 46) != ip.end();
            };
        ipList.print_if_cpp20(any46Filter);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}