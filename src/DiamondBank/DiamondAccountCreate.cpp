#include "DiamondAccountCreate.h"
#include "../InputValidation/InputValidationPassword.h"
#include "../InputValidation/InputValidationRegexEmail.h"
#include <iostream>
DiamondAccountCreate::DiamondAccountCreate()
{
    name = "Diamond Bank > Account Creation";
}

void DiamondAccountCreate::Initialize()
{
    FormQuestion question;
    question.Set<std::string>("Email","");
    question.AddValidationRule(new InputValidationRegexEmail());
    formData.emplace("email",question);
    question.ClearValidationRules();

    question.Set<std::string>("Name","");
    formData.emplace("name",question);

    question.AddValidationRule(new InputValidationPassword());
    question.Set<std::string>("Password","");
    formData.emplace("pass",question);

    question.Set<std::string>("Confirm Password","");
    formData.emplace("passConfirm",question);
}
void DiamondAccountCreate::Content(){
    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << ":\t";
        kv.second.GetInput();
        num++;
    }
}

bool DiamondAccountCreate::CheckIfExisting(std::string email)
{
    return GetBank()->GetAccountDatabase()->CheckIfUserExists(email);
}

bool DiamondAccountCreate::CheckIfValidPassword(std::string pass, std::string passConfirm)
{// add additional pass validation here
    return pass == passConfirm && pass.length() > 0;
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

    std::string pass = formData["pass"].GetResponse<string>();
    std::string passConfirm = formData["passConfirm"].GetResponse<string>();
    
    // this is another validation on top of the FormQuestion validation.
    // one limitation of the FormQuestion validation is that it can only check for its own value
    // it cannot be used to check for another value together with its own value
    if(!CheckIfValidPassword(pass,passConfirm)){
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
