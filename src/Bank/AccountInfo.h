#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <string>

struct AccountInfo {
public:
    AccountInfo():Email(""),Name(""),Money(0){}
    AccountInfo(std::string email, std::string name,float money = 0):Email(email),Name(name),Money(money){ }
    std::string Email;
    std::string Name;
    // don't store balance here since we can't be sure that 
    //      it's up-to-date always fetch from the database
    float Money;
    // also, the variable above is used for file operations since we just have a local txt file as a database
};

#endif