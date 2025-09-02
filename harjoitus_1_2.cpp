// g++ -O2 -std=c++17 harjoitus_1_2.cpp -o harjoitus_1_2

#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

template <typename T>
static inline void dump(const std::vector<T>& v)
{
    for (const T& k : v)
        std::cout << k << "\n";
}

int main(int argc, char **argv)
{
    std::vector<std::string_view> v;

    for (int i = 1; i < argc; i++)
        v.push_back(argv[i]);

    std::sort(v.begin(), v.end());
    dump(v);

    std::cout << "total: " << v.size() << "\n";

    while (!v.empty()) {
        if (v.size() == 1) {
            v.pop_back();
            break;
        }

        v.erase(v.cbegin());
        v.pop_back();

        std::cout << "\n";
        dump(v);
    }
}
