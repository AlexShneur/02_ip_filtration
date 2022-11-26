#include "filter.h"

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