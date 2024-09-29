#ifndef BANKFEATURE_H
#define BANKFEATURE_H

#include "Bank.h"
#include "../UI/Menu.h"

/**
 * Used to access other bank features for verification or whatever
 */
class BankFeature{
    Bank* bank;
protected:
    Bank* GetBank() { return bank; }
    Menu menu;
public:
    void SetBank(Bank* bank){ this->bank = bank; }
    virtual void ShowMenu(){ menu.Show(); }
    virtual void OnChoose(int choice) = 0;
};

#endif