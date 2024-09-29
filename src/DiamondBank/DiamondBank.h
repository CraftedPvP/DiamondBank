#ifndef DIAMONDBANK_H
#define DIAMONDBANK_H

#include <string>
using std::string;

#include "../Bank/Bank.h"
#include "../UI/Menu.h"

class DiamondBank : Bank{
    Menu login;
    Menu signedIn;

    void OnChoose_Login(int choice);
    void OnChoose_SignedIn(int choice);
public:
    DiamondBank();
    ~DiamondBank();
    void Initialize() override;
    void LaunchUI() override;
};

#endif