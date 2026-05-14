#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

/* 
   Project: The Secret Number Game
   Purpose: Practice logic, loops, and random number generation.
 
*/

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 50 + 1;
    int userGuess = 0;
    int tries = 0;

    cout << "== Welcome to My Guessing Game! ==" << endl;
    cout << "I have picked a number between 1 and 50." << endl;
    cout << "Can you guess it?" << endl;

    while (userGuess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        tries++;

        if (userGuess > secretNumber) {
            cout << "Too high! Try a smaller number." << endl;
        } 
        else if (userGuess < secretNumber) {
            cout << "Too low! Try a bigger number." << endl;
        } 
        else {
            cout << "\nCONGRATULATIONS!" << endl;
            cout << "You found it in " << tries << " tries." << endl;
        }
    }

    cout << "Thanks for playing my first C++ game!" << endl;

    return 0;
}