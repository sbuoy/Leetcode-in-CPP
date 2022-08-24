#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;


int main() {
    int num = 0;
    int guess = 0;
    int number_of_digits = 0;
    int attempts = 0;
    int tries = 5;
    srand(time(0));
    long max = rand() % (rand()) + 1;
    num = rand() % (max) + 1;
    int x = num;
    auto start = std::chrono::system_clock::now();
    double time_diff;
    std::vector<int> guesses_array;

    for (; x != 0; x /= 10, number_of_digits++);

    std::cout << "Guess the Number!\n\n";
    printf("The number contains %d digits\n\n", number_of_digits);
    if (number_of_digits > 2)
        tries = number_of_digits * 5;

    do {
        printf("Enter a number between 1 and %d (%d attempts left): ", max, tries);
        std::cin >> guess;

        if (std::find(guesses_array.begin(), guesses_array.end(), guess) != guesses_array.end()) {
            printf("You've already guessed: %d\n\n", guess);
        }
        else {
            tries--;
            attempts++;
            guesses_array.push_back(guess);
            if (guess > num)
                std::cout << "Your guess was too high!\n\n";
            else if (guess < num)
                std::cout << "Your guess was too low!\n\n";
            else {
                std::cout << "\n\nYour guess was correct!\n";
                printf("Tries: %d\n\n", attempts);
            }
        }
     } while (guess != num && tries > 0);

     const auto end = std::chrono::system_clock::now();
     const auto duration = (end - start);
     std::chrono::duration<double> elapsed_time = (end - start);
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);

     if (tries == 0 && guess != num)
         printf("The correct number was %d!\nBetter luck next time\n", num);

     std::cout << "It took you " << elapsed_time.count() << " second(s) to finish the game!\n\n";

     return 0;
}
