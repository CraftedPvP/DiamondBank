#include "DiamondBank.h"

#include "DiamondAccountDatabase.h"
#include "DiamondAccountCreate.h"
#include "DiamondAccountLogin.h"
#include "DiamondAccountCheckBalance.h"
#include "DiamondAccountDeposit.h"
#include "DiamondAccountWithdraw.h"
#include "DiamondAccountClose.h"
#include <iostream>

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

    ((DiamondAccountCreate*)accountCreate)->Initialize();
    ((DiamondAccountLogin*)accountLogin)->Initialize();

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
        "Sign out",
        "Quit"
    };
    size = sizeof(actions2)/sizeof(actions2[0]);
    signedIn.SetActions(actions2,size);
    signedIn.SetChooseCallback(std::bind(&DiamondBank::OnChoose_SignedIn,this,std::placeholders::_1));

    ((DiamondAccountLogin*)accountLogin)->SetOnLoginSuccess(std::bind(&DiamondBank::OnLoginSuccess_Event,this,std::placeholders::_1));
    ((DiamondAccountLogin*)accountLogin)->SetOnLogoutSuccess(std::bind(&DiamondBank::OnLogoutSuccess_Event,this));
    ((DiamondAccountClose*)accountClose)->SetOnAccountCloseSuccess(std::bind(&DiamondBank::OnAccountCloseSuccess_Event,this));
}
void DiamondBank::LaunchUI()
{
    if(!GetAccountDatabase()->CanConnect()) {
        std::cerr << "Error: The program has to run beside the " << ((DiamondAccountDatabase*)accountDatabase)->GetDatabaseUrl() << ". ";
        std::cerr << "Check if you're running the program beside it."<< std::endl;
        #ifdef DEVHELP
        std::cerr << "\tBut I made convenience function to create a database to where you're calling this from for the sake of testing. You're welcome \\()/" << std::endl;
        std::cerr << "\tJust know that your database will change if you change the folder of where you're calling the executable from." << std::endl;
        login.Pause();
        if(!accountDatabase->CreateDatabase()) {
            login.Log("Unable to create database in the current directory. Exiting the program", true);
            login.Pause();
            return;
        }
        #else
        login.Pause();
        return;
        #endif
    }

    do{
        login.Show();
        wantsToContinue = accountLogin->IsLoggedIn(); 
        if(accountLogin->IsLoggedIn()) signedIn.Show();
    }
    while(wantsToContinue);
    
    login.Log("Closing");
}

void DiamondBank::OnChoose_Login(int choice)
{
    if(choice == 1) ((DiamondAccountLogin*)accountLogin)->Show();
    else if(choice == 2) ((DiamondAccountCreate*)accountCreate)->Show();
}
void DiamondBank::OnChoose_SignedIn(int choice)
{
    switch(choice){
        case 1:
            ((DiamondAccountCheckBalance*)accountCheckBalance)->Show();
            break;
        case 2:
            ((DiamondAccountDeposit*)accountDeposit)->Show();
            break;
        case 3:
            ((DiamondAccountWithdraw*)accountWithdraw)->Show();
            break;
        case 4:
            ((DiamondAccountClose*)accountClose)->Show();
            break;
        case 5:
            ((DiamondAccountLogin*)accountLogin)->Logout();
            break;
        case 6:
            ((DiamondAccountLogin*)accountLogin)->Logout();
            wantsToContinue = false;
            break;
    }
}
void DiamondBank::OnLoginSuccess_Event(AccountInfo user)
{
    // delay initialization until after sign in
    ((DiamondAccountDeposit*)accountDeposit)->Initialize();
    ((DiamondAccountWithdraw*)accountWithdraw)->Initialize();
    ((DiamondAccountClose*)accountClose)->Initialize();

    signedIn.name = GetSectionBanner("Homepage");

    login.Hide();
}

void DiamondBank::OnAccountCloseSuccess_Event()
{
    accountLogin->Logout();
    signedIn.Hide();
}
void DiamondBank::OnLogoutSuccess_Event()
{
    signedIn.Hide();
}

std::string DiamondBank::GetSectionBanner(std::string section)
{
    std::string content = "Diamond Bank";
    if(section.length() > 0) content +=" > "+ section;
    content += "\nYou are currently signed in as \"" + accountLogin->GetUser().Name + "\"";
    return content;
}
