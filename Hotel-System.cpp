#include <iostream>
#include <string>

using namespace std;

// Function to get room price per night based on type
float getRoomPrice(int type) {
    if (type == 1) return 40.0; // Standard room
    if (type == 2) return 75.0; // Deluxe room
    if (type == 3) return 120.0; // Suite room
    return 0.0;
}

// Function to calculate total tax (15%)
float calculateTax(float amount) {
    return amount * 0.15;
}

// Function to print the final receipt
void printBill(string name, int days, float roomPrice, float total, float tax, float net) {
    cout << "\n--- HOTEL STAY RECEIPT ---" << endl;
    cout << "Guest Name: " << name << endl;
    cout << "Nights Stayed: " << days << endl;
    cout << "Room Rate: $" << roomPrice << " / night" << endl;
    cout << "--------------------------" << endl;
    cout << "Room Total: $" << total << endl;
    cout << "Tax (15%):  $" << tax << endl;
    cout << "Final Total: $" << net << endl;
    cout << "--------------------------" << endl;
    cout << "Thank you for staying with us!" << endl;
}

int main() {
    string guestName;
    int roomType, stayDays;
    
    cout << "=== Hotel Billing System ===" << endl;

    // Get input from user
    cout << "Enter guest name: ";
    getline(cin, guestName);

    cout << "\nSelect Room Type:" << endl;
    cout << "1. Standard Room ($40/night)" << endl;
    cout << "2. Deluxe Room ($75/night)" << endl;
    cout << "3. Luxury Suite ($120/night)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> roomType;

    // Validate type choice
    if (roomType < 1 || roomType > 3) {
        cout << "Error: Invalid room type selection!" << endl;
        return 0;
    }

    cout << "Enter number of nights: ";
    cin >> stayDays;

    // Validate days input
    if (stayDays <= 0) {
        cout << "Error: Nights must be more than 0!" << endl;
        return 0;
    }

    // Process using functions
    float pricePerNight = getRoomPrice(roomType);
    float costBeforeTax = pricePerNight * stayDays;
    float taxAmount = calculateTax(costBeforeTax);
    float finalBill = costBeforeTax + taxAmount;

    // Output the report
    printBill(guestName, stayDays, pricePerNight, costBeforeTax, taxAmount, finalBill);

    return 0;
}