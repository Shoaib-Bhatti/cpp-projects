#include <iostream>
using namespace std;

int main() {
    int choice;
    double amount, result;

    do {
        cout << "\n=== Currency Converter System ===\n";
        cout << "1. USD to PKR\n";
        cout << "2. PKR to USD\n";
        cout << "3. USD to SAR (Saudi Riyal)\n";
        cout << "4. SAR to USD\n";
        cout << "5. USD to AED (Dirham)\n";
        cout << "6. AED to USD\n";
        cout << "7. USD to GBP (Pound)\n";
        cout << "8. GBP to USD\n";
        cout << "9. USD to AUD (Australian Dollar)\n";
        cout << "10. AUD to USD\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 11) {
            cout << "Exiting...\n";
            break;
        }

        cout << "Enter amount: ";
        cin >> amount;

        switch (choice) {
            case 1: result = amount * 278.45; cout << "USD to PKR: " << result << endl; break;
            case 2: result = amount / 278.45; cout << "PKR to USD: " << result << endl; break;
            case 3: result = amount * 3.75; cout << "USD to SAR: " << result << endl; break;
            case 4: result = amount / 3.75; cout << "SAR to USD: " << result << endl; break;
            case 5: result = amount * 3.67; cout << "USD to AED: " << result << endl; break;
            case 6: result = amount / 3.67; cout << "AED to USD: " << result << endl; break;
            case 7: result = amount * 0.78; cout << "USD to GBP: " << result << endl; break;
            case 8: result = amount / 0.78; cout << "GBP to USD: " << result << endl; break;
            case 9: result = amount * 1.52; cout << "USD to AUD: " << result << endl; break;
            case 10: result = amount / 1.52; cout << "AUD to USD: " << result << endl; break;
            default: cout << "Invalid choice. Please try again.\n";
        }

    } while (true);

    return 0;
}
