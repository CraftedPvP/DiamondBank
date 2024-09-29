#ifndef ACCOUNTLOGIN_H
#define ACCOUNTLOGIN_H

#include <string>
#include "AccountInfo.h"

/**
 * Interface for account login page
 */
class AccountLogin {
public:
    virtual AccountInfo GetUser() = 0;
    virtual bool Login(std::string email, std::string pass) = 0;
    virtual bool IsLoggedIn() = 0;
};

#endif