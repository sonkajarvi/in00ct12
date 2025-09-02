// g++ -O2 -std=c++17 harjoitus_1_4.cpp -o harjoitus_1_4

#include <cmath>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <string_view>

// Helper for printing averages, mainly for printing zeros instead of NaNs
static inline double avg(double a, double b)
{
    double c = a / b;
    if (std::isnan(c))
        return 0.0;
    return c;
}

void assignment_4(void)
{
    std::vector<long> e, o;     // vectors for even and odd numbers
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
            sum = std::stol(tmp.c_str());   // use sum as a temporary value
            if (sum & 1)
                o.push_back(sum);
            else
                e.push_back(sum);
        } catch (std::invalid_argument) {
            std::cerr << "NOT A NUMBER!!1\n";
        } catch (std::out_of_range) {
            std::cerr << "NUMBER TOO BIG. TRY 0\n";
        }
    } while (1);

    auto helper = [&sum](std::vector<long>& v, std::string_view title) {
        std::cout << title << ":\n";

        // Print count, sum and average
        std::cout << "  count: " << v.size() << "\n";
        sum = std::accumulate(v.cbegin(), v.cend(), 0);
        std::cout << "  sum: " << sum << "\n";
        std::cout << "  avg: " << avg(sum, v.size()) << "\n";

        // Sort numbers in ascending order and print them
        std::sort(v.begin(), v.end());
        std::cout << "  ";
        for (auto& n : v)
            std::cout << n << " ";
        std::cout << "\n";
    };

    helper(e, "even");
    helper(o, "odd");
}

#ifndef ASSIGNMENT_6
int main(void)
{
    assignment_4();
}
#endif
