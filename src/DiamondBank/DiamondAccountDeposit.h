#ifndef DIAMONDACCOUNTDEPOSIT_H
#define DIAMONDACCOUNTDEPOSIT_H

#include <string>
#include "../Bank/IAccountDeposit.h"
#include "../Bank/BankFeature2.h"
#include "../UI/Form.h"

class DiamondAccountDeposit : public IAccountDeposit, public BankFeature2, public Form{
    void AskForInput();
public:
    DiamondAccountDeposit();
    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
    
    void SetTransactionFee(float depositFee) override;
    bool CheckIfCanDeposit(float toDeposit) override;
    bool Deposit(float toDeposit) override;
};

#endif