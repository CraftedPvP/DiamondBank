#ifndef INPUTVALIDATION_REGEX_H
#define INPUTVALIDATION_REGEX_H

#include "InputValidationVariant.h"
#include <regex>
#include <iostream>

using std::cout;
using std::endl;
class InputValidationRegex : public InputValidationString {
protected:
    std::string regexPattern;
public:
    InputValidationRegex(){Initialize();}
    void Initialize() override{
        AddRule([this](const std::string& value) {
            std::regex pattern(this->regexPattern);
            return std::regex_match(value, pattern);
        });
    }
    std::string GetErrorMessage() override{
        return "Value did not match the specified pattern";
    }
};
#endif