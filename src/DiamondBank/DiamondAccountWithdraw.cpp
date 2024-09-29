#include "DiamondAccountWithdraw.h"

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

    return true;
}

void DiamondAccountWithdraw::OnChoose(int choice)
{
}
