#ifndef DIAMONDACCOUNTCLOSE_H
#define DIAMONDACCOUNTCLOSE_H

#include <string>
#include "../Bank/IAccountClose.h"
#include "../Bank/BankFeature2.h"
#include "../UI/Form.h"
#include <functional>

class DiamondAccountClose : public IAccountClose, public BankFeature2, public Form {
// events
    using OnAccountCloseSuccess = std::function<void()>;
    OnAccountCloseSuccess onAccountCloseSuccess;
public:
    void SetOnAccountCloseSuccess(OnAccountCloseSuccess callback);

// normal functions
public:
    DiamondAccountClose();
    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
    bool Close() override;
};

#endif