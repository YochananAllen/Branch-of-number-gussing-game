// Branch of number gussing game.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Yochanan Allen 
// Create a second branch in your Exercise 20 project and Enhance the program that you wrote for Programming Challenge 20
//so it keeps a count of the number of guesses the user makes. When the user correctly guesses the random number,
//the program should display the number of guesses.

#include <iostream>
#include <random>
#include <string> 

using namespace std;

int main() {
    char playAgain;

    do {
        random_device rd;
        default_random_engine gen(rd());
        uniform_int_distribution<> distr(1, 100);

        int randomNumber = distr(gen);
        int guess = 0;
        int guessCount = 0;

        cout << "Welcome to the Random Number Guessing Game!" << endl;
        cout << "I'm thinking of a number between 1 and 100." << endl;

        while (guess != randomNumber) {
            cout << "Enter your guess: ";
            string input;


            getline(cin, input);


            try {
                guess = stoi(input);
            }
            catch (invalid_argument&) {
                cout << "Please enter a valid number." << endl;
                continue;
            }
            catch (out_of_range&) {
                cout << "Number is out of range. Please enter a number between 1 and 100." << endl;
                continue;
            }

            guessCount++;

            if (guess > randomNumber) {
                cout << "Too high, try again." << endl;
            }
            else if (guess < randomNumber) {
                cout << "Too low, try again." << endl;
            }
            else {
                cout << "Congratulations! You've guessed the number!" << endl;
                cout << "It took you " << guessCount << " guesses." << endl;
            }
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;


        cin.ignore();

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
