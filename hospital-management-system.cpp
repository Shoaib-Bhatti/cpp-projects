#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    string Disease;

    void input() {
        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Full Name : ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender (Male/Female): ";
        getline(cin, gender);
        cout << "Enter Disease: ";
        getline(cin, Disease);
    
    }

    string toString() const {
        stringstream ss;
        ss << "Patient ID: " << id << ", Name: " << name 
           << ", Age: " << age << ", Gender: " << gender;
        return ss.str();
    }
};

class Doctor {
public:
    int id;
    string name;
    int age;
    string gender;
    string specialization;

    void input() {
        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Doctor Full Name : ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender (Male/Female): ";
        getline(cin, gender);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
    }

    string toString() const {
        stringstream ss;
        ss << "Doctor ID: " << id << ", Name: " << name 
           << ", Age: " << age << ", Gender: " << gender 
           << ", Specialization: " << specialization;
        return ss.str();
    }
};

class Appointment {
public:
    int id;
    int patientId;
    int doctorId;
    string date;

    void input(const vector<Doctor>& doctors) {
        cout << "Enter Appointment ID: ";
        cin >> id;

        cout << "Enter Patient ID: ";
        cin >> patientId;

        cout << "\nDo you want to search doctors by specialization? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        vector<Doctor> filteredDoctors = doctors;
        if (choice == 'y' || choice == 'Y') {
            string spec;
            cout << "Enter specialization to search: ";
            getline(cin, spec);

            filteredDoctors.clear();
            for (const auto& d : doctors) {
                if (d.specialization == spec) {
                    filteredDoctors.push_back(d);
                }
            }

            if (filteredDoctors.empty()) {
                cout << "No doctors found with specialization: " << spec << endl;
                return;
            }
        }

        cout << "\nAvailable Doctors:\n";
        for (const auto& d : filteredDoctors) {
            cout << d.toString() << endl;
        }

        cout << "\nChoose Doctor by ID: ";
        cin >> doctorId;

        cout << "Enter Appointment Date (dd-mm-yyyy): ";
        cin.ignore();
        getline(cin, date);
    }

    string toString() const {
        stringstream ss;
        ss << "Appointment ID: " << id << ", Patient ID: " << patientId 
           << ", Doctor ID: " << doctorId << ", Date: " << date;
        return ss.str();
    }
};

vector<Patient> patients;
vector<Doctor> doctors;
vector<Appointment> appointments;

void saveToFile(const string& filename, const vector<string>& data) {
    ofstream file(filename, ios::app); // append instead of overwrite
    for (const auto& line : data) {
        file << line << endl;
    }
    file.close();
    cout << "Data saved to " << filename << " successfully!\n";
}

void clearFile(const string& filename) {
    string password;
    cout << "Enter admin password to clear file: ";
    cin >> password;

    if (password == "admin123") {  // you can change the password here
        ofstream file(filename, ios::trunc); 
        file.close();
        cout << filename << " has been cleared successfully!\n";
    } else {
        cout << "Access Denied! Wrong password.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Book Appointment\n";
        cout << "4. Show Patients\n";
        cout << "5. Show Doctors\n";
        cout << "6. Show Appointments\n";
        cout << "7. Save Patients to File\n";
        cout << "8. Save Doctors to File\n";
        cout << "9. Save Appointments to File\n";
        cout << "10. Clear Data Files (Password Protected)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.input();
            patients.push_back(p);
        } 
        else if (choice == 2) {
            Doctor d;
            d.input();
            doctors.push_back(d);
        } 
        else if (choice == 3) {
            if (patients.empty() || doctors.empty()) {
                cout << "Please add both Patients and Doctors first.\n";
            } else {
                Appointment a;
                a.input(doctors);
                if (!a.date.empty()) appointments.push_back(a);
            }
        } 
        else if (choice == 4) {
            for (const auto& p : patients) cout << p.toString() << endl;
        } 
        else if (choice == 5) {
            for (const auto& d : doctors) cout << d.toString() << endl;
        } 
        else if (choice == 6) {
            for (const auto& a : appointments) cout << a.toString() << endl;
        } 
        else if (choice == 7) {
            vector<string> data;
            for (const auto& p : patients) data.push_back(p.toString());
            saveToFile("patients.txt", data);
        } 
        else if (choice == 8) {
            vector<string> data;
            for (const auto& d : doctors) data.push_back(d.toString());
            saveToFile("doctors.txt", data);
        } 
        else if (choice == 9) {
            vector<string> data;
            for (const auto& a : appointments) data.push_back(a.toString());
            saveToFile("appointments.txt", data);
        }
        else if (choice == 10) {
            int opt;
            cout << "\nWhich file do you want to clear?\n";
            cout << "1. Patients File\n";
            cout << "2. Doctors File\n";
            cout << "3. Appointments File\n";
            cout << "Enter option: ";
            cin >> opt;

            if (opt == 1) clearFile("patients.txt");
            else if (opt == 2) clearFile("doctors.txt");
            else if (opt == 3) clearFile("appointments.txt");
            else cout << "Invalid option!\n";
        }
    } while (choice != 0);

    

    return 0;
}
