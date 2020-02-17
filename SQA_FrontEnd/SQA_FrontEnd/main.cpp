#include <iostream>
#include "AccountManager.h"
#include "UserActivity.h"

using namespace std;


int main() {
    char selection;
    string username;
    AccountManager user;
    


    cout << "\n Menu";

    cout << "\n========";

    cout << "\n I - Log In";

    cout << "\n M - Modify";

    cout << "\n D - Delete";

    cout << "\n X - Exit";

    cout << "\n Enter selection: ";

    // read the input

    cin >> selection;



    switch (selection){
    case 'I':
    case 'i': {cout << "\nLog In to account\n";}
            cout << "\nEnter Username\n";
            cin >> username;
            user.login(username);
            cout<< user.getUsername()<< " is logged in.";
            break;
    case 'M':
    case 'm': {cout << "\n To modify a record";}
            break;
    case 'D':
    case 'd': {cout << "\n To delete a record";}
            break;
    case 'X':
    case 'x': {cout << "\n To exit the menu";}
            break;
            // other than A, M, D and X...
    default: cout << "\n Invalid selection";
        // no break in the default case
    }
    cout << "\n";
    return 0;
}
