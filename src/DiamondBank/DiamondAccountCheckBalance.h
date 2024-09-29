#ifndef DIAMONDACCOUNTCHECKBALANCE_H
#define DIAMONDACCOUNTCHECKBALANCE_H

#include <string>
#include "../Bank/IAccountCheckBalance.h"
#include "../Bank/BankFeature2.h"
#include "../UI/UIBase.h"

class DiamondAccountCheckBalance : public IAccountCheckBalance, public BankFeature2, public UIBase{
public:
    DiamondAccountCheckBalance();
    void Content() override;
    void ProcessInput() override;
    void ShowBalance() override;
};

#endif