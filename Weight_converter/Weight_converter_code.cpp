#include <iostream>
using namespace std;

int main() {
    int choice;
    double grams, kilograms, pounds;

    do {
        cout << "\n=== Weight Converter ===\n";
        cout << "1. Grams to Kilograms\n";
        cout << "2. Kilograms to Grams\n";
        cout << "3. Kilograms to Pounds\n";
        cout << "4. Pounds to Kilograms\n";
        cout << "5. Grams to Pounds\n";
        cout << "6. Pounds to Grams\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter weight in grams: ";
                cin >> grams;
                kilograms = grams / 1000;
                cout << "Weight in kilograms: " << kilograms << endl;
                break;

            case 2:
                cout << "Enter weight in kilograms: ";
                cin >> kilograms;
                grams = kilograms * 1000;
                cout << "Weight in grams: " << grams << endl;
                break;

            case 3:
                cout << "Enter weight in kilograms: ";
                cin >> kilograms;
                pounds = kilograms * 2.20462;
                cout << "Weight in pounds: " << pounds << endl;
                break;

            case 4:
                cout << "Enter weight in pounds: ";
                cin >> pounds;
                kilograms = pounds / 2.20462;
                cout << "Weight in kilograms: " << kilograms << endl;
                break;

            case 5:
                cout << "Enter weight in grams: ";
                cin >> grams;
                pounds = grams / 453.592;
                cout << "Weight in pounds: " << pounds << endl;
                break;

            case 6:
                cout << "Enter weight in pounds: ";
                cin >> pounds;
                grams = pounds * 453.592;
                cout << "Weight in grams: " << grams << endl;
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}






