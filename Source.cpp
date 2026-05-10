#include <iostream>
#include <string>

using namespace std;

void showMenu() {
    cout << "--- Newton's Second Law Calculator ---" << endl;
    cout << "1. Calculate Force (F)" << endl;
    cout << "2. Calculate Mass (m)" << endl;
    cout << "3. Calculate Acceleration (a)" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    float f, m, a;

    showMenu();
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter Mass (kg): ";
			cin >> m;
            cout << "Enter Acceleration (m/s^2): "; 
			cin >> a;
            cout << "Force = " << m * a << " Newton" << endl;
            break;
        case 2:
            cout << "Enter Force (N): "; 
			cin >> f;
            cout << "Enter Acceleration (m/s^2): ";
			cin >> a;
            cout << "Mass = " << f / a << " kg" << endl;
            break;
        case 3:
            cout << "Enter Force (N): "; 
			cin >> f;
            cout << "Enter Mass (kg): "; 
			cin >> m;
            cout << "Acceleration = " << f / m << " m/s^2" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    system("pause");
}