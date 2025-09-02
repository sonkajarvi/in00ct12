// g++ -O2 -std=c++17 harjoitus_1_3.cpp -o harjoitus_1_3

#include <cmath>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

// Helper for printing averages, mainly for printing zeros instead of NaNs
static inline double avg(double a, double b)
{
    double c = a / b;
    if (std::isnan(c))
        return 0.0;
    return c;
}

void assignment_3(void)
{
    std::vector<long> v;        // vector of numbers
    std::string tmp;            // temporary string
    long sum;

    std::cout << "use 'q' to quit. prints a summary after\n";

    // Ask for numbers until q
    do {
        std::cout << "enter <number>: ";

        std::cin >> tmp;
        if (tmp == "q")
            break;

        // Convert string to number while handling errors
        try {
            v.push_back(std::stol(tmp.c_str()));
        } catch (std::invalid_argument) {
            std::cerr << "NOT A NUMBER!!1\n";
        } catch (std::out_of_range) {
            std::cerr << "NUMBER TOO BIG. TRY 0\n";
        }
    } while (1);

    // Sort numbers (in ascending order) and print them (in reverse)
    std::sort(v.begin(), v.end());
    for (auto it = v.crbegin(); it != v.crend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // Print count, sum and average
    std::cout << "count: " << v.size() << "\n";
    sum = std::accumulate(v.cbegin(), v.cend(), 0);
    std::cout << "sum: " << sum << "\n";
    std::cout << "avg: " << avg(sum, v.size()) << "\n";
}


#ifndef ASSIGNMENT_6
int main(void)
{
    assignment_3();
}
#endif
