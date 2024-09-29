#include "DiamondAccountCreate.h"
#include <iostream>
DiamondAccountCreate::DiamondAccountCreate()
{
    menu.name = "Diamond Account Create form";
    std::string actions[] = {
        "Create an account",
        // "Already have an account?",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
    menu.SetChooseCallback(std::bind(&DiamondAccountCreate::OnChoose,this,std::placeholders::_1));
}

bool DiamondAccountCreate::CheckIfExisting(std::string email)
{
    return GetBank()->GetAccountDatabase()->CheckIfUserExists(email);
}

bool DiamondAccountCreate::CheckIfValidPassword(std::string pass, std::string confirmPass)
{// add additional pass validation here
    return pass == confirmPass && pass.length() > 0;
}

bool DiamondAccountCreate::Create(AccountInfo user, std::string pass)
{
    return GetBank()->GetAccountDatabase()->CreateAccount(user,pass);
}

void DiamondAccountCreate::OnChoose(int choice)
{
    if(choice == 1){
        AskForNewCredentials();
    }
}

void DiamondAccountCreate::AskForNewCredentials()
{
    AccountInfo newUser;
    
    menu.Log("Email: ");
    std::cin >> newUser.Email;
    if(CheckIfExisting(newUser.Email)){
        menu.Log("An account with that email already exists. Try logging in.",true);
        return;
    }

    menu.Log("Name: ");
    std::cin >> newUser.Name;

    std::string pass = "",confirmPass = "";
    menu.Log("Password: ");
    std::cin >> pass;
    menu.Log("Password: ");
    std::cin >> confirmPass;
    
    if(CheckIfValidPassword(pass,confirmPass)){
        menu.Log("Invalid password or pass and confirm password is not the same. Try making it longer or same.",true);
        return;
    }

    if(Create(newUser,pass)){
        menu.Log("User account created successfully. Please sign in.");
        menu.Hide();
    }
    else{
        menu.Log("Unable to create user account. Try again.", true);
    }
}
