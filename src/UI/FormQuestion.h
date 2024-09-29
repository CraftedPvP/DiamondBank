#ifndef FORMQUESTION_H
#define FORMQUESTION_H

#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include "../InputValidation/InputValidationVariant.h"
#include <stdexcept>

class FormQuestion{
    std::string question;
    std::variant<int,float,std::string> response;

    std::vector<IValidation*> validationRules;

    /**
     * Returns true if invalid input
     * pass in the input that we need to check if it's valid or not and not "response"
     */
    bool IsInvalidInput(std::variant<int,float,std::string> tempInput);

    public:
    /**
     * You can customize the validation rules for its own value here.
     * Note, it is limited to check for itself and it cannot be used to combine multiple values for checking.
     * To add another validation rule, you'll have to create your own custom on when processing the Form
     */
    std::vector<IValidation*>& GetValidationRules();
    void AddValidationRule(IValidation* validation);

    /**
     * the 2nd value is the default value. this is used to determine
     * what its input should be when receiving via cin
     */
    template <typename T>
    void Set(std::string question, T value){
        this->question = question;
        this->response = value;
    }

    template<typename T>
    T GetResponse() {
        if(std::holds_alternative<T>(response)) return std::get<T>(response);
        // we crash the program here because there's a logic error made by the developer and it cannot be mediated by the program itself
        throw std::runtime_error("You're trying to cast the Response for the FormQuestion (\"" + question + "\") with the incorrect type. You should have used " + GetType());
    }
    /**
     * Gets the type in string so we can use it for checking what kind of input we should expect
     */
    std::string GetType();
    std::string GetQuestion();
    /**
     * Asks for the user input
     */
    void GetInput();
    void PrintResponse();
    /**
     * Use this if you just want to reset the FormQuestion but retain the existing validations
     */
    void ClearValidationRules();
    /**
     * Use this if you want to delete the validations and reset the FormQuestion
     */
    void ClearAndDeleteValidationRules();
    /**
     * Resets and clears the input stream from invalid characters
     */
    void ClearInput();
};
#endif