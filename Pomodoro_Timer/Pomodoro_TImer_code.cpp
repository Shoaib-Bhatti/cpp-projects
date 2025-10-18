// Portable Pomodoro Timer (Windows + Linux/Mac)
// Copy this into Pomodoro.cpp and compile.
// Linux / macOS:  g++ Pomodoro.cpp -o pomodoro
// Windows (MinGW-w64): g++ Pomodoro.cpp -o pomodoro.exe -std=c++11

#include <iostream>
#include <iomanip>
#include <cstdlib>

#ifdef _WIN32
  #include <windows.h> // Sleep(ms)
#else
  #include <unistd.h>  // sleep(s)
#endif

using namespace std;

void sleep_seconds(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

void countdown_minutes_seconds(int minutes) {
    for (int m = minutes - 1; m >= 0; --m) {
        for (int s = 59; s >= 0; --s) {
            // print mm:ss with leading zeros, carriage return to overwrite line
            cout << '\r' << "Time Left: "
                 << (m < 10 ? "0" : "") << m << ":"
                 << (s < 10 ? "0" : "") << s << " " << flush;
            sleep_seconds(1);
        }
    }
    cout << "\rTime Left: 00:00" << endl;
}

int main() {
    cout << "==============================\n";
    cout << "     POMODORO TIMER SYSTEM\n";
    cout << "==============================\n\n";

    int workMinutes = 25;
    int shortBreak = 5;
    int longBreak = 15;
    int rounds = 4;

    cout << "Enter work session duration in minutes (default 25): ";
    if (!(cin >> workMinutes)) return 0;
    cout << "Enter short break duration in minutes (default 5): ";
    if (!(cin >> shortBreak)) return 0;
    cout << "Enter long break duration in minutes (default 15): ";
    if (!(cin >> longBreak)) return 0;
    cout << "Enter number of Pomodoro rounds (default 4): ";
    if (!(cin >> rounds)) return 0;

    cout << "\nLet's begin your focus journey!\n";

    for (int i = 1; i <= rounds; ++i) {
        cout << "\n==============================\n";
        cout << "Pomodoro Round " << i << " - Work Time!\n";
        cout << "==============================\n";
        countdown_minutes_seconds(workMinutes);
        cout << "Work session completed!\n";

        if (i == rounds) break; // finished all rounds

        if (i % 4 == 0) {
            cout << "\nTime for a long break (" << longBreak << " minutes)\n";
            countdown_minutes_seconds(longBreak);
        } else {
            cout << "\nTake a short break (" << shortBreak << " minutes)\n";
            countdown_minutes_seconds(shortBreak);
        }

        cout << "\nGet ready for the next round!\n";
    }

    cout << "\n Congratulations! You've completed all your Pomodoro sessions!\n";
    cout << "Stay consistent — great work!\n";
    cout << "==============================\n";
    return 0;
}
