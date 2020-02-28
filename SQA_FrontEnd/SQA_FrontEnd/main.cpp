#include <iostream>
#include <iomanip>
#include <string>
#include "AccountManager.h"
using namespace std;

int main(int argc, char* argv[]) {
    char selection;
    string username;
    bool menu = true;// keep menu running

    AccountManager user;
    if (argc == 4) {
        user = AccountManager(string(argv[1]), string(argv[2]), string(argv[3]));
    }
    else {
        user = AccountManager();
    }
  
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
                user.login(username);

                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'O':
        case 'o': {cout << "\n - Log out of account -\n";}
                user.logout();

                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'C':
        case 'c': {cout << "\n - Create a new user -\n";}
                user.createUser();// Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'D':
        case 'd': {cout << "\n - Remove users (this also cancels their sales) -\n";}
                user.deleteUser();
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'A':
        case 'a': {cout << "\n - Put up an item for auction -\n";}
                user.advertise();
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'B':
        case 'b': {cout << "\n - Bid on an item for auction -\n";}
                user.bid();
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'R':
        case 'r': {cout << "\n - Refund credit to a buyer’s account from a seller’s account -\n";}
                user.refund();
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'F':
        case 'f': {cout << "\n Add credit into the system\n";}
                user.addCredit();
                // Function Call Here
                system("pause"); // Waits for input
                system("CLS"); // Clears console
                break;
        case 'X':
        case 'x': {cout << "\n To exit the menu\n ";}
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
