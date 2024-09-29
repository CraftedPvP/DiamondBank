#include "DiamondAccountLogin.h"
#include <iostream>

DiamondAccountLogin::DiamondAccountLogin()
{
    name = "Diamond Account Login";
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
        Log("Invalid account credentials. Please check your email or password", true);
    }

    currentUser = user;
    return IsLoggedIn();
}

bool DiamondAccountLogin::IsLoggedIn() { return currentUser.Email != ""; }

void DiamondAccountLogin::Logout()
{
    // clear it in-case it gets read afterwards
    currentUser.Email = "";
    currentUser.Name = "";

    Log("Logged out");

    if(onLogoutSuccess) onLogoutSuccess();
}

void DiamondAccountLogin::Initialize()
{
    FormQuestion question;
    question.Set<std::string>("Email","");
    formData.emplace("email",question);
    question.Set<std::string>("Password","");
    formData.emplace("pass",question);
}

void DiamondAccountLogin::Content()
{
    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << ":\t";
        kv.second.GetInput();
        num++;
    }
}


void DiamondAccountLogin::SetOnLoginSuccess(OnLoginSuccess callback) { onLoginSuccess = callback; }

void DiamondAccountLogin::SetOnLogoutSuccess(OnLogoutSuccess callback){ onLogoutSuccess = callback; }

void DiamondAccountLogin::ProcessInput()
{
    std::string email = formData["email"].GetResponse<string>();
    std::string pass = formData["pass"].GetResponse<string>();

    if(Login(email,pass)){
        Log("Login success");
        Hide();
        Pause();
        if(onLoginSuccess) onLoginSuccess(currentUser);
    }
}
