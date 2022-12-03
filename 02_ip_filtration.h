#pragma once
#include <string>
#include <vector>
#include <array>

using namespace std;

constexpr int N = 4;                        //bytes count in the ip-address
using my_ip_array = vector<array<int, N>>;

vector<string> split(const string& str, char d);

my_ip_array filter(const my_ip_array& ip_pool, const int& val);
my_ip_array filter(const my_ip_array& ip_pool, const int& val1, const int& val2);
my_ip_array filter_any(const my_ip_array& ip_pool, const int& val);