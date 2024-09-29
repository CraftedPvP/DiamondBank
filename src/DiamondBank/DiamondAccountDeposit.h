#ifndef DIAMONDACCOUNTDEPOSIT_H
#define DIAMONDACCOUNTDEPOSIT_H

#include <string>
#include "../Bank/AccountDeposit.h"
#include "../Bank/BankFeature.h"

class DiamondAccountDeposit : public AccountDeposit, public BankFeature{
public:
    DiamondAccountDeposit();
    void SetTransactionFee(float depositFee) override;
    bool CheckIfCanDeposit(float toDeposit) override;
    bool Deposit(float toDeposit) override;
    void OnChoose(int choice) override;
};

#endif