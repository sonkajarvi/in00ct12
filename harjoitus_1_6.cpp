// g++ -O2 -std=c++17 -DASSIGNMENT_6 harjoitus_1_{1,2,3,4,5,6}.cpp -o harjoitus_1_6

#include <unistd.h>
#include <sys/wait.h>

#include <array>
#include <functional>
#include <iostream>

// Forward declare assignments
void assignment_1(void);
void assignment_2(void);
void assignment_3(void);
void assignment_4(void);
void assignment_5(void);
void assignment_6(void);

static const std::array<std::function<void(void)>, 6> ASSIGNMENTS = {
    assignment_1,
    assignment_2,
    assignment_3,
    assignment_4,
    assignment_5,
    assignment_6,
};

// Helper for enabling and disabling SIGINTs
static inline void sigint(bool on)
{
    if (on) {
        signal(SIGINT, [](int s) {
            std::cout << "\n";
            std::cout << "<<< process(" << getpid() << ") killed >>>\n";
            std::exit(0);
        });
    } else {
        signal(SIGINT, [](int s){
            // Do nothing
        });
    }
}

void assignment_6(void)
{
    pid_t pid;
    unsigned int input;

    std::cout << "<<< process(" << getpid() << ") started >>>\n";

    std::cout << "use ctrl+c to stop parent or child program.\n";
    std::cout << "1: numbers forever\n";
    std::cout << "2: names\n";
    std::cout << "3: numbers\n";
    std::cout << "4: even and odd numbers\n";
    std::cout << "5: names and ages\n";
    std::cout << "6: this\n";

    // Loop until ctrl+c
    do {
        // Enable SIGINT for both (child and parent)
        sigint(true);

        std::cout << "enter <number> (1-6): ";
        std::cin >> input;

        if (input < 1 || input > 6) {
            std::cout << "INVALID NUMBER!!1\n";
            continue;
        }

        // Create the child process
        if ((pid = fork()) == -1) {
            std::cout << "FAILED TO FORK. TRY SPOON\n";
            break;
        }

        if (pid > 0) {
            // Disable SIGINT for parent process
            sigint(false);

            // Wait for child process
            wait(nullptr);
        } else {
            if (input != 6) // NOTE: added after submitting
                std::cout << "<<< process(" << getpid() << ") started >>>\n";

            // Call the assignment function
            ASSIGNMENTS[input - 1]();

            // Exit child process
            std::cout << "<<< process(" << getpid() << ") killed >>>\n";
            std::exit(0);
        }
    } while (1);
}

int main(void)
{
    assignment_6();
}
