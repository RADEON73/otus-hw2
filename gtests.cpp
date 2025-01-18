#include "gtest/gtest.h"
#include <algorithm>
#include "IpList.h"

class IPListTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		ipList.read("ip_filter.tsv");
		ipList.reverse();
	}

	IPList ipList;
};

TEST_F(IPListTest, reverse_Test)
{
	// 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
    // ...
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

	ASSERT_GE(ipList.size(), 2);
	ASSERT_TRUE(std::is_sorted(ipList.begin(), ipList.end(), std::greater<IPAddress>()));
}

TEST_F(IPListTest, print_firstByte1Filter_Test)
{
	auto firstByte1Filter = [](const IPAddress& ip) {
		return ip.at(0) == 1;
		};
	testing::internal::CaptureStdout();

	ipList.print_if_cpp20(firstByte1Filter);
	auto outputStrIPs = testing::internal::GetCapturedStdout();

	std::string expectedStrIPs =
		"1.231.69.33\n"
		"1.87.203.225\n"
		"1.70.44.170\n"
		"1.29.168.152\n"
		"1.1.234.8\n";

	EXPECT_EQ(outputStrIPs, expectedStrIPs);
}

TEST_F(IPListTest, print_firstByte46SecondByte70Filter_Test)
{
	auto firstByte46SecondByte70Filter = [](const IPAddress& ip) {
		return ip.at(0) == 46 && ip.at(1) == 70;
		};
	testing::internal::CaptureStdout();

	ipList.print_if_cpp20(firstByte46SecondByte70Filter);
	auto outputStrIPs = testing::internal::GetCapturedStdout();

	std::string expectedStrIPs =
		"46.70.225.39\n"
		"46.70.147.26\n"
		"46.70.113.73\n"
		"46.70.29.76\n";

	EXPECT_EQ(outputStrIPs, expectedStrIPs);
}

TEST_F(IPListTest, print_any46Filter_Test)
{
	auto any46Filter = [](const IPAddress& ip) {
		return std::find(ip.begin(), ip.end(), 46) != ip.end();
		};
	testing::internal::CaptureStdout();

	ipList.print_if_cpp20(any46Filter);
	auto outputStrIPs = testing::internal::GetCapturedStdout();

	std::string expectedStrIPs =
		"186.204.34.46\n"
		"186.46.222.194\n"
		"185.46.87.231\n"
		"185.46.86.132\n"
		"185.46.86.131\n"
		"185.46.86.131\n"
		"185.46.86.22\n"
		"185.46.85.204\n"
		"185.46.85.78\n"
		"68.46.218.208\n"
		"46.251.197.23\n"
		"46.223.254.56\n"
		"46.223.254.56\n"
		"46.182.19.219\n"
		"46.161.63.66\n"
		"46.161.61.51\n"
		"46.161.60.92\n"
		"46.161.60.35\n"
		"46.161.58.202\n"
		"46.161.56.241\n"
		"46.161.56.203\n"
		"46.161.56.174\n"
		"46.161.56.106\n"
		"46.161.56.106\n"
		"46.101.163.119\n"
		"46.101.127.145\n"
		"46.70.225.39\n"
		"46.70.147.26\n"
		"46.70.113.73\n"
		"46.70.29.76\n"
		"46.55.46.98\n"
		"46.49.43.85\n"
		"39.46.86.85\n"
		"5.189.203.46\n";

	EXPECT_EQ(outputStrIPs, expectedStrIPs);
}