#include <iostream>
#include <string>

using namespace std;

/* 
   Project: Smart Car Rental Management System
   */

int main() {
    // Car types and basic variables
    int carCategory, carSelection, rentalDays;
    string selectedCarName = "";
    double pricePerDay = 0;
    char addMoreOptions;

    // Rental configuration variables
    int insuranceType = 0;
    double insuranceCostPerDay = 0;
    string insuranceName = "None";
    
    bool includeGPS = false;
    bool includeChildSeat = false;
    double gpsCostPerDay = 3.50;
    double childSeatCostPerDay = 2.00;

    cout << "==================================================" << endl;
    cout << "          WELCOME TO DRIVE-EASY CAR RENTAL        " << endl;
    cout << "==================================================" << endl;

    // STEP 1: Main Car Category Selection
    cout << "\nChoose Car Category:" << endl;
    cout << "1. Economy (Budget Friendly)" << endl;
    cout << "2. SUVs (Family & Adventure)" << endl;
    cout << "3. Luxury (Premium Experience)" << endl;
    cout << "Select category (1-3): ";
    cin >> carCategory;

    // STEP 2: Nested Sub-menus for specific models
    if (carCategory == 1) {
        cout << "\n--- ECONOMY CARS AVAILABLE ---" << endl;
        cout << "1. Hyundai Elantra  - $25.00 / day" << endl;
        cout << "2. Toyota Corolla   - $28.00 / day" << endl;
        cout << "3. Kia Rio          - $22.00 / day" << endl;
        cout << "Select vehicle (1-3): ";
        cin >> carSelection;

        switch (carSelection) {
            case 1: selectedCarName = "Hyundai Elantra"; pricePerDay = 25.00; break;
            case 2: selectedCarName = "Toyota Corolla"; pricePerDay = 28.00; break;
            case 3: selectedCarName = "Kia Rio"; pricePerDay = 22.00; break;
            default: cout << "Invalid car selected!" << endl; return 0;
        }
    } 
    else if (carCategory == 2) {
        cout << "\n--- SUVs AVAILABLE ---" << endl;
        cout << "1. Toyota RAV4      - $45.00 / day" << endl;
        cout << "2. Hyundai Tucson   - $40.00 / day" << endl;
        cout << "3. Jeep Grand Chero - $60.00 / day" << endl;
        cout << "Select vehicle (1-3): ";
        cin >> carSelection;

        switch (carSelection) {
            case 1: selectedCarName = "Toyota RAV4"; pricePerDay = 45.00; break;
            case 2: selectedCarName = "Hyundai Tucson"; pricePerDay = 40.00; break;
            case 3: selectedCarName = "Jeep Grand Cherokee"; pricePerDay = 60.00; break;
            default: cout << "Invalid car selected!" << endl; return 0;
        }
    } 
    else if (carCategory == 3) {
        cout << "\n--- LUXURY CARS AVAILABLE ---" << endl;
        cout << "1. Mercedes C-Class - $90.00 / day" << endl;
        cout << "2. BMW 5 Series     - $95.00 / day" << endl;
        cout << "3. Audi A6          - $85.00 / day" << endl;
        cout << "Select vehicle (1-3): ";
        cin >> carSelection;

        switch (carSelection) {
            case 1: selectedCarName = "Mercedes C-Class"; pricePerDay = 90.00; break;
            case 2: selectedCarName = "BMW 5 Series"; pricePerDay = 95.00; break;
            case 3: selectedCarName = "Audi A6"; pricePerDay = 85.00; break;
            default: cout << "Invalid car selected!" << endl; return 0;
        }
    } 
    else {
        cout << "Invalid category selection!" << endl;
        return 0;
    }

    // STEP 3: Enter duration
    cout << "\nEnter total rental period (in days): ";
    cin >> rentalDays;
    if (rentalDays <= 0) {
        cout << "Error: Rental duration must be at least 1 day!" << endl;
        return 0;
    }

    // STEP 4: Choose Insurance coverage Plan
    cout << "\nSelect Insurance Plan (Recommended):" << endl;
    cout << "1. Basic Cover     (Third party only) - $5.00 / day" << endl;
    cout << "2. Full Protection (Zero liability)   - $15.00 / day" << endl;
    cout << "3. No Insurance    (Risky)            - $0.00 / day" << endl;
    cout << "Select choice (1-3): ";
    cin >> insuranceType;

    if (insuranceType == 1) {
        insuranceName = "Basic Cover";
        insuranceCostPerDay = 5.00;
    } else if (insuranceType == 2) {
        insuranceName = "Full Protection";
        insuranceCostPerDay = 15.00;
    }

    // STEP 5: Add extra GPS or Accessories
    cout << "\nDo you want to add GPS Navigation System for $3.50/day? (y/n): ";
    cin >> addMoreOptions;
    if (addMoreOptions == 'y' || addMoreOptions == 'Y') includeGPS = true;

    cout << "Do you want to add a Child Safety Seat for $2.00/day? (y/n): ";
    cin >> addMoreOptions;
    if (addMoreOptions == 'y' || addMoreOptions == 'Y') includeChildSeat = true;

    // STEP 6: Invoice Calculations
    double baseCarCost = pricePerDay * rentalDays;
    double totalInsuranceCost = insuranceCostPerDay * rentalDays;
    double totalGpsCost = (includeGPS ? gpsCostPerDay : 0) * rentalDays;
    double totalSeatCost = (includeChildSeat ? childSeatCostPerDay : 0) * rentalDays;
    
    double finalInvoiceTotal = baseCarCost + totalInsuranceCost + totalGpsCost + totalSeatCost;

    // STEP 7: Print detailed digital contract/invoice
    cout << "\n==================================================" << endl;
    cout << "             OFFICIAL LEASE CONTRACT              " << endl;
    cout << "==================================================" << endl;
    cout << "Vehicle Selected:   " << selectedCarName << endl;
    cout << "Rental Duration:    " << rentalDays << " Days" << endl;
    cout << "Rate per Day:       $" << pricePerDay << " / day" << endl;
    cout << "Insurance Selected: " << insuranceName << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Base Car Cost:      $" << baseCarCost << endl;
    if (totalInsuranceCost > 0) {
        cout << "Insurance Total:    +$" << totalInsuranceCost << endl;
    }
    if (includeGPS) {
        cout << "GPS Navigator addon:+$" << totalGpsCost << endl;
    }
    if (includeChildSeat) {
        cout << "Child Seat addon:   +$" << totalSeatCost << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "TOTAL CONTRACT DUE: $" << finalInvoiceTotal << endl;
    cout << "==================================================" << endl;
    cout << "       Drive safely! Please return with full tank. " << endl;
    cout << "==================================================" << endl;

    return 0;
}