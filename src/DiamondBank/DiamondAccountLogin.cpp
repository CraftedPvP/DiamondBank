#include "DiamondAccountLogin.h"
#include <iostream>

DiamondAccountLogin::DiamondAccountLogin()
{
    menu.name = "Diamond Account Login";
    std::string actions[] = {
        "Login",
        // "Create a new account",
        // "Forget Password",
        "Go back"
    };
    int size = sizeof(actions)/sizeof(actions[0]);
    menu.SetActions(actions,size);
    menu.SetChooseCallback(std::bind(&DiamondAccountLogin::OnChoose,this,std::placeholders::_1));
}

DiamondAccountLogin::~DiamondAccountLogin()
{
    Logout();
}

AccountInfo DiamondAccountLogin::GetUser() { return currentUser; }

bool DiamondAccountLogin::Login(std::string email, std::string pass)
{
    AccountInfo user = GetBank()->GetAccountDatabase()->Login(email,pass);
    if(user.Email == ""){
        menu.Log("Invalid account credentials. Please check your email or password", true);
    }

    currentUser = user;
    return IsLoggedIn();
}

bool DiamondAccountLogin::IsLoggedIn() { return currentUser.Email != ""; }

void DiamondAccountLogin::OnChoose(int choice)
{
    if(choice == 1){
        AskForLoginCredentials();
    }
}

void DiamondAccountLogin::Logout()
{
    // clear it in-case it gets read afterwards
    currentUser.Email = "";
    currentUser.Name = "";

    menu.Log("Logged out");

    if(onLogoutSuccess) onLogoutSuccess();
}

void DiamondAccountLogin::SetOnLoginSuccess(OnLoginSuccess callback) { onLoginSuccess = callback; }

void DiamondAccountLogin::SetOnLogoutSuccess(OnLogoutSuccess callback){ onLogoutSuccess = callback; }

void DiamondAccountLogin::AskForLoginCredentials()
{
    menu.Log("Email: ");
    std::string email;
    std::cin >> email;

    std::string pass = "";
    menu.Log("Password: ");
    std::cin >> pass;

    if(Login(email,pass)){
        menu.Log("Login success");
        menu.Hide();
        menu.Pause();
        if(onLoginSuccess) onLoginSuccess(currentUser);
    }
}
