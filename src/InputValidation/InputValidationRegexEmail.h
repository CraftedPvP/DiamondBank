#ifndef INPUTVALIDATION_REGEX_EMAIL_H
#define INPUTVALIDATION_REGEX_EMAIL_H

#include "InputValidationRegex.h"

class InputValidationRegexEmail : public InputValidationRegex {
public:
    InputValidationRegexEmail(){
        regexPattern = R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z]{2,}$)";
        Initialize();
    }
    std::string GetErrorMessage() override{
        return "Value is not an email";
    }
};
#endif