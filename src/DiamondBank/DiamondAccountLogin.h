#ifndef DIAMONDACCOUNTLOGIN_H
#define DIAMONDACCOUNTLOGIN_H

#include <string>
#include "../Bank/IAccountLogin.h"
#include "../Bank/BankFeature2.h"
#include "../UI/Form.h"
#include <functional>

class DiamondAccountLogin : public IAccountLogin, public BankFeature2, public Form{
// events
    using OnLoginSuccess = std::function<void(AccountInfo)>;
    OnLoginSuccess onLoginSuccess;
    using OnLogoutSuccess = std::function<void()>;
    OnLogoutSuccess onLogoutSuccess;
public:
    void SetOnLoginSuccess(OnLoginSuccess callback);
    void SetOnLogoutSuccess(OnLogoutSuccess callback);

// normal functions
private:
    void AskForLoginCredentials();
protected:
    AccountInfo currentUser;
public:
    DiamondAccountLogin();
    ~DiamondAccountLogin();
    AccountInfo GetUser() override;
    bool Login(std::string email, std::string pass) override;
    bool IsLoggedIn() override;
    void Logout() override;

    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
};

#endif