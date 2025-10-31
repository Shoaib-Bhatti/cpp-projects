#include <iostream>
using namespace std;

int main() {
    int choice;
    double celsius, fahrenheit, kelvin;

    do {
        cout << "\n=== Temperature Converter ===\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Fahrenheit to Celsius\n";
        cout << "3. Celsius to Kelvin\n";
        cout << "4. Kelvin to Celsius\n";
        cout << "5. Fahrenheit to Kelvin\n";
        cout << "6. Kelvin to Fahrenheit\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter temperature in Celsius: ";
                cin >> celsius;
                fahrenheit = (celsius * 9 / 5) + 32;
                cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
                break;

            case 2:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> fahrenheit;
                celsius = (fahrenheit - 32) * 5 / 9;
                cout << "Temperature in Celsius: " << celsius << endl;
                break;

            case 3:
                cout << "Enter temperature in Celsius: ";
                cin >> celsius;
                kelvin = celsius + 273.15;
                cout << "Temperature in Kelvin: " << kelvin << endl;
                break;

            case 4:
                cout << "Enter temperature in Kelvin: ";
                cin >> kelvin;
                celsius = kelvin - 273.15;
                cout << "Temperature in Celsius: " << celsius << endl;
                break;

            case 5:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> fahrenheit;
                kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
                cout << "Temperature in Kelvin: " << kelvin << endl;
                break;

            case 6:
                cout << "Enter temperature in Kelvin: ";
                cin >> kelvin;
                fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
                cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
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
