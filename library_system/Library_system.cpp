#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Book {
public:
    int id;
    string title, author, genre;
    int year;
    bool available;

    Book(int i, string t, string a, string g, int y, bool av) {
        id = i; title = t; author = a; genre = g; year = y; available = av;
    }

    string toString() const {
        return "ID: " + to_string(id) + " | Title: " + title + " | Author: " + author +
               " | Genre: " + genre + " | Year: " + to_string(year) +
               " | Available: " + string(available ? "Yes" : "No");
    }

    string fileString() const {
        return to_string(id) + " | " + title + " | " + author + " | " + genre + " | " +
               to_string(year) + " | " + string(available ? "Yes" : "No");
    }
};

class Member {
public:
    int id;
    string name, gender, contact;
    int age;

    Member(int i, string n, int a, string g, string c) {
        id = i; name = n; age = a; gender = g; contact = c;
    }

    string toString() const {
        return "ID: " + to_string(id) + " | Name: " + name + " | Age: " + to_string(age) +
               " | Gender: " + gender + " | Contact: " + contact;
    }

    string fileString() const {
        return to_string(id) + " | " + name + " | " + to_string(age) +
               " | " + gender + " | " + contact;
    }
};

class IssuedRecord {
public:
    string memberName, bookTitle, issueDate, returnDate;

    IssuedRecord(string m, string b, string i, string r) {
        memberName = m; bookTitle = b; issueDate = i; returnDate = r;
    }

    string toString() const {
        return "Member: " + memberName + " | Book: " + bookTitle +
               " | Issue Date: " + issueDate + " | Return Date: " + returnDate;
    }

    string fileString() const {
        return memberName + " | " + bookTitle + " | " + issueDate + " | " + returnDate;
    }
};

vector<Book> books;
vector<Member> members;
vector<IssuedRecord> records;

void addBook() {
    int id, year; string title, author, genre; char avail;
    cout << "Enter Book ID: "; cin >> id; cin.ignore();
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Genre: "; getline(cin, genre);
    cout << "Enter Publication Year: "; cin >> year;
    cout << "Is Available (y/n): "; cin >> avail;
    books.push_back(Book(id, title, author, genre, year, (avail=='y'||avail=='Y')));
    cout << "Book added successfully!\n";
}

void showBooks() {
    if (books.empty()) { cout << "No books available.\n"; return; }
    for (const auto &b : books) cout << b.toString() << endl;
}

void addMember() {
    int id, age; string name, gender, contact;
    cout << "Enter Member ID: "; cin >> id; cin.ignore();
    cout << "Enter Full Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age; cin.ignore();
    cout << "Enter Gender: "; getline(cin, gender);
    cout << "Enter Contact Number: "; getline(cin, contact);
    members.push_back(Member(id, name, age, gender, contact));
    cout << "Member added successfully!\n";
}

void showMembers() {
    if (members.empty()) { cout << "No members found.\n"; return; }
    for (const auto &m : members) cout << m.toString() << endl;
}

void issueBook() {
    if (members.empty() || books.empty()) {
        cout << "Add members and books first.\n"; return;
    }
    cout << "\n--- Members ---\n";
    for (const auto &m : members) cout << m.toString() << endl;
    int memId; cout << "Enter Member ID: "; cin >> memId;
    Member *selMem = nullptr;
    for (auto &m : members) if (m.id == memId) selMem = &m;
    if (!selMem) { cout << "Invalid Member ID.\n"; return; }

    cout << "\n--- Available Books ---\n";
    for (const auto &b : books) if (b.available) cout << b.toString() << endl;
    int bookId; cout << "Enter Book ID: "; cin >> bookId;
    Book *selBook = nullptr;
    for (auto &b : books) if (b.id == bookId && b.available) selBook = &b;
    if (!selBook) { cout << "Invalid or unavailable Book ID.\n"; return; }

    string issueDate, returnDate; cin.ignore();
    cout << "Enter Issue Date: "; getline(cin, issueDate);
    cout << "Enter Return Date: "; getline(cin, returnDate);

    selBook->available = false;
    records.push_back(IssuedRecord(selMem->name, selBook->title, issueDate, returnDate));
    cout << "Book issued successfully to " << selMem->name << "!\n";
}

void showIssuedRecords() {
    if (records.empty()) { cout << "No records found.\n"; return; }
    for (const auto &r : records) cout << r.toString() << endl;
}

void saveBooksToFile() {
    ofstream f("books.txt"); for (const auto &b : books) f << b.fileString() << endl;
    f.close(); cout << "Books saved to books.txt\n";
}
void saveMembersToFile() {
    ofstream f("members.txt"); for (const auto &m : members) f << m.fileString() << endl;
    f.close(); cout << "Members saved to members.txt\n";
}
void saveRecordsToFile() {
    ofstream f("issued.txt"); for (const auto &r : records) f << r.fileString() << endl;
    f.close(); cout << "Issued records saved to issued.txt\n";
}

void saveDataMenu() {
    string pass;
    cout << "Enter password to save data: ";
    cin >> pass;
    if (pass != "admin123") {
        cout << "Wrong password. Access denied.\n"; return;
    }

    int choice;
    while (true) {
        cout << "\n===== Save Data Menu =====\n";
        cout << "1. Save Books to File\n2. Save Members to File\n3. Save Issued Records to File\n4. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: saveBooksToFile(); break;
            case 2: saveMembersToFile(); break;
            case 3: saveRecordsToFile(); break;
            case 4: return;
            default: cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n2. Show All Books\n3. Add Member\n4. Show All Members\n";
        cout << "5. Issue Book\n6. Show Issued Records\n7. Save Data\n8. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: addMember(); break;
            case 4: showMembers(); break;
            case 5: issueBook(); break;
            case 6: showIssuedRecords(); break;
            case 7: saveDataMenu(); break;
            case 8: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
