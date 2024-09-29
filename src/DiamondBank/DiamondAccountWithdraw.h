#ifndef DIAMONDACCOUNTWITHDRAW_H
#define DIAMONDACCOUNTWITHDRAW_H

#include <string>
#include "../Bank/IAccountWithdraw.h"
#include "../Bank/BankFeature.h"

class DiamondAccountWithdraw : public IAccountWithdraw, public BankFeature{
    void AskForInput();
public:
    DiamondAccountWithdraw();
    void SetTransactionFee(float transactionFee) override;
    bool CheckIfCanWithdraw(float toWithdraw) override;
    bool Withdraw(float toWithdraw) override;
    void OnChoose(int choice) override;
};

#endif