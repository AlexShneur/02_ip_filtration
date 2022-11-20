#include "readData.h"
#include "split.h"
#include <string>
#include <fstream>

constexpr int POSSIBLE_LINE_COUNT = 1000;       //default line count in the file ip_filter.tsv. May be any positive number

my_ip_array readData(const string& filename)
{
    ifstream ip_file(filename);
    my_ip_array ip_pool;
    ip_pool.reserve(POSSIBLE_LINE_COUNT);

    string line;
    while (getline(ip_file, line))
    {
        auto v = split(line, '\t');
        auto ip = (split(v.at(0), '.'));

        array<int, N> ip_arr;
        for (auto i = 0; i < N; i++)
        {
            ip_arr[i] = stoi(ip.at(i));
        }
        ip_pool.emplace_back(move(ip_arr));
    }
    return ip_pool;
}