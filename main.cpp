#include <iostream>
#include <vector>

using namespace std;

class User {
public:
    int id;
    string name;

    User(int i, string n) {
        id = i;
        name = n;
    }
};

vector<User> users;
int nextId = 1;

void showMenu() {
    cout << "\n===== USER MANAGEMENT SYSTEM =====\n";
    cout << "1. Add User\n";
    cout << "2. List Users\n";
    cout << "3. Delete User\n";
    cout << "4. Exit\n";
    cout << "Select an option: ";
}

void addUser(vector<User>& users, int& nextId) {
    string name;

    cout << "Enter name: ";
    cin >> name;

    users.push_back(User(nextId, name));
    cout << "User added with ID: " << nextId << endl;

    nextId++;
}

void listUsers(vector<User>& users) {
    if (users.empty()) {
        cout << "No users found.\n";
        return;
    }

    cout << "\n--- USER LIST ---\n";
    for (const auto& user : users) {
        cout << "ID: " << user.id << " | Name: " << user.name << endl;
    }
}

void deleteUser(vector<User>& users) {
    int id;

    cout << "Enter ID to delete: ";
    cin >> id;

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->id == id) {
            users.erase(it);
            cout << "User deleted.\n";
            return;
        }
    }

    cout << "User not found.\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addUser(users, nextId);
            break;

        case 2:
            listUsers(users);
            break;

        case 3:
            deleteUser(users);
            break;

        case 4:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid option!\n";
        }
    }

    return 0;
}