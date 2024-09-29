#ifndef ACCOUNTDEPOSIT_H
#define ACCOUNTDEPOSIT_H

#include <string>

class AccountDeposit {
protected:
    float transactionFee = .12f;
public:
    virtual void SetTransactionFee(float transactionFee) = 0;
    virtual bool CheckIfCanDeposit(float toDeposit) = 0;
    virtual bool Deposit(float toDeposit) = 0;
};

#endif