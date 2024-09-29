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
    ClearFormData();

    FormQuestion question;
    std::string email = GetBank()->GetAccountLogin()->GetUser().Email;
    question.Set<std::string>("Do you want to close this \"" + email + "\" diamond account","");
    question.SetHint("(Y)es or (N)o");
    formData.emplace("1",question);
}
void DiamondAccountClose::Content()
{
    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << "?\t" << endl;
        cout << "Hint: " << kv.second.GetHint() << endl;
        cout << "Input: "; 
        kv.second.GetInput();
        num++;
    }
}

void DiamondAccountClose::ProcessInput()
{
    // because of how dangerous the operation is, if the user didn't say yes, just exit out of the form
    string response = formData["1"].GetResponse<string>();
    bool wantsToClose = response == "Y" || response == "y" || response == "yes" || response == "Yes";
    if(wantsToClose) Close();
    else Log("Returning to previous menu");
    Hide();
}


bool DiamondAccountClose::Close()
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        Log("You have to be signed in to do this action", true);
        return false;
    }

    std::string email = GetBank()->GetAccountLogin()->GetUser().Email;
    bool success = GetBank()->GetAccountDatabase()->DeleteAccount(email);
    if(success && onAccountCloseSuccess) {
        Log("Your diamond bank account has been closed");
        onAccountCloseSuccess();
    }
    else Log("Unable to close your diamond bank account at this time", true);
    return success;
}

void DiamondAccountClose::SetOnAccountCloseSuccess(OnAccountCloseSuccess callback) { onAccountCloseSuccess = callback; }
