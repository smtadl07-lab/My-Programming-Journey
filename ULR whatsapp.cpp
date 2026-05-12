#include <iostream>
#include <string>

using namespace std;

/* 
   Project: WhatsApp Link Generator
   This tool helps convert a phone number into a professional wa.me link.
*/

int main() {
    string countryCode, phoneNumber;
    string baseUrl = "https://wa.me/";

    cout << "--- Professional WhatsApp Link Generator ---" << endl;
    
    
    cout << "Enter Country Code (without +): ";
    cin >> countryCode;

    cout << "Enter Phone Number (without leading zero): ";
    cin >> phoneNumber;


    string finalLink = baseUrl + countryCode + phoneNumber;

    cout << "\n--------------------------------------------" << endl;
    cout << "Your professional link is ready:" << endl;
    cout << finalLink << endl;
    cout << "--------------------------------------------" << endl;
    
    cout << "\nTip: You can use this link in your GitHub Bio!" << endl;

    return 0;
}