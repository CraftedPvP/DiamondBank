#ifndef BANK_H
#define BANK_H

#include <string>
using std::string;

#include "AccountDatabase.h"
#include "AccountCreate.h"
#include "AccountLogin.h"
#include "AccountCheckBalance.h"
#include "AccountDeposit.h"
#include "AccountWithdraw.h"
#include "AccountClose.h"

/**
 * Base bank class
 */
class Bank{
protected:
    string name = "Bank Name";

    AccountDatabase* accountDatabase;
    AccountCreate* accountCreate;
    AccountLogin* accountLogin;
    AccountCheckBalance* accountCheckBalance;
    AccountDeposit* accountDeposit;
    AccountWithdraw* accountWithdraw;
    AccountClose* accountClose;
public:
    ~Bank();
    virtual void Initialize() = 0;
    virtual void LaunchUI() = 0;

    AccountDatabase* GetAccountDatabase() { return accountDatabase;}
    AccountCreate* GetAccountCreate() { return accountCreate;}
    AccountLogin* GetAccountLogin() { return accountLogin;}
    AccountCheckBalance* GetAccountCheckBalance() { return accountCheckBalance;}
    AccountDeposit* GetAccountDeposit() { return accountDeposit;}
    AccountWithdraw* GetAccountWithdraw() { return accountWithdraw;}
    AccountClose* GetAccountClose() { return accountClose;}
};

#endif