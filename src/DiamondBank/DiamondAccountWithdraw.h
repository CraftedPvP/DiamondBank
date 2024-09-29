#ifndef DIAMONDACCOUNTWITHDRAW_H
#define DIAMONDACCOUNTWITHDRAW_H

#include <string>
#include "../Bank/IAccountWithdraw.h"
#include "../Bank/BankFeature2.h"
#include "../UI/Form.h"

class DiamondAccountWithdraw : public IAccountWithdraw, public BankFeature2, public Form{
    void AskForInput();
public:
    DiamondAccountWithdraw();
    void SetTransactionFee(float transactionFee) override;
    bool CheckIfCanWithdraw(float toWithdraw) override;
    bool Withdraw(float toWithdraw) override;
    
    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
};

#endif