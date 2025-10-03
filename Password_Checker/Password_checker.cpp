#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);

    int score = 0;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    // 1. Check length
    if (password.length() >= 8) {
        score++;
    }

    // 2. Loop through each character
    for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) hasUpper = true;
        else if (islower(password[i])) hasLower = true;
        else if (isdigit(password[i])) hasDigit = true;
        else hasSpecial = true;
    }

    // 3. Add score based on what password contains
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    // 4. Decide strength
    cout << "\nPassword Strength: ";
    if (score <= 2) cout << "Weak ❌";
    else if (score == 3 || score == 4) cout << "Medium ⚠️";
    else cout << "Strong ✅";

    return 0;
}
