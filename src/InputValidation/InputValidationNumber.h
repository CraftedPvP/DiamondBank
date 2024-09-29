#ifndef INPUTVALIDATION_NUMBER_H
#define INPUTVALIDATION_NUMBER_H

#include "InputValidationVariant.h"

class InputValidationNumber : public InputValidationFloat {
public:
    InputValidationNumber(){Initialize();}
    void Initialize() override{
        AddRule([](float value) {
            return value >= 0.f;
        });
    }
    std::string GetErrorMessage() override{
        return "Number must be greater than or equal to 0";
    }
};
#endif