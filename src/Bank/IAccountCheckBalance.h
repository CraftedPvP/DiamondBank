#ifndef ACCOUNTCHECKBALANCE_H
#define ACCOUNTCHECKBALANCE_H

#include <string>

/**
 * Interface for checking account balance
 */
class IAccountCheckBalance {
public:
    virtual void ShowBalance() = 0;
};

#endif