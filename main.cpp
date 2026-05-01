#include <iostream>
#include <vector>
#include <fstream>

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

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }

    void setName(string newName) {
        name = newName;
    }

    void setEmail(string newEmail) {
        email = newEmail;
    }

    void display() {
        cout << "ID: " << id
            << " | Name: " << name
            << " | Email: " << email << endl;
    }
};

vector<User> users;

// ---------------- FILE SYSTEM ----------------

void saveUsers() {
    ofstream file("users.txt");

    for (User& u : users) {
        file << u.getId() << " "
            << u.getName() << " "
            << u.getEmail() << endl;
    }

    file.close();
}

void loadUsers() {
    ifstream file("users.txt");

    if (!file.is_open()) return;

    int id;
    string name, email;

    while (file >> id >> name >> email) {
        users.push_back(User(id, name, email));
    }

    file.close();
}

// ---------------- CRUD ----------------

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

    cout << "User added!\n";
}

void listUsers() {
    if (users.empty()) {
        cout << "No users found.\n";
        return;
    }

    for (User& u : users) {
        u.display();
    }
}

void updateUser() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (User& u : users) {
        if (u.getId() == id) {
            string name, email;

            cout << "New name: ";
            cin >> name;

            cout << "New email: ";
            cin >> email;

            u.setName(name);
            u.setEmail(email);

            cout << "Updated!\n";
            return;
        }
    }

    cout << "User not found!\n";
}

void deleteUser() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == id) {
            users.erase(users.begin() + i);
            cout << "Deleted!\n";
            return;
        }
    }

    cout << "User not found!\n";
}

// ---------------- MENU ----------------

void showMenu() {
    cout << "\n===== USER SYSTEM =====\n";
    cout << "1. Add User\n";
    cout << "2. List Users\n";
    cout << "3. Update User\n";
    cout << "4. Delete User\n";
    cout << "5. Exit\n";
    cout << "Select: ";
}

// ---------------- MAIN ----------------

int main() {
    loadUsers(); // program açılırken veri yükle

    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addUser();
            saveUsers();
            break;

        case 2:
            listUsers();
            break;

        case 3:
            updateUser();
            saveUsers();
            break;

        case 4:
            deleteUser();
            saveUsers();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid option!\n";
        }
    }
}