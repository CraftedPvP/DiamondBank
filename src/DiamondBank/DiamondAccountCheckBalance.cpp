#include "DiamondAccountCheckBalance.h"
#include <functional>
#include "../Utility/TextHelper.h"

DiamondAccountCheckBalance::DiamondAccountCheckBalance()
{
    menu.name = "Diamond Account Balance";
    std::string actions[] = {
        "Check Balance",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
    menu.SetChooseCallback(std::bind(&DiamondAccountCheckBalance::OnChoose,this,std::placeholders::_1));
}

void DiamondAccountCheckBalance::ShowBalance()
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        menu.Log("You have to be signed in to do this action", true);
        return;
    }
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float amountStored = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    menu.Log("You have " + TextHelper::FixedFloat(amountStored) + " diamond(s).");
}

void DiamondAccountCheckBalance::OnChoose(int choice)
{
    if(choice == 1){
        ShowBalance();
    }
}
