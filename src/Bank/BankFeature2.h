#ifndef BANKFEATURE2_H
#define BANKFEATURE2_H

#include "Bank.h"

/**
 * Used to access other bank features for verification or whatever
 */
class BankFeature2{
    Bank* bank;
protected:
    Bank* GetBank() { return bank; }
public:
    void SetBank(Bank* bank){ this->bank = bank; }
};

#endif