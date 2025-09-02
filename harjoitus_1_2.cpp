// g++ -O2 -std=c++17 harjoitus_1_2.cpp -o harjoitus_1_2

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Helper for printing vectors
template <typename T>
static inline void print_vector(const std::vector<T>& v)
{
    for (const T& k : v)
        std::cout << "  " << k << "\n";
}

void assignment_2(void)
{
    std::vector<std::string> v;     // vector of names
    std::string tmp;                // temporary string

    std::cout << "use 'q' to quit. prints a summary after\n";

    // Ask for names until q
    do {
        std::cout << "enter <name>: ";

        std::cin >> tmp;
        if (tmp == "q")
            break;

        v.push_back(std::move(tmp));
    } while (1);

    // Sort and print names
    std::sort(v.begin(), v.end());
    std::cout << "total: " << v.size() << "\n";
    print_vector(v);

    // Remove the first and last element
    while (!v.empty()) {
        // Pop the first element only if vector has two or more elements
        if (v.size() > 1)
            v.erase(v.cbegin());
        v.pop_back();

        std::cout << "total: " << v.size() << "\n";
        print_vector(v);
    };
}

#ifndef ASSIGNMENT_6
int main(void)
{
    assignment_2();
}
#endif
