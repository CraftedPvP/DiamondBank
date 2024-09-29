#include "FormQuestion.h"
#include <iostream>
#include <limits> // to invalidate/clear the console input

bool FormQuestion::IsInvalidInput(std::variant<int,float,std::string> tempInput)
{
    // use C++ input validation
    if (std::cin.fail()) {
        std::cerr << std::endl << "Error: Invalid input" << std::endl; 
        ClearInput();
        std::cout << question << "\t";
        return true;
    }
    try{
        // use custom validation rules
        for(auto& v : validationRules){
            if(!v->IsValid(tempInput)) 
            {
                ClearInput();
                std::cerr << std::endl << "Error: " << v->GetErrorMessage() << std::endl; 
                std::cout << question << "\t";
                return true;
            }
        }
    }
    catch(std::exception e){
        std::cerr << std::endl << "Error: " << e.what() << std::endl; 
        return true;
    }
    ClearInput();
    return false;
}
std::vector<IValidation *> &FormQuestion::GetValidationRules() { return validationRules; }
void FormQuestion::AddValidationRule(IValidation *validation) { validationRules.push_back(validation); }
std::string FormQuestion::GetQuestion() { return question; }

std::string FormQuestion::GetType(){
    if(std::holds_alternative<int>(response)) return "int";
    if(std::holds_alternative<float>(response)) return "float";
    if(std::holds_alternative<std::string>(response)) return "string";
    // if this executes, it could be that we lack conditions to support additional types from the variant.
    // this is a logic error made by the developer; hence, we crash the program as it cannot be mediated by the code
    throw std::runtime_error("Unsupported value type in FormContent::GetType(). Try adding more types into the variant");
}
void FormQuestion::GetInput(){
    std::string type = GetType();
    std::variant<int,float,std::string> tempInput;
    if(type == "string"){
        std::string text;
        int num = 0;
        do{
            std::cin >> text;
            tempInput = text;
        }
        while(IsInvalidInput(tempInput));
        response = text;
    }
    else if(type == "int"){
        int num = 0;
        do{
            std::cin >> num;
            tempInput = num;
        }
        while(IsInvalidInput(tempInput));
        response = num;
    }
    else if(type == "float"){
        float num = 0;
        do{
            std::cin >> num;
            tempInput = num;
        }
        while(IsInvalidInput(tempInput));
        response = num;
    }
    else{
        std::cerr << std::endl << "Error: Unable to generate input form for type - " << type << std::endl; 
    }
}

void FormQuestion::PrintResponse()
{
    std::visit([](auto&& arg){
        std::cout << arg;
    },response);
}

void FormQuestion::ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void FormQuestion::ClearAndDeleteValidationRules()
{// call this when the form is no longer needed. otherwise, using the rule pointer will crash in FormQuestion inside IsInvalidInput
    for(auto& validation : validationRules){
        delete validation;
    }
    validationRules.clear();
}


void FormQuestion::ClearValidationRules()
{// call this when we just want a fresh FormQuestion with no values in it
    validationRules.clear();
}
