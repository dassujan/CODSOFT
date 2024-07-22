#include <iostream>     // Includes the standard input-output stream library
#include <cstdlib>      // Includes the C standard library (for rand() and srand())
#include <ctime>        // Includes the C time library (for time())
#include <string>       // Includes the C++ string library
using namespace std;    // Uses the standard namespace to avoid prefixing std::

int main()
{
    // Initialize random seed using the current time to ensure different random numbers each run
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1; // rand() % 100 will generate a number between 0 and 99. Adding 1 will make it between 1 and 100
    int userGuess = 0;                   // Variable to store the user's guess

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;
    cout << "Hint: The number is " << randomNumber << endl;
    cout << "You can exit the game at any time by entering 0." << endl;

    // Infinite loop until user guesses the correct number or enters 0 to exit
    while (true)
    {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess == 0) // User wants to exit the game
        {
            cout << "Exiting game. The number was: " << randomNumber << endl;
            break; // Exit the loop
        }
        else if (userGuess > randomNumber) // User's guess is higher than the random number
        {
            cout << "Your guess is too high. Try again." << endl;
        }
        else if (userGuess < randomNumber) // User's guess is lower than the random number
        {
            cout << "Your guess is too low. Try again." << endl;
        }
        else // User's guess is equal to the random number
        {
            cout << "Congratulations! You guessed the number correctly 🎉" << endl;
            break; // Exit the loop
        }
    }

    return 0;
}