#ifndef DIAMONDACCOUNTLOGIN_H
#define DIAMONDACCOUNTLOGIN_H

#include <string>
#include "../Bank/AccountLogin.h"
#include "../Bank/BankFeature.h"

class DiamondAccountLogin : public AccountLogin, public BankFeature{
    void AskForLoginCredentials();
protected:
    AccountInfo currentUser;
public:
    DiamondAccountLogin();
    ~DiamondAccountLogin();
    AccountInfo GetUser() override;
    bool Login(std::string email, std::string pass) override;
    bool IsLoggedIn() override;
    void OnChoose(int choice) override;
};

#endif