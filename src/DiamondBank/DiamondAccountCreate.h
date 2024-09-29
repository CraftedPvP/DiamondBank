#ifndef DIAMONDACCOUNTCREATE_H
#define DIAMONDACCOUNTCREATE_H

#include <string>
#include "../Bank/BankFeature.h"

class DiamondAccountCreate : public IAccountCreate, public BankFeature{
    void AskForNewCredentials();
public:
    DiamondAccountCreate();
    bool CheckIfExisting(std::string email) override;
    bool CheckIfValidPassword(std::string pass, std::string confirmPass) override;
    bool Create(AccountInfo user, std::string pass) override;
    void OnChoose(int choice) override;
};

#endif