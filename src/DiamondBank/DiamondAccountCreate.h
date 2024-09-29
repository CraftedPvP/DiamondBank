#ifndef DIAMONDACCOUNTCREATE_H
#define DIAMONDACCOUNTCREATE_H

#include <string>
#include "../Bank/IAccountCreate.h"
#include "../Bank/BankFeature2.h"
#include "../UI/Form.h"

class DiamondAccountCreate : public IAccountCreate, public BankFeature2, public Form{
public:
    DiamondAccountCreate();
    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
    
    bool CheckIfExisting(std::string email) override;
    bool CheckIfValidPassword(std::string pass, std::string confirmPass) override;
    bool Create(AccountInfo user, std::string pass) override;
};

#endif