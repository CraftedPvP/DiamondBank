#include "DiamondAccountClose.h"
#include <iostream>
DiamondAccountClose::DiamondAccountClose()
{
    menu.name = "Diamond Account Closing form";
    std::string actions[] = {
        "Close account",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
}

bool DiamondAccountClose::Close()
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        menu.Log("You have to be signed in to do this action", true);
        return false;
    }

    std::string email = GetBank()->GetAccountLogin()->GetUser().Email;
    menu.Log("Do you want to close this \"" + email + "\" account?");
    menu.Log("Input (Y)es or (N)o: ");
    
    char choice;
    std::cin >> choice;
    if(choice != 'Y' && choice != 'y') return false;

    GetBank()->GetAccountDatabase()->DeleteAccount(email);
    return true; 
}

void DiamondAccountClose::OnChoose(int choice)
{
    if(choice == 1){
        Close();
    }
}
