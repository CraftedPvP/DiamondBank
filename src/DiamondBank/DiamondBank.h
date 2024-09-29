#ifndef DIAMONDBANK_H
#define DIAMONDBANK_H

#include <string>
using std::string;

#include "../Bank/Bank.h"
#include "../UI/Menu.h"

class DiamondBank : Bank{
    /* UI for non-signed in users */
    Menu login;
    /* UI for signed in users */
    Menu signedIn;

    void OnChoose_Login(int choice);
    void OnChoose_SignedIn(int choice);
public:
    DiamondBank();
    void Initialize() override;
    /* Main loop */
    void LaunchUI() override;
};

#endif