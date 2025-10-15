#include <iostream>
#include <string>
using namespace std;

int main() {
    string questions[5] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "Who wrote 'Romeo and Juliet'?",
        "What is 5 + 3?",
        "Which is the largest ocean?"
    };

    string options[5][4] = {
        {"A. London", "B. Paris", "C. Berlin", "D. Madrid"},
        {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
        {"A. Charles Dickens", "B. Mark Twain", "C. William Shakespeare", "D. George Orwell"},
        {"A. 6", "B. 7", "C. 8", "D. 9"},
        {"A. Atlantic", "B. Indian", "C. Pacific", "D. Arctic"}
    };

    char correctAnswers[5] = {'B', 'B', 'C', 'C', 'C'};

    int score = 0;
    char answer;

    cout << "Welcome to the Quiz Game!" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;

        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }

        cout << "Enter your answer (A/B/C/D): ";
        cin >> answer;

        // Convert to uppercase so 'a' and 'A' both work
        if (answer >= 'a' && answer <= 'z') {
            answer = answer - 32;
        }

        if (answer == correctAnswers[i]) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer is " << correctAnswers[i] << "." << endl;
        }
    }

    cout << "\nQuiz Finished!" << endl;
    cout << "Your Total Score: " << score << " out of 5" << endl;

    cout << "\nThanks for playing!" << endl;
    return 0;
}
