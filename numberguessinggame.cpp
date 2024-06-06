#include <bits/stdc++.h>
using namespace std;
int main() 
{
    // change the output of the random variable always the program runs
    srand(time(0));
    int minRange, maxRange;
    int randomNumber;
    string input;
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;
    // Ask the user to define the range
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Please enter the minimum value of the range: ";
    cin >> minRange;
    cout << "Please enter the maximum value of the range: ";
    cin >> maxRange;
    // Ensure the minimum range is less than the maximum range
    if (minRange >= maxRange) 
    {
        cout << "Invalid range. The minimum value must be less than the maximum value." << endl;
        return 1;
    }
    // Generate a random number within the user-defined range
    randomNumber = (int)(rand() % (maxRange - minRange + 1) + minRange);
    cout << "I have selected a number between " << minRange << " and " << maxRange << ". Can you guess it?" << endl;
    // Loop until the player guesses the number correctly
    while (!guessedCorrectly) 
    {
        cout << "Enter your guess (or type 'exit' to quit): ";
        cin >> input;
        if (input == "exit") 
        {
            cout << "You choose to exit the game. You lost!" << endl;
            break;
        }
        // Convert the input to an integer
        try {
            guess = stoi(input);
        } catch (invalid_argument&){
            cout << "Invalid input. Please enter a number or 'exit' to quit." << endl;
            continue;
        }
        attempts++;
        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    }
    return 0;
}

