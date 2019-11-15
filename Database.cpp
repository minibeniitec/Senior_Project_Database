/*  	Source: 	Database.cpp
 *	Author:		Benjamin A Garza III
 *	Date:		Nov 12, 2019
 *	Class:		CMPS 4910 - Senior Seminar I
 *	Purpose: 	Easy dba creation/termination access via terminal.
 *
 *  Compile:
 *      g++ Database.cpp -o Database
 */

#include <iostream>
using namespace std;

void printMenu() {
    cout << "\n\nMenu:\n";
    cout << " 1. Create user and tablespaces\n";
    cout << " 2. Create all tables\n";
    cout << " 3. Insert default tuples\n";
    cout << " 4. Drop all tables\n";
    cout << " 5. Drope user and tablesapces\n";
    cout << " 6. Query All into file\n";
    cout << "Easy Menu:\n";
    cout << " 7. Run Setup\n";
    cout << " 8. Insert Default Data\n";
    cout << " 9. Drop entire database\n";
    cout << "10. Quit\n";
    cout << "Choice: ";
    return;
}

int getChoice() {
    int choice;
    while (!(cin >> choice)) {
        // Explain error
        cout << "ERROR: a number must be entered: ";
        // Clear input stream
        cin.clear();
        // Discard previous input
        cin.ignore(132, '\n');
    }
    return choice;
}

int main() {
    int choice = 0;
    do {
        switch (choice) {
            case 1: 
                cout << "Creating User and Tablespaces:\n";
                system("psql -f Create_User_Tablespaces.psql");
                break;
            case 2:
                cout << "Creating Tables:\n";
                system("psql -f Create_Tables.psql restaurant  groupzero");
                break;
            case 3:
	    case 8:
                cout << "Inserting defualt tuples into all tables:\n";
                system("psql -f Insert_All.psql restaurant groupzero");
                break;
            case 4:
                cout << "Dropping all tables:\n";
                system("psql -f Drop_Tables.psql restaurant groupzero");
                break;
            case 5:
                cout << "Droping User and Tablespaces\n";
                system("psql -f Drop_User_Tablespaces.psql restaurant groupzero");
                break;
            case 6:
                cout << "Querying:\n";
                system("psql -f Query_All.psql restaurant groupzero");
                break;
	    case 7:
                cout << "Setting Up Database:\n";
                system("psql -f Create_User_Tablespaces.psql");
                system("psql -f Create_Tables.psql restaurant  groupzero");
                break;
            case 9:
		cout << "Destroying database...\n";
                system("psql -f Drop_Tables.psql restaurant groupzero");
                system("psql -f Drop_User_Tablespaces.psql restaurant groupzero");
            default:
                cout << "Error: Please enter a valid option.";
        }
        printMenu();
        choice = getChoice();
    } while (choice != 10);

    return 0;
}