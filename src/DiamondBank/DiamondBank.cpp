#include "DiamondBank.h"

#include "DiamondAccountDatabase.h"
#include "DiamondAccountCreate.h"
#include "DiamondAccountLogin.h"
#include "DiamondAccountCheckBalance.h"
#include "DiamondAccountDeposit.h"
#include "DiamondAccountWithdraw.h"
#include "DiamondAccountClose.h"
DiamondBank::DiamondBank()
{
    name = "Diamond Bank";

    accountDatabase = new DiamondAccountDatabase();
    accountCreate = new DiamondAccountCreate();
    accountLogin = new DiamondAccountLogin();
    accountCheckBalance = new DiamondAccountCheckBalance();
    accountDeposit = new DiamondAccountDeposit();
    accountWithdraw = new DiamondAccountWithdraw();
    accountClose = new DiamondAccountClose();
}

void DiamondBank::Initialize(){
    ((DiamondAccountCreate*)accountCreate)->SetBank(this);
    ((DiamondAccountLogin*)accountLogin)->SetBank(this);
    ((DiamondAccountCheckBalance*)accountCheckBalance)->SetBank(this);
    ((DiamondAccountDeposit*)accountDeposit)->SetBank(this);
    ((DiamondAccountWithdraw*)accountWithdraw)->SetBank(this);
    ((DiamondAccountClose*)accountClose)->SetBank(this);

    login.name = "Diamond Bank Login";
    std::string actions[] = {
        "Login",
        "Create an account",
        "Quit"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    login.SetActions(actions,size);
    login.SetChooseCallback(std::bind(&DiamondBank::OnChoose_Login,this,std::placeholders::_1));

    signedIn.name = "Diamond Bank Homepage";
    std::string actions2[] = {
        "Check Balance",
        "Deposit Diamonds",
        "Withdraw Diamonds",
        "Close the account",
        "Quit"
    };
    size = sizeof(actions2)/sizeof(actions2[0]);
    signedIn.SetActions(actions2,size);
    signedIn.SetChooseCallback(std::bind(&DiamondBank::OnChoose_SignedIn,this,std::placeholders::_1));
}
void DiamondBank::LaunchUI()
{
    bool justQuit = true;
    do{
        login.Show();
        justQuit = !accountLogin->IsLoggedIn(); 
        if(accountLogin->IsLoggedIn()) signedIn.Show();
    }
    while(justQuit);
}

void DiamondBank::OnChoose_Login(int choice)
{
    if(choice == 1) ((DiamondAccountLogin*)accountLogin)->ShowMenu();
    else if(choice == 2) ((DiamondAccountCreate*)accountCreate)->ShowMenu();
}
void DiamondBank::OnChoose_SignedIn(int choice)
{
    switch(choice){
        case 1:
            ((DiamondAccountCheckBalance*)accountCheckBalance)->ShowMenu();
            break;
        case 2:
            ((DiamondAccountDeposit*)accountDeposit)->ShowMenu();
            break;
        case 3:
            ((DiamondAccountWithdraw*)accountWithdraw)->ShowMenu();
            break;
        case 4:
            ((DiamondAccountClose*)accountClose)->ShowMenu();
            break;
    }
}