#ifndef ACCOUNTLOGIN_H
#define ACCOUNTLOGIN_H

#include <string>
#include "AccountInfo.h"

class AccountLogin {
public:
    AccountLogin();
    virtual AccountInfo GetUser() = 0;
    virtual bool Login(std::string email, std::string pass) = 0;
    virtual bool IsLoggedIn() = 0;
};

#endif