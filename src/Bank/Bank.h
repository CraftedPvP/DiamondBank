#ifndef BANK_H
#define BANK_H

#include <string>
using std::string;

#include "IAccountDatabase.h"
#include "IAccountCreate.h"
#include "IAccountLogin.h"
#include "IAccountCheckBalance.h"
#include "IAccountDeposit.h"
#include "IAccountWithdraw.h"
#include "IAccountClose.h"

/**
 * Base bank class
 */
class Bank{
protected:
    string name = "Bank Name";

    IAccountDatabase* accountDatabase;
    IAccountCreate* accountCreate;
    IAccountLogin* accountLogin;
    IAccountCheckBalance* accountCheckBalance;
    IAccountDeposit* accountDeposit;
    IAccountWithdraw* accountWithdraw;
    IAccountClose* accountClose;

public:
    ~Bank();
    virtual void Initialize() = 0;
    virtual void LaunchUI() = 0;

    IAccountDatabase* GetAccountDatabase() { return accountDatabase;}
    IAccountCreate* GetAccountCreate() { return accountCreate;}
    IAccountLogin* GetAccountLogin() { return accountLogin;}
    IAccountCheckBalance* GetAccountCheckBalance() { return accountCheckBalance;}
    IAccountDeposit* GetAccountDeposit() { return accountDeposit;}
    IAccountWithdraw* GetAccountWithdraw() { return accountWithdraw;}
    IAccountClose* GetAccountClose() { return accountClose;}

    virtual std::string GetSectionBanner(std::string section);
};

#endif