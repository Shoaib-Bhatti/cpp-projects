#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    do {
        cout << "\n=== Length Converter ===\n";
        cout << "1. Meters to Kilometers\n";
        cout << "2. Kilometers to Meters\n";
        cout << "3. Centimeters to Meters\n";
        cout << "4. Meters to Centimeters\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter length in meters: ";
            cin >> value;
            result = value / 1000;
            cout << "Length in kilometers: " << result << " km\n";
        } 
        else if (choice == 2) {
            cout << "Enter length in kilometers: ";
            cin >> value;
            result = value * 1000;
            cout << "Length in meters: " << result << " m\n";
        } 
        else if (choice == 3) {
            cout << "Enter length in centimeters: ";
            cin >> value;
            result = value / 100;
            cout << "Length in meters: " << result << " m\n";
        } 
        else if (choice == 4) {
            cout << "Enter length in meters: ";
            cin >> value;
            result = value * 100;
            cout << "Length in centimeters: " << result << " cm\n";
        } 
        else if (choice == 5) {
            cout << "Exiting Length Converter...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
