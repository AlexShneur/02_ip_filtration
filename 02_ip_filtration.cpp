#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

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

bool operator < (const vector<string>& lhs, const vector<string>& rhs)
{
    for (auto i = 0; i < 4; ++i)
    {
        auto lnum = stoi(lhs[i]);
        auto rnum = stoi(rhs[i]);
        if (lnum != rnum)
            return lnum < rnum;
    }
    return false;
}

void print(const vector<vector<string>>& ip_data)
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

vector<vector<string>> filter(const vector<vector<string>>& ip_pool, const int& val)
{
    vector<vector<string>> result;
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if ((*ip).at(0) == to_string(val))
            result.emplace_back(*ip);
    }
    return result;
}

vector<vector<string>> filter(const vector<vector<string>>& ip_pool, const int& val1, const int& val2)
{
    vector<vector<string>> result;
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if ((*ip).at(0) == to_string(val1) &&
            (*ip).at(1) == to_string(val2))
            result.emplace_back(*ip);
    }
    return result;
}

vector<vector<string>> filter_any(const vector<vector<string>>& ip_pool, const int& val)
{
    vector<vector<string>> result;
    for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        bool needOutput = false;
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (*ip_part == to_string(val))
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
        string line;
        vector<vector<string>> ip_pool;
        while (getline(ip_file, line))
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort
        sort(ip_pool.rbegin(), ip_pool.rend(),
            [](const vector<string>& x, const vector<string>& y)
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
