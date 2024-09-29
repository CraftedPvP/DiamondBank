#ifndef DIAMONDACCOUNTCLOSE_H
#define DIAMONDACCOUNTCLOSE_H

#include <string>
#include "../Bank/IAccountClose.h"
#include "../Bank/BankFeature.h"
#include <functional>

class DiamondAccountClose : public IAccountClose, public BankFeature{
// events
    using OnAccountCloseSuccess = std::function<void()>;
    OnAccountCloseSuccess onAccountCloseSuccess;
public:
    void SetOnAccountCloseSuccess(OnAccountCloseSuccess callback);

// normal functions
public:
    DiamondAccountClose();
    bool Close() override;
    void OnChoose(int choice) override;
};

#endif