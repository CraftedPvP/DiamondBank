#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <string>
using std::string;

#include "AccountInfo.h"

class IAccountDatabase {
public:
    // call this at app start up
    virtual bool CanConnect() = 0;

    // call this BEFORE you make changes in the database
    virtual void MakeDatabaseBackup() = 0;

    // only call this in the register/create page
    virtual bool CheckIfUserExists(string email) = 0;
    // only call this function if the user is authenticated to use the email we're passing
    //      this isn't ideal in a production environment but it's here since it's just a test project
    virtual AccountInfo GetAccount(string email) = 0;
    
    virtual bool CreateAccount(AccountInfo user, string pass) = 0;
    virtual bool DeleteAccount(string email) = 0;
    virtual AccountInfo Login(string email, string pass) = 0;

    virtual float GetMoney(string email) = 0;
    virtual bool AddMoney(string email, float amount) = 0;
    
    // ideally NOT created client side but it's here in-case you want to test out if the database is missing
    virtual bool CreateDatabase() = 0;
};

#endif