#include <iostream>
using namespace std;

int main() {
    double weight, height, bmi;
    int choice;

    cout << "\n=== BMI Converter System ===\n";
    cout << "1. Calculate BMI\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter your weight (in kilograms): ";
        cin >> weight;
        cout << "Enter your height (in meters): ";
        cin >> height;

        bmi = weight / (height * height);

        cout << "\nYour BMI is: " << bmi << endl;

        if (bmi < 18.5)
            cout << "Status: Underweight\n";
        else if (bmi >= 18.5 && bmi < 24.9)
            cout << "Status: Normal weight\n";
        else if (bmi >= 25 && bmi < 29.9)
            cout << "Status: Overweight\n";
        else
            cout << "Status: Obese\n";
    } 
    else {
        cout << "Exiting the program.\n";
    }

    return 0;
}
