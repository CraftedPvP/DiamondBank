#include "Bank.h"

Bank::~Bank()
{
    delete accountDatabase;
    delete accountCreate;
    delete accountLogin;
    delete accountCheckBalance;
    delete accountDeposit;
    delete accountWithdraw;
    delete accountClose;
}

std::string Bank::GetSectionBanner(std::string section)
{
    std::string content = "Bank";
    if(section.length() > 0) content +=" > "+ section;
    content += "\nYou are currently signed in as \"" + accountLogin->GetUser().Name + "\"";
    return content;
}
