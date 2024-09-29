#include "DiamondAccountClose.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

DiamondAccountClose::DiamondAccountClose()
{
    name = "Diamond Account Closing";
}

void DiamondAccountClose::Initialize()
{
    FormQuestion question;
    std::string email = GetBank()->GetAccountLogin()->GetUser().Email;
    question.Set<std::string>("Do you want to close this \"" + email + "\" diamond account?","");
    formData.emplace("1",question);
}
void DiamondAccountClose::Content()
{
    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << "?\t";
        kv.second.GetInput();
        num++;
    }
    // cout << "(Y)es or (N)o" << endl;
}

void DiamondAccountClose::ProcessInput()
{
    string response = formData["1"].GetResponse<string>();
    bool wantsToClose = response == "Y" || response == "y" || response == "yes" || response == "Yes";
    if(wantsToClose) Close();
    else Log("Returning to previous menu");
    Hide();
    Pause();
}


bool DiamondAccountClose::Close()
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        Log("You have to be signed in to do this action", true);
        return false;
    }

    std::string email = GetBank()->GetAccountLogin()->GetUser().Email;
    bool success = GetBank()->GetAccountDatabase()->DeleteAccount(email);
    Log("Your diamond bank account has been closed");
    if(success && onAccountCloseSuccess) onAccountCloseSuccess();
    else Log("Unable to close your diamond bank account at this time", true);
    return success;
}

void DiamondAccountClose::SetOnAccountCloseSuccess(OnAccountCloseSuccess callback) { onAccountCloseSuccess = callback; }
