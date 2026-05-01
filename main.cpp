#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n===== USER MANAGEMENT SYSTEM =====\n";
    cout << "1. Add User\n";
    cout << "2. List Users\n";
    cout << "3. Delete User\n";
    cout << "4. Exit\n";
    cout << "Select an option: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Add User selected (not implemented yet)\n";
            break;

        case 2:
            cout << "List Users selected (not implemented yet)\n";
            break;

        case 3:
            cout << "Delete User selected (not implemented yet)\n";
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