#include "FormQuestion.h"
#include <iostream>
#include <limits> // to invalidate/clear the console input

bool FormQuestion::IsInvalidInput()
{
    if (std::cin.fail()) {
        std::cerr << std::endl << "Error: Invalid input" << std::endl; 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << question << "\t";
        return true;
    }
    // when entering a float value in int input, the integer gets sliced from the cin. then the float value bleeds into the next cin.
    // this behaviour is unwanted; hence, we clear it here. there's no side effect if there's nothing to clear and if it's just 100 chars to clear.
    std::cin.clear();
    std::cin.ignore(100, '\n');
    return false;
}
std::string FormQuestion::GetQuestion() {return question;}

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
    if(type == "string"){
        std::cin >> type;
        response = type;
    }
    else if(type == "int"){
        int num = 0;
        do{
            std::cin >> num;
        }
        while(IsInvalidInput());
        response = num;
    }
    else if(type == "float"){
        float num = 0;
        do{
            std::cin >> num;
        }
        while(IsInvalidInput());
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
