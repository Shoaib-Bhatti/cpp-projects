#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double getGradePoint(double percentage) {
    if (percentage >= 85) return 4.0;
    else if (percentage >= 80) return 3.7;
    else if (percentage >= 75) return 3.3;
    else if (percentage >= 70) return 3.0;
    else if (percentage >= 65) return 2.7;
    else if (percentage >= 60) return 2.3;
    else if (percentage >= 55) return 2.0;
    else if (percentage >= 50) return 1.7;
    else return 0.0;
}

string getLetterGrade(double percentage) {
    if (percentage >= 85) return "A";
    else if (percentage >= 80) return "A-";
    else if (percentage >= 75) return "B+";
    else if (percentage >= 70) return "B";
    else if (percentage >= 65) return "B-";
    else if (percentage >= 60) return "C+";
    else if (percentage >= 55) return "C";
    else if (percentage >= 50) return "D";
    else return "F";
}

void calculateCGPA() {
    int semesters;
    cout << "\nEnter how many semesters you have completed: ";
    cin >> semesters;

    double sumGPA = 0;
    char know;
    cout << "Do you know your GPA for each semester? (y/n): ";
    cin >> know;

    if (know == 'n' || know == 'N') {
        cout << "\nPlease calculate your semester GPAs first before calculating CGPA.\n";
        cout << "You can come back to this program once you have them ready.\n";
        return;
    }

    for (int i = 1; i <= semesters; i++) {
        double gpa;
        cout << "Enter GPA of Semester " << i << ": ";
        cin >> gpa;
        sumGPA += gpa;
    }

    double cgpa = sumGPA / semesters;
    cout << fixed << setprecision(2);
    cout << "\n----------------------------------\n";
    cout << "Your overall CGPA is: " << cgpa << endl;
    cout << "----------------------------------\n";
}

int main() {
    cout << "========================================================================\n";
    cout << "                         GPA & CGPA CALCULATOR  \n";
    cout << "========================================================================\n";

    string choice;
    cout << "Do you want to calculate GPA or CGPA? (gpa/cgpa): ";
    cin >> choice;

    if (choice == "gpa" || choice == "GPA") {
        int subjects;
        cout << "\nEnter the number of subjects this semester: ";
        cin >> subjects;

        double totalGradePoints = 0, totalCreditHours = 0;

        for (int i = 1; i <= subjects; i++) {
            double obtained, total, creditHour;
            cout << "\nSubject " << i << ":\n";
            cout << "Enter credit hours: ";
            cin >> creditHour;

            cout << "Enter marks obtained: ";
            cin >> obtained;
            cout << "Enter total marks: ";
            cin >> total;

            double percentage = (obtained / total) * 100;
            double gradePoint = getGradePoint(percentage);
            string letterGrade = getLetterGrade(percentage);

            cout << fixed << setprecision(2);
            cout << "Percentage: " << percentage << "% | Grade: " << letterGrade
                 << " | Grade Point: " << gradePoint << endl;

            totalGradePoints += gradePoint * creditHour;
            totalCreditHours += creditHour;
        }

        if (totalCreditHours > 0) {
            double gpa = totalGradePoints / totalCreditHours;
            cout << fixed << setprecision(2);
            cout << "\n----------------------------------\n";
            cout << "Your GPA for this semester is: " << gpa << endl;
            cout << "----------------------------------\n";

            char choiceCGPA;
            cout << "\nDo you want to calculate your overall CGPA now? (y/n): ";
            cin >> choiceCGPA;

            if (choiceCGPA == 'y' || choiceCGPA == 'Y') {
                calculateCGPA();
            } else {
                cout << "\nYou chose not to calculate CGPA now.\n";
            }
        } else {
            cout << "\nInvalid input! Credit hours cannot be zero.\n";
        }
    }

    else if (choice == "cgpa" || choice == "CGPA") {
        calculateCGPA();
    }

    else {
        cout << "\nInvalid choice! Please type 'gpa' or 'cgpa'.\n";
    }

    cout << "\nThank you for using the GPA & CGPA Calculator!  \n";
    cout << "   Created by Shoaib Nazar         \n";
    cout << "=====================================\n";
    return 0;
}
