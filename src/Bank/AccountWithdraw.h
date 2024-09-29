#ifndef ACCOUNTWITHDRAW_H
#define ACCOUNTWITHDRAW_H

#include <string>

/**
 * Interface for account withdrawal page
 */
class AccountWithdraw {
protected:
    float transactionFee = .12f;
public:
    virtual void SetTransactionFee(float amount) = 0;
    virtual bool CheckIfCanWithdraw(float amount) = 0;
    virtual bool Withdraw(float amount) = 0;
};

#endif