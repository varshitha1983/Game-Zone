#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set up the game
    const int minNumber = 1;
    const int maxNumber = 100;
    const int targetNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've selected a number between " << minNumber << " and " << maxNumber << ". Can you guess it?" << endl;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        attempts++;

        if (guess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }

    } while (guess != targetNumber);

    return 0;
}

