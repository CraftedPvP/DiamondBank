#ifndef INPUTVALIDATION_PASSWORD_H
#define INPUTVALIDATION_PASSWORD_H

#include "InputValidationVariant.h"

class InputValidationPassword : public InputValidationString {
public:
    InputValidationPassword(){Initialize();}
    void Initialize() override{
        AddRule([](const std::string& value) {
            return value.length() > 0;
        });
    }
    std::string GetErrorMessage() override{
        return "Password must be greater than 0 characters";
    }
};
#endif