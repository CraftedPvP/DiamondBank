#include "DiamondAccountDeposit.h"

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

void DiamondAccountDeposit::SetTransactionFee(float depositFee)
{
    transactionFee = std::min(depositFee,1.0f);
}


void DiamondAccountDeposit::OnChoose(int choice)
{
}
