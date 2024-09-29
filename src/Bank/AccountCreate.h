#ifndef ACCOUNTCREATE_H
#define ACCOUNTCREATE_H

#include <string>
#include "AccountInfo.h"
/**
 * Interface for account registration
 */
class AccountCreate {
public:
    virtual bool CheckIfExisting(std::string email) = 0;
    virtual bool CheckIfValidPassword(std::string pass, std::string confirmPass) = 0;
    virtual bool Create(AccountInfo user, std::string pass) = 0;
};

#endif