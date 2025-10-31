#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Expense {
public:
    string date, category, note;
    double amount;

    Expense(string d, string c, double a, string n) {
        date = d;
        category = c;
        amount = a;
        note = n;
    }
};

vector<Expense> expenses;

void saveData() {
    ofstream file("expenses.txt");
    for (auto &e : expenses) {
        // Save each field with a separator (like |) to handle spaces safely
        file << e.date << "|" << e.category << "|" << e.amount << "|" << e.note << endl;
    }
    file.close();
}

void loadData() {
    ifstream file("expenses.txt");
    expenses.clear();

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
            continue;

        string date = line.substr(0, pos1);
        string category = line.substr(pos1 + 1, pos2 - pos1 - 1);
        double amount = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
        string note = line.substr(pos3 + 1);

        expenses.push_back(Expense(date, category, amount, note));
    }
    file.close();
}

void addExpense() {
    string date, category, note;
    double amount;

    cin.ignore(); // clear leftover newline before getline

    cout << "Enter Date (DD-MM-YYYY): ";
    getline(cin, date);

    cout << "Enter Category (Food/Travel/Shopping/etc): ";
    getline(cin, category);

    cout << "Enter Amount: ";
    cin >> amount;
    cin.ignore(); // clear buffer again

    cout << "Enter Note: ";
    getline(cin, note);

    expenses.push_back(Expense(date, category, amount, note));
    saveData();
    cout << "Expense added successfully!\n";
}

void viewExpenses() {
    cout << "\n===== All Expenses =====\n";
    cout << left << setw(12) << "Date" << setw(15) << "Category"
         << setw(10) << "Amount" << setw(25) << "Note" << endl;
    cout << "-------------------------------------------------------------\n";
    for (auto &e : expenses) {
        cout << left << setw(12) << e.date
             << setw(15) << e.category
             << setw(10) << e.amount
             << setw(25) << e.note << endl;
    }
}

void totalSpending() {
    double total = 0;
    for (auto &e : expenses)
        total += e.amount;
    cout << "\n Total Spending: $" << total << endl;
}

void filterByCategory() {
    string cat;
    cin.ignore();
    cout << "Enter category to filter: ";
    getline(cin, cat);

    cout << "\nExpenses in category: " << cat << endl;
    cout << left << setw(12) << "Date" << setw(15) << "Category"
         << setw(10) << "Amount" << setw(25) << "Note" << endl;
    cout << "-------------------------------------------------------------\n";
    for (auto &e : expenses) {
        if (e.category == cat) {
            cout << left << setw(12) << e.date
                 << setw(15) << e.category
                 << setw(10) << e.amount
                 << setw(25) << e.note << endl;
        }
    }
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\n===== Expense Tracker System =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Show Total Spending\n";
        cout << "4. Filter by Category\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalSpending(); break;
            case 4: filterByCategory(); break;
            case 5: saveData(); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
