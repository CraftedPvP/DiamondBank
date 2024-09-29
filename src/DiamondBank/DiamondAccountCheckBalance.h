#ifndef DIAMONDACCOUNTCHECKBALANCE_H
#define DIAMONDACCOUNTCHECKBALANCE_H

#include <string>
#include "../Bank/AccountCheckBalance.h"
#include "../Bank/BankFeature.h"

class DiamondAccountCheckBalance : public AccountCheckBalance, public BankFeature{
public:
    DiamondAccountCheckBalance();
    void ShowBalance() override;
    void OnChoose(int choice) override;
};

#endif