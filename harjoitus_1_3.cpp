// g++ -O2 -std=c++17 harjoitus_1_3.cpp -o harjoitus_1_3

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
static inline void dump(const std::vector<T>& v)
{
    for (const T& k : v)
        std::cout << k << "\n";
}

int main(int argc, char **argv)
{
    std::vector<unsigned long> v;
    unsigned long sum;

    for (int i = 1; i < argc; i++)
        v.push_back(std::strtoul(argv[i], nullptr, 10));

    std::sort(v.begin(), v.end());
    dump(v);

    std::cout << "count: " << v.size() << "\n";

    sum = std::accumulate(v.cbegin(), v.cend(), 0);
    std::cout << "sum: " << sum << "\n";
    std::cout << "avg: " << (double)sum / v.size() << "\n";
}
