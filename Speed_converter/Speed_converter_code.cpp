#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    do {
        cout << "\n=== Speed Converter ===\n";
        cout << "1. Meters/Second to Kilometers/Hour\n";
        cout << "2. Kilometers/Hour to Meters/Second\n";
        cout << "3. Meters/Second to Miles/Hour\n";
        cout << "4. Miles/Hour to Meters/Second\n";
        cout << "5. Kilometers/Hour to Miles/Hour\n";
        cout << "6. Miles/Hour to Kilometers/Hour\n";
        cout << "7. Meters/Second to Feet/Second\n";
        cout << "8. Feet/Second to Meters/Second\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 8) {
            cout << "Enter value: ";
            cin >> value;
        }

        switch (choice) {
            case 1: result = value * 3.6; cout << "Result: " << result << " km/h\n"; break;
            case 2: result = value / 3.6; cout << "Result: " << result << " m/s\n"; break;
            case 3: result = value * 2.23694; cout << "Result: " << result << " mph\n"; break;
            case 4: result = value / 2.23694; cout << "Result: " << result << " m/s\n"; break;
            case 5: result = value / 1.60934; cout << "Result: " << result << " mph\n"; break;
            case 6: result = value * 1.60934; cout << "Result: " << result << " km/h\n"; break;
            case 7: result = value * 3.28084; cout << "Result: " << result << " ft/s\n"; break;
            case 8: result = value / 3.28084; cout << "Result: " << result << " m/s\n"; break;
            case 9: cout << "Exiting Speed Converter...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
