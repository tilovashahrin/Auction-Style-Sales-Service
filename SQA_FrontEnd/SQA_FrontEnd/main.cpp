#include <iostream>
#include "AccountManager.h"
#include "UserActivity.h"
using namespace std;

int main() {
    char selection;
    string username;
    bool menu = true;// keep menu running

    //AccountManager user; // Regular use
    AccountManager user(true, 'AA', "user_1"); // Testing purpose
    
    while (menu) {
        cout << "\n Menu";

        cout << "\n========";

        cout << "\n I - Log In";

        cout << "\n O - Log Out";

        cout << "\n C - Create (Admin Only)";

        cout << "\n D - Delete (Admin Only)";

        cout << "\n A - Advertise";

        cout << "\n B - Bid";

        cout << "\n R - Refund (Admin Only)";

        // already had A and C in the menu, so I used "funds" instead of "credits"
        cout << "\n F - Add Funds"; 

        cout << "\n X - Exit";

        cout << "\n Enter selection: ";

        // read the input

        cin >> selection;

        switch (selection) {
        case 'I':
        case 'i': {cout << "\n - Log In to account -\n";}
                cout << "Enter Username: ";
                cin >> username;
                user.login(username);
                cout << user.getUsername() << " is logged in.\n";

                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'O':
        case 'o': {cout << "\n - Log out of account -\n";}
                user.logout();
                cout << "User is now logged out\n";

                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'C':
        case 'c': {cout << "\n - Create a new user -\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'D':
        case 'd': {cout << "\n - Cancel any items for sale and remove users -\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'A':
        case 'a': {cout << "\n - Put up an item for auction -\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'B':
        case 'b': {cout << "\n - Bid on an item for auction -\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'R':
        case 'r': {cout << "\n - Refund credit to a buyer’s account from a seller’s account -\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'F':
        case 'f': {cout << "\n Add credit into the system\n";}
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'X':
        case 'x': {cout << "\n To exit the menu";}
                if (!user.getLogStatus()) {
                    user.logout();
                }
                menu = false;
                break;
                // other than A, M, D and X...
        default: cout << "\n Invalid selection";
            // no break in the default case
        }
        cout << "\n";
    }
    return 0;
}
