#include "DiamondAccountWithdraw.h"
#include <iostream>
#include "../Utility/TextHelper.h"

DiamondAccountWithdraw::DiamondAccountWithdraw()
{
    name = "Diamond Bank > Account Withdrawal";
}

void DiamondAccountWithdraw::SetTransactionFee(float transactionFee)
{
    this->transactionFee = transactionFee;
}

bool DiamondAccountWithdraw::CheckIfCanWithdraw(float toWidthraw)
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        Log("You have to be signed in to do this action", true);
        return false;
    }
    
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float amountStored = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    if(amountStored < toWidthraw){
        float missing = std::abs(amountStored - toWidthraw);
        Log("You lack funds to withdraw " + TextHelper::FixedFloat(toWidthraw) + " diamond(s). You still need " + TextHelper::FixedFloat(missing) + " diamond(s).", true);
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

void DiamondAccountWithdraw::Initialize()
{
    ClearFormData();
    
    name = GetBank()->GetSectionBanner("Account Withdrawal");

    FormQuestion question;
    question.Set<float>("How much would you want to withdraw",0.f);
    formData.emplace("withdraw",question);
}

void DiamondAccountWithdraw::Content()
{
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    Log("You currently have " + TextHelper::FixedFloat(diamonds) + " diamond(s).");

    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << ":\t";
        kv.second.GetInput();
        num++;
    }
}

void DiamondAccountWithdraw::ProcessInput()
{
    float toWithdraw = formData["withdraw"].GetResponse<float>();
    
    if(toWithdraw < 0) { Log("Invalid input", true); return; }

    if(Withdraw(toWithdraw)){
        Log("You withdrew " + TextHelper::FixedFloat(toWithdraw) + " diamond(s).");
        AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
        float diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
        Log("You now have a total of " + TextHelper::FixedFloat(diamonds) + " diamond(s) left in the bank.");
    }
    else{
        Log("Unable to withdraw at this time. Try again later.",true);
    }
    Hide();
}