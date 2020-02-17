#include <iostream>
#include "AccountManager.h"
#include "UserActivity.h"

using namespace std;


int main() {
    char selection;
    string username;
    bool menu = true;// keep menu running

    //AccountManager user; // Regular use
    AccountManager user(true, 'AA', "user_1");// Testing purpose
    

    while (menu) {
        cout << "\n Menu";

        cout << "\n========";

        cout << "\n I - Log In";

        cout << "\n O - Log Out";

        cout << "\n D - Delete";

        cout << "\n X - Exit";

        cout << "\n Enter selection: ";

        // read the input

        cin >> selection;

        switch (selection) {
        case 'I':
        case 'i': {cout << "\nLog In to account\n";}
                cout << "\nEnter Username\n";
                cin >> username;
                user.login(username);
                cout << user.getUsername() << " is logged in.";
                break;
        case 'O':
        case 'o': {cout << "\n Logging out";}
                user.logout();
                cout << "User is now logged out";
                break;
        case 'D':
        case 'd': {cout << "\n To delete a record";}
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
