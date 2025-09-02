// g++ -O2 -std=c++17 harjoitus_1_4.cpp -o harjoitus_1_4

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

static inline void dump(const std::vector<unsigned long>& v)
{
    for (const unsigned long& k : v)
        std::cout << k << "\n";
}

static inline void dump2(std::vector<unsigned long>& v)
{
    unsigned long sum;

    std::sort(v.begin(), v.end());

    dump(v);
    std::cout << "count: " << v.size() << "\n";

    sum = std::accumulate(v.cbegin(), v.cend(), 0);
    std::cout << "sum: " << sum << "\n";
    std::cout << "avg: " << (double)sum / v.size() << "\n";
}

int main(int argc, char **argv)
{
    std::vector<unsigned long> odd, even;
    unsigned long tmp;

    for (int i = 1; i < argc; i++) {
        tmp = std::strtoul(argv[i], nullptr, 10);

        if (tmp & 1)
            odd.push_back(tmp);
        else
            even.push_back(tmp);
    }

    dump2(even);
    dump2(odd);
}
