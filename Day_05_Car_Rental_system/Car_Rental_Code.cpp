#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Car {
public:
    int id;
    string name;
    string model;
    double rentPerDay;
    bool available;

    Car(int i, string n, string m, double r, bool a)
        : id(i), name(n), model(m), rentPerDay(r), available(a) {}
};

vector<Car> cars;

void saveData() {
    ofstream file("cars.txt");
    for (auto &c : cars) {
        file << c.id << " " << c.name << " " << c.model << " " << c.rentPerDay << " " << c.available << endl;
    }
    file.close();
}

void loadData() {
    ifstream file("cars.txt");
    cars.clear();
    int id;
    string name, model;
    double rent;
    bool available;
    while (file >> id >> name >> model >> rent >> available) {
        cars.push_back(Car(id, name, model, rent, available));
    }
    file.close();
}

void addCar() {
    int id;
    string name, model;
    double rent;
    cout << "Enter Car ID: ";
    cin >> id;
    cout << "Enter Car Name: ";
    cin >> name;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Rent per day: ";
    cin >> rent;

    cars.push_back(Car(id, name, model, rent, true));
    cout << "Car added successfully!\n";
    saveData();
}

void viewCars() {
    cout << "\n===== Available Cars =====\n";
    for (auto &c : cars) {
        cout << "ID: " << c.id
             << " | Name: " << c.name
             << " | Model: " << c.model
             << " | Rent/Day: $" << c.rentPerDay
             << " | Status: " << (c.available ? "Available" : "Rented") << endl;
    }
}

void rentCar() {
    int id;
    cout << "Enter Car ID to rent: ";
    cin >> id;
    for (auto &c : cars) {
        if (c.id == id && c.available) {
            c.available = false;
            cout << "You have rented " << c.name << " successfully!\n";
            saveData();
            return;
        }
    }
    cout << "Car not available or ID not found.\n";
}

void returnCar() {
    int id;
    cout << "Enter Car ID to return: ";
    cin >> id;
    for (auto &c : cars) {
        if (c.id == id && !c.available) {
            c.available = true;
            cout << "Car returned successfully!\n";
            saveData();
            return;
        }
    }
    cout << "Car not found or already available.\n";
}

void sortByPrice() {
    sort(cars.begin(), cars.end(), [](Car &a, Car &b) {
        return a.rentPerDay < b.rentPerDay;
    });
    cout << "\nCars sorted by price (low to high):\n";
    viewCars();
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\n===== Car Rental System =====\n";
        cout << "1. Add Car\n2. View Cars\n3. Rent Car\n4. Return Car\n5. Sort Cars by Price\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: addCar(); break;
        case 2: viewCars(); break;
        case 3: rentCar(); break;
        case 4: returnCar(); break;
        case 5: sortByPrice(); break;
        case 6: saveData(); cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
