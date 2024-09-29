#include "DiamondAccountCreate.h"
#include "../InputValidation/InputValidationPassword.h"
#include <iostream>
DiamondAccountCreate::DiamondAccountCreate()
{
    name = "Diamond Account Create form";
}

void DiamondAccountCreate::Initialize()
{
    FormQuestion question;
    question.Set<std::string>("Email","");
    formData.emplace("email",question);
    question.Set<std::string>("Name","");
    formData.emplace("name",question);

    question.AddValidationRule(new InputValidationPassword());
    question.Set<std::string>("Password","");
    formData.emplace("pass",question);

    question.Set<std::string>("Confirm Password","");
    formData.emplace("confirmPass",question);
}
void DiamondAccountCreate::Content(){
    int num = 1;
    for(auto& kv : formData){
    cout << "Here" << endl;
        cout << num << ". " << kv.second.GetQuestion() << ":\t";
        kv.second.GetInput();
        num++;
    }
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

void DiamondAccountCreate::ProcessInput()
{
    AccountInfo newUser;
    
    newUser.Email = formData["email"].GetResponse<string>();
    if(CheckIfExisting(newUser.Email)){
        Log("An account with that email already exists. Try logging in.",true);
        Hide();
        return;
    }

    newUser.Name = formData["name"].GetResponse<string>();

    std::string pass = "",confirmPass = "";
    pass = formData["pass"].GetResponse<string>();
    confirmPass = formData["confirmPass"].GetResponse<string>();
    
    if(!CheckIfValidPassword(pass,confirmPass)){
        Log("Invalid password or pass and confirm password is not the same. Try making it longer or same.",true);
        return;
    }

    if(Create(newUser,pass)){
        Log("User account created successfully. Please sign in.");
        Hide();
    }
    else{
        Log("Unable to create user account. Try again.", true);
    }
}
