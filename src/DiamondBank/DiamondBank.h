#ifndef DIAMONDBANK_H
#define DIAMONDBANK_H

#include <string>
using std::string;

#include "../Bank/Bank.h"
#include "../UI/Menu.h"

class DiamondBank : Bank{
    /* UI for non-signed in users */
    Menu unsignedInUserUI;
    /* UI for signed in users */
    Menu signedInUserUI;

    void OnChoose_Login(int choice);
    void OnChoose_SignedIn(int choice);
    
    bool wantsToContinue = true;

    void OnLoginSuccess_Event(AccountInfo user);
    void OnAccountCloseSuccess_Event();
    void OnLogoutSuccess_Event();

public:
    DiamondBank();
    void Initialize() override;
    /* Main loop */
    void LaunchUI() override;
    std::string GetSectionBanner(std::string section) override;
};

#endif