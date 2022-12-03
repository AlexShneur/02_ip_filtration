#include "sort.h"
#include <algorithm>

void sort(my_ip_array& ip_pool)
{
    sort(ip_pool.rbegin(), ip_pool.rend(),
        [](const array<int, N>& x, const array<int, N>& y)
        {
            return x < y;
        });
}