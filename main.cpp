#include <iostream>
#include <vector>

using namespace std;

class User {
private:
    int id;
    string name;
    string email;

public:
    User(int userId, string userName, string userEmail) {
        id = userId;
        name = userName;
        email = userEmail;
    }

    void display() {
        cout << "ID: " << id
            << " | Name: " << name
            << " | Email: " << email << endl;
    }
};

vector<User> users;

void showMenu() {
    cout << "\n===== USER MANAGEMENT SYSTEM =====\n";
    cout << "1. Add User\n";
    cout << "2. List Users\n";
    cout << "3. Exit\n";
    cout << "Select option: ";
}

void addUser() {
    int id;
    string name, email;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Email: ";
    cin >> email;

    users.push_back(User(id, name, email));

    cout << "User added successfully!\n";
}

void listUsers() {
    if (users.empty()) {
        cout << "No users found.\n";
        return;
    }

    for (User u : users) {
        u.display();
    }
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addUser();
            break;

        case 2:
            listUsers();
            break;

        case 3:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid option!\n";
        }
    }
}