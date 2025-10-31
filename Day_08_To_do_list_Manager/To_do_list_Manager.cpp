// #include <iostream>
// #include <vector>
// #include <fstream>
// using namespace std;

// struct Task {
//     string name;
//     bool done;
// };

// vector<Task> tasks;

// void loadTasks() {
//     ifstream file("tasks.txt");
//     Task t;
//     while (file >> t.done) {
//         file.ignore();
//         getline(file, t.name);
//         tasks.push_back(t);
//     }
//     file.close();
// }

// void saveTasks() {
//     ofstream file("tasks.txt");
//     for (auto &t : tasks) {
//         file << t.done << " " << t.name << endl;
//     }
//     file.close();
// }

// void addTask() {
//     Task t;
//     cout << "Enter task name: ";
//     cin.ignore();
//     getline(cin, t.name);
//     t.done = false;
//     tasks.push_back(t);
//     saveTasks();
//     cout << "Task added successfully!\n";
// }

// void viewTasks() {
//     if (tasks.empty()) {
//         cout << "No tasks found.\n";
//         return;
//     }
//     cout << "\nYour Tasks:\n";
//     for (int i = 0; i < tasks.size(); i++) {
//         cout << i + 1 << ". " << tasks[i].name
//              << (tasks[i].done ? " [Done]" : " [Pending]") << endl;
//     }
// }

// void markDone() {
//     viewTasks();
//     int n;
//     cout << "\nEnter task number to mark as done: ";
//     cin >> n;
//     if (n > 0 && n <= tasks.size()) {
//         tasks[n - 1].done = true;
//         saveTasks();
//         cout << "Task marked as done!\n";
//     } else {
//         cout << "Invalid task number.\n";
//     }
// }

// void deleteTask() {
//     viewTasks();
//     int n;
//     cout << "\nEnter task number to delete: ";
//     cin >> n;
//     if (n > 0 && n <= tasks.size()) {
//         tasks.erase(tasks.begin() + (n - 1));
//         saveTasks();
//         cout << "Task deleted successfully!\n";
//     } else {
//         cout << "Invalid task number.\n";
//     }
// }

// int main() {
//     loadTasks();
//     int choice;
//     do {
//         cout << "\n=== To-Do List Manager ===\n";
//         cout << "1. Add Task\n2. View Tasks\n3. Mark as Done\n4. Delete Task\n5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: addTask(); break;
//             case 2: viewTasks(); break;
//             case 3: markDone(); break;
//             case 4: deleteTask(); break;
//             case 5: saveTasks(); cout << "Exiting...\n"; break;
//             default: cout << "Invalid choice.\n";
//         }
//     } while (choice != 5);
//     return 0;
// }




                                  // simplified version 






#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    bool done;
};

Task tasks[100];
int totalTasks = 0;

void addTask() {
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, tasks[totalTasks].name);
    tasks[totalTasks].done = false;
    totalTasks++;
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (totalTasks == 0) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < totalTasks; i++) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].done)
            cout << " [Done]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}

void markDone() {
    viewTasks();
    int n;
    cout << "\nEnter task number to mark as done: ";
    cin >> n;

    if (n > 0 && n <= totalTasks) {
        tasks[n - 1].done = true;
        cout << "Task marked as done!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    viewTasks();
    int n;
    cout << "\nEnter task number to delete: ";
    cin >> n;

    if (n > 0 && n <= totalTasks) {
        for (int i = n - 1; i < totalTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        totalTasks--;
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n=== To-Do List Manager ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markDone();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
