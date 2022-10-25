#include "02_ip_filtration.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cstdlib>

constexpr int POSSIBLE_LINE_COUNT = 1000;       //default line count in the file ip_filter.tsv. May be any positive number

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vector<string> split(const string& str, char d)
{
    vector<string> r;

    size_t start = 0;
    auto stop = str.find_first_of(d);
    while (stop != string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool operator < (const array<int, N>& lhs, const array<int, N>& rhs)
{
    for (auto i = 0; i < N; ++i)
    {
        auto lnum = lhs[i];
        auto rnum = rhs[i];
        if (lnum != rnum)
            return lnum < rnum;
    }
    return false;
}

void print(const my_ip_array& ip_data)
{
    for (auto ip = ip_data.cbegin(); ip != ip_data.cend(); ++ip)
    {
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                cout << ".";
            }
            cout << *ip_part;
        }
        cout << endl;
    }
}

my_ip_array filter(const my_ip_array& ip_pool, const int& val)
{
    my_ip_array result;
    result.reserve(ip_pool.size());
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if ((*ip).at(0) == val)
            result.emplace_back(*ip);
    }
    return result;
}

my_ip_array filter(const my_ip_array& ip_pool, const int& val1, const int& val2)
{
    my_ip_array result;
    result.reserve(ip_pool.size());
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if ((*ip).at(0) == val1 &&
            (*ip).at(1) == val2)
            result.emplace_back(*ip);
    }
    return result;
}

my_ip_array filter_any(const my_ip_array& ip_pool, const int& val)
{
    my_ip_array result;
    result.reserve(ip_pool.size());
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        bool needOutput = false;
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (*ip_part == val)
            {
                needOutput = true;
                break;
            }
        }
        if (needOutput)
            result.emplace_back(*ip);
    }
    return result;
}

int main(int argc, char const* argv[])
{
    try
    {
        ifstream ip_file("ip_filter.tsv");
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

        // TODO reverse lexicographically sort
        sort(ip_pool.rbegin(), ip_pool.rend(),
            [](const array<int, N>& x, const array<int, N>& y)
            {
                return x < y;
            });

        print(ip_pool);

        // TODO filter by first byte and output
        auto ip = filter(ip_pool, 1);
        print(ip);

        // TODO filter by first and second bytes and output
        ip = filter(ip_pool, 46, 70);
        print(ip);

        // TODO filter by any byte and output
        ip = filter_any(ip_pool, 46);
        print(ip);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
