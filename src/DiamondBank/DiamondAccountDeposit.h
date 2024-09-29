#ifndef DIAMONDACCOUNTDEPOSIT_H
#define DIAMONDACCOUNTDEPOSIT_H

#include <string>
#include "../Bank/IAccountDeposit.h"
#include "../Bank/BankFeature.h"

class DiamondAccountDeposit : public IAccountDeposit, public BankFeature{
    void AskForInput();
public:
    DiamondAccountDeposit();
    void SetTransactionFee(float depositFee) override;
    bool CheckIfCanDeposit(float toDeposit) override;
    bool Deposit(float toDeposit) override;
    void OnChoose(int choice) override;
};

#endif