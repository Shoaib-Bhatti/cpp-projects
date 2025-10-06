#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;
    char grade;

    void calculateGrade() {
        if (marks >= 90) grade = 'A';
        else if (marks >= 80) grade = 'B';
        else if (marks >= 70) grade = 'C';
        else if (marks >= 60) grade = 'D';
        else grade = 'F';
    }

    void input() {
        cout << "\nEnter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
        calculateGrade();
    }

    void display() const {
        cout << "Roll: " << roll << " | Name: " << name
             << " | Marks: " << marks << " | Grade: " << grade << endl;
    }
};

vector<Student> students;

void saveToFile() {
    ofstream file("students.txt");
    for (auto &s : students) {
        file << s.roll << "," << s.name << "," << s.marks << "," << s.grade << "\n";
    }
    file.close();
}

void loadFromFile() {
    ifstream file("students.txt");
    if (!file) return;
    Student s;
    string line;
    while (getline(file, line)) {
        size_t p1 = line.find(','), p2 = line.find(',', p1 + 1), p3 = line.find(',', p2 + 1);
        s.roll = stoi(line.substr(0, p1));
        s.name = line.substr(p1 + 1, p2 - p1 - 1);
        s.marks = stof(line.substr(p2 + 1, p3 - p2 - 1));
        s.grade = line[p3 + 1];
        students.push_back(s);
    }
    file.close();
}

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "\nStudent added successfully.\n";
}

void viewAll() {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (auto &s : students) s.display();
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll No to Search: ";
    cin >> roll;
    for (auto &s : students) {
        if (s.roll == roll) {
            cout << "\nStudent Found:\n";
            s.display();
            return;
        }
    }
    cout << "\nStudent not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll No to Delete: ";
    cin >> roll;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "\nStudent deleted successfully.\n";
            return;
        }
    }
    cout << "\nStudent not found.\n";
}

void sortByMarks() {
    if (students.empty()) {
        cout << "\nNo records available to sort.\n";
        return;
    }
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.marks > b.marks;
    });
    cout << "\nStudents sorted by marks (highest to lowest):\n";
    for (auto &s : students) s.display();
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "        STUDENT MANAGEMENT SYSTEM\n";
        cout << "              By: Shoaib Bhatti\n";
        cout << "========================================\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Sort by Marks\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewAll(); break;
        case 3: searchStudent(); break;
        case 4: deleteStudent(); break;
        case 5: sortByMarks(); break;
        case 6:
            saveToFile();
            cout << "\nAll records saved. Exiting program...\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
