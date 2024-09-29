#include "DiamondAccountDeposit.h"
#include <iostream>

DiamondAccountDeposit::DiamondAccountDeposit()
{
    menu.name = "Diamond Account Deposit";
    std::string actions[] = {
        "Deposit",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
    menu.SetChooseCallback(std::bind(&DiamondAccountDeposit::OnChoose,this,std::placeholders::_1));
}

bool DiamondAccountDeposit::CheckIfCanDeposit(float amount)
{
    return true;
}

bool DiamondAccountDeposit::Deposit(float toDeposit)
{
    return GetBank()->GetAccountDatabase()->AddMoney(GetBank()->GetAccountLogin()->GetUser().Email,toDeposit);
}

void DiamondAccountDeposit::SetTransactionFee(float depositFee)
{
    transactionFee = std::min(depositFee,1.0f);
}


void DiamondAccountDeposit::OnChoose(int choice)
{
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    menu.Log("You currently have " + std::to_string(diamonds) + " diamond(s).");
    menu.Log("How much would you deposit?");

    float toDeposit = 0;
    std::cin >> toDeposit;
    
    if(toDeposit < 0) { menu.Log("Invalid input", true); return; }

    if(Deposit(toDeposit)){
        menu.Log("You deposited " + std::to_string(toDeposit) + " diamond(s).");
        diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
        menu.Log("You now have a total of " + std::to_string(diamonds) + " diamond(s) left in the bank.");
    }
    else{
        menu.Log("Unable to deposit at this time. Try again later.",true);
    }
}
