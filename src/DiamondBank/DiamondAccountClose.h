#ifndef DIAMONDACCOUNTCLOSE_H
#define DIAMONDACCOUNTCLOSE_H

#include <string>
#include "../Bank/AccountClose.h"
#include "../Bank/BankFeature.h"

class DiamondAccountClose : public AccountClose, public BankFeature{
public:
    DiamondAccountClose();
    bool Close() override;
    void OnChoose(int choice) override;
};

#endif