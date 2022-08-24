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
     std::chrono::duration<float> elapsed_time = (end - start);
     std::chrono::duration<int, std::nano> ns;
     std::chrono::duration<int, std::micro> us;
     std::chrono::duration<int, std::milli> ms;
     int yrs = (elapsed_time.count() / 31556952);
     int mos = (elapsed_time.count() / 2629746);
     int wks = (elapsed_time.count() / 604800);
     int days = (elapsed_time.count() / 86400);
     int hrs = (elapsed_time.count() / 3600);
     int min = (elapsed_time.count() / 60);
     int sec = int(elapsed_time.count()) % 60;
     std::time_t end_time = std::chrono::system_clock::to_time_t(end);

     if (tries == 0 && guess != num)
         printf("The correct number was %d!\nBetter luck next time\n", num);

     std::cout << "It took you " << elapsed_time.count() << " second(s) to finish the game!\n\n";
     std::cout << "hrs:" << hrs << "\n";
     std::cout << "min:" << min << "\n";
     std::cout << "sec:" << sec << "\n";
     std::cout << "ms:" << (std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count() % 1000) << "\n";
     std::cout << "us:" << (std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count() % 1000000) << "\n";
     std::cout << "ns:" << (std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count() % 1000000000) << "\n";

     return 0;
}
