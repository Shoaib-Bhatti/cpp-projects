#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    do {
        cout << "\n=== Time Converter System ===\n";
        cout << "1. Seconds to Minutes\n";
        cout << "2. Minutes to Seconds\n";
        cout << "3. Minutes to Hours\n";
        cout << "4. Hours to Minutes\n";
        cout << "5. Hours to Days\n";
        cout << "6. Days to Hours\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter value: ";
            cin >> value;
        }

        switch (choice) {
            case 1:
                result = value / 60;
                cout << value << " seconds = " << result << " minutes\n";
                break;
            case 2:
                result = value * 60;
                cout << value << " minutes = " << result << " seconds\n";
                break;
            case 3:
                result = value / 60;
                cout << value << " minutes = " << result << " hours\n";
                break;
            case 4:
                result = value * 60;
                cout << value << " hours = " << result << " minutes\n";
                break;
            case 5:
                result = value / 24;
                cout << value << " hours = " << result << " days\n";
                break;
            case 6:
                result = value * 24;
                cout << value << " days = " << result << " hours\n";
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
