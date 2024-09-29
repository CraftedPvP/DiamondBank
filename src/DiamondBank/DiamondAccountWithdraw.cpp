#include "DiamondAccountWithdraw.h"
#include <iostream>

DiamondAccountWithdraw::DiamondAccountWithdraw()
{
    menu.name = "Diamond Account Withdraw";
    std::string actions[] = {
        "Withdraw",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
    menu.SetChooseCallback(std::bind(&DiamondAccountWithdraw::OnChoose,this,std::placeholders::_1));
}

bool DiamondAccountWithdraw::CheckIfCanWithdraw(float toWidthraw)
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        menu.Log("You have to be signed in to do this action", true);
        return false;
    }
    
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float amountStored = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    if(amountStored < toWidthraw){
        float missing = amountStored - toWidthraw;
        menu.Log("You lack funds to withdraw " + std::to_string(toWidthraw) + " diamond(s). You still need " + std::to_string(missing) + " diamond(s).", true);
        return false;
    }

    return true;
}

bool DiamondAccountWithdraw::Withdraw(float toWidthraw)
{
    if(!CheckIfCanWithdraw(toWidthraw)) return false;
    
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float amountStored = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    return GetBank()->GetAccountDatabase()->AddMoney(user.Email, -toWidthraw);
}

void DiamondAccountWithdraw::OnChoose(int choice)
{
    if(choice == 1){
        AskForInput();
    }
}

void DiamondAccountWithdraw::AskForInput()
{
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    menu.Log("You currently have " + std::to_string(diamonds) + " diamond(s).");
    menu.Log("How much would you withdraw?");

    float toWithdraw = 0;
    std::cin >> toWithdraw;
    
    if(toWithdraw < 0) { menu.Log("Invalid input", true); return; }

    if(Withdraw(toWithdraw)){
        menu.Log("You withdrew " + std::to_string(toWithdraw) + " diamond(s).");
        diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
        menu.Log("You now have a total of " + std::to_string(diamonds) + " diamond(s) left in the bank.");
    }
    else{
        menu.Log("Unable to withdraw at this time. Try again later.",true);
    }
}