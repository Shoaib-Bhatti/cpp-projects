#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void binaryToDecimal() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;

    long long decimal = 0;
    int power = 0;

    // Validate input and calculate decimal
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        } else if (binary[i] != '0') {
            cout << "\nInvalid input! Only 0s and 1s are allowed.\n";
            return;
        }
        power++;
    }

    cout << "\n-----------------------------------------\n";
    cout << "Binary Number : " << binary << endl;
    cout << "Decimal Value : " << decimal << endl;
    cout << "-----------------------------------------\n\n";

    cout << "Explanation:\n";
    cout << binary << " = ";
    power = binary.size() - 1;
    for (int i = 0; i < binary.size(); i++) {
        cout << binary[i] << " * 2^" << power;
        if (i != binary.size() - 1)
            cout << " + ";
        power--;
    }
    cout << " = " << decimal << endl;
}

void decimalToBinary() {
    long long decimal;
    cout << "\nEnter a decimal number: ";
    cin >> decimal;

    if (decimal < 0) {
        cout << "\nNegative numbers are not supported.\n";
        return;
    }

    if (decimal == 0) {
        cout << "\nBinary Value: 0\n";
        return;
    }

    string binary = "";
    long long temp = decimal;

    while (temp > 0) {
        binary = char((temp % 2) + '0') + binary;
        temp /= 2;
    }

    cout << "\n-----------------------------------------\n";
    cout << "Decimal Number : " << decimal << endl;
    cout << "Binary Value   : " << binary << endl;
    cout << "-----------------------------------------\n\n";

    cout << "Explanation:\n";
    cout << decimal << " divided by 2 repeatedly gives remainders: ";
    temp = decimal;
    while (temp > 0) {
        cout << (temp % 2);
        temp /= 2;
        if (temp > 0) cout << ", ";
    }
    cout << " (read in reverse = " << binary << ")\n";
}

int main() {
    int choice;
    char again;

    do {
        cout << "\n=========================================\n";
        cout << "        BINARY TO DECIMAL CONVERTER\n";
        cout << "=========================================\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Decimal to Binary\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        if (choice == 1)
            binaryToDecimal();
        else if (choice == 2)
            decimalToBinary();
        else
            cout << "\nInvalid choice! Please enter 1 or 2.\n";

        cout << "\nDo you want to convert again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the converter.\n";
    return 0;
}
