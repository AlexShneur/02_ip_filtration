#include "print.h"

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