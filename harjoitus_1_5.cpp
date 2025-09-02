// g++ -O2 -std=c++17 harjoitus_1_5.cpp -o harjoitus_1_5

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

static constexpr unsigned int CURRENT_YEAR = 2025;
static constexpr unsigned int AGE_LIMIT = 130;

struct Person {
    std::string name;
    unsigned int year;
};

static inline double avg(double a, double b)
{
    double c = a / b;
    if (std::isnan(c))
        return 0.0;
    return c;
}

static inline void dump(const std::vector<struct Person>& v)
{
    unsigned int kid_cnt = 0, kid_sum = 0;
    unsigned int adult_cnt = 0, adult_sum = 0;
    unsigned int old_cnt = 0, old_sum = 0;
    unsigned int age;

    for (const struct Person& p : v) {
        age = CURRENT_YEAR - p.year;
        if (age < 18) {
            kid_cnt++;
            kid_sum += age;
        } else if (age > 65) {
            old_cnt++;
            old_sum += age;
        } else {
            adult_cnt++;
            adult_sum += age;
        }
    }

    std::cout << "stats:\n";
    std::cout << "    <18 count : " << kid_cnt << "\n";
    std::cout << "      <18 avg : " << avg(kid_sum, kid_cnt) << "\n";
    std::cout << "  18-65 count : " << adult_cnt << "\n";
    std::cout << "    18-65 avg : " << avg(adult_sum, adult_cnt) << "\n";
    std::cout << "    >65 count : " << old_cnt << "\n";
    std::cout << "      >65 avg : " << avg(old_sum, old_cnt) << "\n";
    std::cout << "    total avg : " << avg((kid_sum + adult_sum + old_sum), v.size()) << "\n";
}

int main(void)
{
    std::vector<struct Person> v;
    struct Person tmp;

    std::cout << "use 'q' for quit\n";

    do {
        std::cout << "<name> <year>: ";

        std::cin >> tmp.name;
        if (tmp.name == "q")
            break;

        std::cin >> tmp.year;
        if (tmp.year > CURRENT_YEAR) {
            std::cout << "THAT'S IN THE FUTURE. try again\n";
            continue;
        } else if ((CURRENT_YEAR - tmp.year) > AGE_LIMIT) {
            std::cout << "TOO OLD. try again\n";
            continue;
        }

        v.push_back(tmp);
        std::cout << "added person '" << tmp.name << "', born " << tmp.year << "\n";
        dump(v);
    } while (1);

    for (const struct Person& p : v)
        std::cout << "'" << p.name << "', born " << p.year << "\n";
}
