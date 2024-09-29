#include "DiamondAccountDeposit.h"
#include <iostream>
#include "../Utility/TextHelper.h"
#include "../InputValidation/InputValidationNumber.h"

DiamondAccountDeposit::DiamondAccountDeposit()
{
    name = "Diamond Bank > Account Deposit";
}

void DiamondAccountDeposit::Initialize()
{
    ClearFormData();
    
    name = GetBank()->GetSectionBanner("Account Deposit");

    FormQuestion question;
    question.Set<float>("How much do you want to deposit",0.f);
    question.AddValidationRule(new InputValidationNumber());
    formData.emplace("deposit",question);
}
void DiamondAccountDeposit::Content()
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

bool DiamondAccountDeposit::CheckIfCanDeposit(float amount)
{// we can add limit to how much one can deposit here
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

void DiamondAccountDeposit::ProcessInput()
{
    float toDeposit = formData["deposit"].GetResponse<float>();
    
    if(toDeposit < 0) { Log("Invalid input", true); return; }

    if(Deposit(toDeposit)){
        Log("You deposited " + TextHelper::FixedFloat(toDeposit) + " diamond(s).");
        
        AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
        float diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
        diamonds = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
        Log("You now have a total of " + TextHelper::FixedFloat(diamonds) + " diamond(s) left in the bank.");
    }
    else{
        Log("Unable to deposit at this time. Try again later.",true);
    }
    Hide();
}