#include <iostream>
#include <string>

using namespace std;

/* 
   Project: Smart ATM & Banking Account Simulator

*/

// Global Constants for Security
const string CORRECT_ACC_NUM = "123456";
const string CORRECT_PIN = "9988";

// FUNCTION 1: Handles user authentication and login attempts
bool runSecurityLogin() {
    string inputAccNum, inputPin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "\n[SECURITY LOGIN]" << endl;
        cout << "Enter Account Number: ";
        cin >> inputAccNum;
        cout << "Enter 4-Digit PIN: ";
        cin >> inputPin;

        if (inputAccNum == CORRECT_ACC_NUM && inputPin == CORRECT_PIN) {
            return true; // Login success
        } else {
            attempts++;
            cout << "Error: Invalid credentials! Attempts remaining: " << (3 - attempts) << endl;
        }
    }
    return false; // Login failed after 3 attempts
}

// FUNCTION 2: Displays the main dashboard menu
void displayMenu() {
    cout << "\n==================================================" << endl;
    cout << "                 ATM MAIN DASHBOARD               " << endl;
    cout << "==================================================" << endl;
    cout << "1. Check Account Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Cash" << endl;
    cout << "4. Terminate Session (Exit)" << endl;
    cout << "--------------------------------------------------" << endl;
}

// FUNCTION 3: Handles balance inquiry
void checkBalance(double balance) {
    cout << "\n[BALANCE INQUIRY]" << endl;
    cout << "Current Available Balance: $" << balance << endl;
}

// FUNCTION 4: Handles cash deposits with validation
double depositMoney(double currentBalance) {
    double amount;
    cout << "\n[CASH DEPOSIT SERVICE]" << endl;
    cout << "Enter deposit amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Transaction Failed: Invalid deposit amount!" << endl;
        return currentBalance; // Return unchanged balance
    } else {
        double newBalance = currentBalance + amount;
        cout << "Success: $" << amount << " deposited successfully." << endl;
        return newBalance; // Return updated balance
    }
}

// FUNCTION 5: Handles secure cash withdrawals
double withdrawMoney(double currentBalance) {
    double amount;
    cout << "\n[CASH WITHDRAWAL SERVICE]" << endl;
    cout << "Enter withdrawal amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Transaction Failed: Invalid withdrawal amount!" << endl;
        return currentBalance;
    } else if (amount > currentBalance) {
        cout << "Transaction Failed: Insufficient funds available!" << endl;
        return currentBalance;
    } else {
        double newBalance = currentBalance - amount;
        cout << "Success: Please collect your $" << amount << " cash." << endl;
        return newBalance;
    }
}

// THE MAIN FUNCTION: Controls the flow of the application
int main() {
    cout << "==================================================" << endl;
    cout << "          WELCOME TO THE GLOBAL DIGITAL BANK      " << endl;
    cout << "==================================================" << endl;

    // Call Security Function
    if (!runSecurityLogin()) {
        cout << "\n**************************************************" << endl;
        cout << "CRITICAL WARNING: Account locked due to 3 failed attempts." << endl;
        cout << "**************************************************" << endl;
        return 0; // Stop the program
    }

    double accountBalance = 500.00; // Shared state variable
    int userChoice;
    char exitChoice;

    // Main Transaction Loop
    do {
        displayMenu();
        cout << "Please select an option (1-4): ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                checkBalance(accountBalance);
                break;
            case 2:
                accountBalance = depositMoney(accountBalance); // Update balance via function return
                break;
            case 3:
                accountBalance = withdrawMoney(accountBalance); // Update balance via function return
                break;
            case 4:
                cout << "\nThank you for banking with us today!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-4." << endl;
        }

        // Ask for another transaction
        if (userChoice != 4) {
            cout << "\nWould you like another transaction? (y/n): ";
            cin >> exitChoice;
            if (exitChoice == 'n' || exitChoice == 'N') {
                userChoice = 4; // Break loop
                cout << "\nThank you for banking with us today!" << endl;
            }
        }

    } while (userChoice != 4);

    cout << "==================================================" << endl;
    cout << "        SESSION ENDED. SECURELY LOGGING OUT...    " << endl;
    cout << "==================================================" << endl;

    return 0;
}