#include "main.h"
#include "readData.h"
#include "sort.h"
#include "print.h"
#include "filter.h"

const string FILENAME = "ip_filter.tsv";

int main(int argc, char const* argv[])
{
    try
    {
        auto ip_pool = readData(FILENAME);

        // TODO reverse lexicographically sort
        sort(ip_pool);
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