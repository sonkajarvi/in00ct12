// g++ -O2 -std=c++17 harjoitus_1_1.cpp -o harjoitus_1_1

#include <iostream>

void assignment_1(void)
{
    unsigned char i = 0;

    for (;;)
        std::cout << static_cast<int>(i++) << "\n";
}

// Do not include main() when built as part of assignment 6
#ifndef ASSIGNMENT_6
int main(void)
{
    assignment_1();
}
#endif
