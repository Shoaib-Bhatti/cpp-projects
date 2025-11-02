#include <iostream>
#include <iomanip>
using namespace std;

void calculatePercentage() {
    int choice;
    char again;

    do {
        cout << "\n==============================\n";
        cout << "     PERCENTAGE MASTER TOOL\n";
        cout << "==============================\n";
        cout << "1. What is X% of Y?\n";
        cout << "2. X is what percent of Y?\n";
        cout << "3. If X% = Y, find the total (100%)\n";
        cout << "4. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            double X, Y;
            cout << "\nEnter percentage (X): ";
            cin >> X;
            cout << "Enter number (Y): ";
            cin >> Y;

            double result = (X / 100) * Y;
            cout << fixed << setprecision(2);
            cout << "\n----------------------------------\n";
            cout << X << "% of " << Y << " = " << result << endl;
            cout << "Explanation: (" << X << " / 100) × " << Y << " = " << result << endl;
            cout << "----------------------------------\n";
        }
        else if (choice == 2) {
            double X, Y;
            cout << "\nEnter first number (X): ";
            cin >> X;
            cout << "Enter second number (Y): ";
            cin >> Y;

            double result = (X / Y) * 100;
            cout << fixed << setprecision(2);
            cout << "\n----------------------------------\n";
            cout << X << " is " << result << "% of " << Y << endl;
            cout << "Explanation: (" << X << " / " << Y << ") × 100 = " << result << "%" << endl;
            cout << "----------------------------------\n";
        }
        else if (choice == 3) {
            double X, Y;
            cout << "\nIf X% = Y, find total (100%)\n";
            cout << "Enter percentage (X): ";
            cin >> X;
            cout << "Enter value (Y): ";
            cin >> Y;

            double total = (Y * 100) / X;
            cout << fixed << setprecision(2);
            cout << "\n----------------------------------\n";
            cout << "If " << X << "% = " << Y << ", then 100% = " << total << endl;
            cout << "Explanation: (" << Y << " × 100) / " << X << " = " << total << endl;
            cout << "----------------------------------\n";
        }
        else if (choice == 4) {
            cout << "\nThank you for using Percentage Master! 💡\n";
            break;
        }
        else {
            cout << "\nInvalid choice! Please choose between 1–4.\n";
        }

        cout << "\nDo you want to try another calculation? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');
}

int main() {
    calculatePercentage();
    cout << "\nKeep learning math made simple! \n";
    return 0;
}
