// g++ -O2 -std=c++17 harjoitus_1_5.cpp -o harjoitus_1_5

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

static constexpr unsigned int CURRENT_YEAR = 2025;
static constexpr unsigned int AGE_MAX = 130;

struct Person {
    std::string name;
    unsigned int year;
};

// Helper for printing averages, mainly for printing zeros instead of NaNs
static inline double avg(double a, double b)
{
    double c = a / b;
    if (std::isnan(c))
        return 0.0;
    return c;
}

// Helper for printing stats of people
static inline void print_stats(const std::vector<struct Person>& v)
{
    unsigned int kid_cnt = 0, kid_sum = 0;
    unsigned int adult_cnt = 0, adult_sum = 0;
    unsigned int old_cnt = 0, old_sum = 0;
    unsigned int tmp;

    for (const struct Person& p : v) {
        tmp = CURRENT_YEAR - p.year;
        if (tmp < 18) {
            kid_cnt++;
            kid_sum += tmp;
        } else if (tmp > 65) {
            old_cnt++;
            old_sum += tmp;
        } else {
            adult_cnt++;
            adult_sum += tmp;
        }
    }

    std::cout << "stats:\n";
    std::cout << "    count <18 : " << kid_cnt << "\n";
    std::cout << "  avg age <18 : " << avg(kid_sum, kid_cnt) << "\n";
    std::cout << "  count 18-65 : " << adult_cnt << "\n";
    std::cout << "avg age 18-65 : " << avg(adult_sum, adult_cnt) << "\n";
    std::cout << "    count >65 : " << old_cnt << "\n";
    std::cout << "  avg age >65 : " << avg(old_sum, old_cnt) << "\n";
    std::cout << "    total avg : " << avg((kid_sum + adult_sum + old_sum), v.size()) << "\n";
}

void assignment_5(void)
{
    std::vector<struct Person> v;       // vector of people
    struct Person tmp;                  // temporary person
    std::string tmp2;

    std::cout << "use 'q' to quit. prints a summary after\n";

    // Ask for names and birthdays until q
    do {
        std::cout << "enter <name> <year>: ";

        std::cin >> tmp.name;
        if (tmp.name == "q")
            break;

        std::cin >> tmp2;

        // Convert string to number while handling errors
        try {
            tmp.year = std::stol(tmp2.c_str());
        } catch (std::invalid_argument) {
            std::cerr << "NOT A NUMBER!!1\n";
            continue;
        } catch (std::out_of_range) {
            std::cerr << "NUMBER TOO BIG. TRY " << CURRENT_YEAR << "\n";
            continue;
        }

        // Handle some invalid values for years
        if (tmp.year > CURRENT_YEAR) {
            std::cout << "THAT'S IN THE FUTURE!!1\n";
            continue;
        } else if ((CURRENT_YEAR - tmp.year) > AGE_MAX) {
            std::cout << "TOO OLD. MUST BE ALIVE\n";
            continue;
        }

        std::cout << "added person '" << tmp.name << "', born " << tmp.year << "\n";
        v.push_back(std::move(tmp));
        print_stats(v);
    } while (1);

    for (const struct Person& p : v)
        std::cout << "'" << p.name << "', born " << p.year << "\n";
}

#ifndef ASSIGNMENT_6
int main(void)
{
    assignment_5();
}
#endif
