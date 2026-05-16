#include <iostream>
#include <string>

using namespace std;

/* 
   Project: Advanced Self-Service Restaurant System
*/

int main() {
    // Variables for ordering food
    int mainChoice, subChoice, quantity;
    float totalBill = 0;
    char orderAgain;
    
    // Variables for advanced features
    int serviceType; // 1: Dine-in, 2: Takeaway, 3: Delivery
    int tableNumber = 0;
    string deliveryAddress = "";
    float deliveryFee = 0;
    string promoCode = "";
    float discount = 0;
    float taxRate = 0.15; // 15% Tax rate

    cout << "==================================================" << endl;
    cout << "        WELCOME TO THE SMART RESTAURANT SYSTEM    " << endl;
    cout << "==================================================" << endl;

    // STEP 1: Ask user for the service type before ordering
    cout << "\nHow would you like to receive your order?" << endl;
    cout << "1. Dine-in (Inside the Restaurant)" << endl;
    cout << "2. Takeaway (Pickup)" << endl;
    cout << "3. Home Delivery" << endl;
    cout << "Select service type (1-3): ";
    cin >> serviceType;

    // Handle service choices (Table number or Delivery Address)
    if (serviceType == 1) {
        cout << "Enter your Table Number: ";
        cin >> tableNumber;
    } else if (serviceType == 3) {
        cin.ignore(); // Clear input buffer
        cout << "Enter your Delivery Address: ";
        getline(cin, deliveryAddress);
        deliveryFee = 5.00; // Fixed delivery fee
        cout << "Note: A $5.00 delivery fee will be added." << endl;
    }

    // STEP 2: Main loop for the digital food menu
    do {
        cout << "\n===== DIGITAL MENU CATEGORIES =====" << endl;
        cout << "1. Gourmet Burgers" << endl;
        cout << "2. Italian Pizzas" << endl;
        cout << "3. Refreshing Drinks" << endl;
        cout << "4. Special Desserts" << endl;
        cout << "===================================" << endl;
        cout << "Select a category (1-4): ";
        cin >> mainChoice;

        // Category 1: Burgers
        if (mainChoice == 1) {
            cout << "\n--- GOURMET BURGERS ---" << endl;
            cout << "1. Double Beef Cheese Burger  - $7.50" << endl;
            cout << "2. Spicy Zinger Chicken Burger - $6.50" << endl;
            cout << "3. BBQ Mushroom Burger        - $8.00" << endl;
            cout << "Select item: ";
            cin >> subChoice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (subChoice) {
                case 1: totalBill += 7.50 * quantity; break;
                case 2: totalBill += 6.50 * quantity; break;
                case 3: totalBill += 8.00 * quantity; break;
                default: cout << "Invalid item!" << endl;
            }
        } 
        // Category 2: Pizzas
        else if (mainChoice == 2) {
            cout << "\n--- ITALIAN PIZZAS ---" << endl;
            cout << "1. Pepperoni Supreme    - $11.00" << endl;
            cout << "2. BBQ Chicken Pizza    - $12.50" << endl;
            cout << "3. Margherita Classic   - $9.00" << endl;
            cout << "Select item: ";
            cin >> subChoice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (subChoice) {
                case 1: totalBill += 11.00 * quantity; break;
                case 2: totalBill += 12.50 * quantity; break;
                case 3: totalBill += 9.00 * quantity; break;
                default: cout << "Invalid item!" << endl;
            }
        } 
        // Category 3: Drinks
        else if (mainChoice == 3) {
            cout << "\n--- REFRESHING DRINKS ---" << endl;
            cout << "1. Fresh Mojito (Mint/Lemon) - $3.50" << endl;
            cout << "2. Iced Spanish Latte        - $4.50" << endl;
            cout << "3. Mineral Water             - $1.00" << endl;
            cout << "Select item: ";
            cin >> subChoice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (subChoice) {
                case 1: totalBill += 3.50 * quantity; break;
                case 2: totalBill += 4.50 * quantity; break;
                case 3: totalBill += 1.00 * quantity; break;
                default: cout << "Invalid item!" << endl;
            }
        } 
        // Category 4: Desserts
        else if (mainChoice == 4) {
            cout << "\n--- SPECIAL DESSERTS ---" << endl;
            cout << "1. Chocolate Souffle         - $5.00" << endl;
            cout << "2. Lotus Cheesecake          - $6.00" << endl;
            cout << "3. Waffle with Nutella       - $5.50" << endl;
            cout << "Select item: ";
            cin >> subChoice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (subChoice) {
                case 1: totalBill += 5.00 * quantity; break;
                case 2: totalBill += 6.00 * quantity; break;
                case 3: totalBill += 5.50 * quantity; break;
                default: cout << "Invalid item!" << endl;
            }
        } 
        else {
            cout << "Invalid category!" << endl;
        }

        // Ask the user if they want to add more food
        cout << "\nDo you want to add more items? (y/n): ";
        cin >> orderAgain;

    } while (orderAgain == 'y' || orderAgain == 'Y');

    // STEP 3: Promo Code / Coupon validation system
    cout << "\nDo you have a Promo Code? (Enter Code or 'NONE'): ";
    cin >> promoCode;

    if (promoCode == "SAVE10" || promoCode == "save10") {
        discount = totalBill * 0.10; // 10% discount
        cout << "Success: 10% Discount Applied!" << endl;
    } else if (promoCode == "FREE5" || promoCode == "free5") {
        discount = 5.00; // Flat $5 discount
        cout << "Success: $5.00 Discount Applied!" << endl;
    } else if (promoCode != "NONE" && promoCode != "none") {
        cout << "Invalid Promo Code. No discount applied." << endl;
    }

    // STEP 4: Final math calculations (Subtotal, Tax, and Final Total)
    float subtotalAfterDiscount = totalBill - discount;
    if (subtotalAfterDiscount < 0) subtotalAfterDiscount = 0; // Security check: prevent negative bills
    
    float taxAmount = subtotalAfterDiscount * taxRate;
    float finalTotal = subtotalAfterDiscount + taxAmount + deliveryFee;

    // STEP 5: Printing the final detailed invoice/receipt
    cout << "\n==================================================" << endl;
    cout << "                OFFICIAL RECEIPT                  " << endl;
    cout << "==================================================" << endl;
    
    // Print order specifications based on service type
    if (serviceType == 1) {
        cout << "Order Type:   Dine-In" << endl;
        cout << "Table Number: " << tableNumber << endl;
    } else if (serviceType == 2) {
        cout << "Order Type:   Takeaway (Pickup)" << endl;
    } else if (serviceType == 3) {
        cout << "Order Type:   Home Delivery" << endl;
        cout << "Address:      " << deliveryAddress << endl;
    }
    
    cout << "--------------------------------------------------" << endl;
    cout << "Items Total:      $" << totalBill << endl;
    if (discount > 0) {
        cout << "Promo Discount:  -$" << discount << endl;
    }
    cout << "Tax (15%):        $" << taxAmount << endl;
    if (deliveryFee > 0) {
        cout << "Delivery Fee:     $" << deliveryFee << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "TOTAL AMOUNT:     $" << finalTotal << endl;
    cout << "==================================================" << endl;
    cout << "       Thank you for using our Smart System!      " << endl;
    cout << "==================================================" << endl;

    return 0;
}