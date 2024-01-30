#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void add(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added\n";
}

void view(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks\n";
        return;
    }
    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " - ";
        if (tasks[i].completed)
            cout << "Completed";
        else
            cout << "Pending";
        cout << endl;
    }
}

void markAsCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void remove(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                add(tasks, description);
                break;
            }
            case 2:
                view(tasks);
                break;
            case 3: {
                size_t index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markAsCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                remove(tasks, index - 1);
                break;
            }
            case 5:
                cout << "bbye";
                return 0;
            default:
                cout << "Invalid\n";
        }
    }

    return 0;
}
