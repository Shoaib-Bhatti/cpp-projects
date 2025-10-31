#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    do {
        cout << "\n=== Volume Converter System ===\n";
        cout << "1. Liters to Milliliters\n";
        cout << "2. Milliliters to Liters\n";
        cout << "3. Liters to Gallons\n";
        cout << "4. Gallons to Liters\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter value: ";
            cin >> value;
        }

        switch (choice) {
            case 1:
                result = value * 1000;
                cout << value << " liters = " << result << " milliliters\n";
                break;
            case 2:
                result = value / 1000;
                cout << value << " milliliters = " << result << " liters\n";
                break;
            case 3:
                result = value * 0.264172;
                cout << value << " liters = " << result << " gallons\n";
                break;
            case 4:
                result = value / 0.264172;
                cout << value << " gallons = " << result << " liters\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
