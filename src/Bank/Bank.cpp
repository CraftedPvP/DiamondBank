#include "Bank.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

void Bank::Menu(){
    int choice = 0;
    do{
        cout << "=======================" << endl;
        cout << "\tWelcome to " << name << endl;
        cout << "=======================" << endl << endl;
        string actions[] = {
            "Create New Account", // 1
            "Log In to an Existing Account",
            "Check Account Balance",
            "Deposit Diamonds to Account",
            "Withdraw Diamonds from Account", // 5
            "Close Account",
            "Quit",
        };
        for (size_t i = 1; i < 8; i++)
            cout << "\t" << i << ". " << actions[i] << endl;

        cout << "Action 1-7: ";
        cin >> choice;

        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                cerr << "invalid input. enter a number between 1-7" << endl;
        }
    }
    while(choice != 7);
}