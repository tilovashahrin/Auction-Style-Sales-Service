#include <iostream>
#include <iomanip>
#include "AccountManager.h"
#include "UserActivity.h"
using namespace std;

int main() {
    char selection;
    string username;
    bool menu = true;// keep menu running
    int errorCode;

    AccountManager user; // Regular use
    //AccountManager user(true, "AA", "user_1", 1000.00f); // Testing purpose
    cout << setprecision(2) << fixed;

    while (menu) {
        
        cout << "\n Menu";

        cout << "\n========";
        if (user.getLogStatus()) {
            cout << "\n Current User: " << user.getUsername()
                    << "\n User Funds: $" << user.getCredits()
                    << "\n User Type: " << user.getUserType()
                    << "\n========";
        }
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
                errorCode = user.login(username);
                if (errorCode == 0) {
                    cout << "Success! "<< user.getUsername() << " is now logged in.\n";
                }
                else if (errorCode == 1) {
                    cout<< "ERROR: Cannot log in, "<< user.getUsername() << " is already logged in.\n";
                }
                else if (errorCode == 2) {
                    cout << "ERROR: Cannot log in, " << username << " was not found.\n";
                }
                else{
                    cout << user.getUsername() << " is logged in.\n";
                }

                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'O':
        case 'o': {cout << "\n - Log out of account -\n";}
                errorCode = user.logout();
                if (errorCode == 0) {
                    cout << "Success! User is now logged out.\n";
                }
                else if (errorCode == 1) {
                    cout << "ERROR: User is already logged out.\n";
                }
                else {
                    cout << "User is now logged out\n";
                }

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
                user.advertise();// Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'B':
        case 'b': {cout << "\n - Bid on an item for auction -\n";}
                user.bid(user_type);// Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'R':
        case 'r': {cout << "\n - Refund credit to a buyer’s account from a seller’s account -\n";}
                user.refund();// Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'F':
        case 'f': {cout << "\n Add credit into the system\n";}
                user.addCredit(1000.00f);
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'X':
        case 'x': {cout << "\n To exit the menu";}
                user.logout();
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
