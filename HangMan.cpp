#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to check if the guessed letter is in the word
bool isLetterInWord(char letter, const string& word) {
    return word.find(letter) != string::npos;
}

// Function to display the current state of the word
void displayWord(const string& word, const vector<bool>& guessedLetters) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessedLetters[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the player has guessed all letters in the word
bool isWordGuessed(const vector<bool>& guessedLetters) {
    for (bool letterGuessed : guessedLetters) {
        if (!letterGuessed) {
            return false;  // If any letter is not guessed, return false
        }
    }
    return true;  // All letters are guessed
}

int main() {
    // Array of words for the game
    const string words[] = {"programming", "hangman", "cplusplus", "developer", "challenge","varshitha","google","microsoft","fever","game","crocodile","diwali","philosophy"};
    const int numWords = sizeof(words) / sizeof(words[0]);

    // Randomly select a word from the array
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % numWords;
    string selectedWord = words[randomIndex];

    // Vector to track guessed letters
    vector<bool> guessedLetters(selectedWord.length(), false);

    // Game loop
    while (!isWordGuessed(guessedLetters)) {
        // Display current state of the word
        displayWord(selectedWord, guessedLetters);

        // Get a letter guess from the player
        cout << "Enter a letter guess: ";
        char guess;
        cin >> guess;

        // Check if the guessed letter is in the word
        if (isLetterInWord(guess, selectedWord)) {
            cout << "Correct guess!" << endl;

            // Update guessedLetters vector
            for (size_t i = 0; i < selectedWord.length(); ++i) {
                if (selectedWord[i] == guess) {
                    guessedLetters[i] = true;
                }
            }
        } else {
            cout << "Incorrect guess. Try again!" << endl;
        }

        cout << "---------------------" << endl;
    }

    // Display the final result
    cout << "Congratulations! You guessed the word: " << selectedWord << endl;

    return 0;
}
