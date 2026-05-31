#include <iostream>
#include <string>

using namespace std;

// Function to calculate the main salary
float getSalary(float hours, float rate) {
    float result = hours * rate;
    return result;
}

// Function to calculate tax (10%)
float getTax(float amount) {
    return amount * 0.10;
}

// Function to print the final payslip
void showSlip(string name, int id, float hours, float rate, float total, float tax, float net) {
    cout << "\n--- EMPLOYEE PAYSLIP ---" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Hours Worked: " << hours << endl;
    cout << "Rate per Hour: $" << rate << endl;
    cout << "-----------------------" << endl;
    cout << "Gross Salary: $" << total << endl;
    cout << "Tax Deducted: $" << tax << endl;
    cout << "Net Salary:   $" << net << endl;
    cout << "-----------------------" << endl;

    if (net > 3000) {
        cout << "Status: High Tier Salary" << endl;
    } else {
        cout << "Status: Standard Tier Salary" << endl;
    }
}

int main() {
    string empName;
    int empId;
    float hours, rate;

    cout << "=== Salary Calculation System ===" << endl;

    // Get info from user
    cout << "Enter employee name: ";
    getline(cin, empName);
    cout << "Enter employee ID: ";
    cin >> empId;

    cout << "Enter total hours worked: ";
    cin >> hours;
    cout << "Enter pay rate per hour: ";
    cin >> rate;

    // Check if input is wrong
    if (hours < 0 || rate < 0) {
        cout << "Error: Input values cannot be negative!" << endl;
        return 0;
    }

    // Calculations using functions
    float gross = getSalary(hours, rate);
    float taxAmount = getTax(gross);
    float netSalary = gross - taxAmount;

    // Print the result
    printReport(empName, empId, hours, rate, gross, taxAmount, netSalary);

    return 0;
}