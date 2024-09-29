#include "FormQuestion.h"
#include <iostream>
#include <limits> // to invalidate/clear the console input

bool FormQuestion::IsInvalidInput()
{
    if (std::cin.fail()) {
        std::cerr << std::endl << "Error: Invalid input" << std::endl; 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}
std::string FormQuestion::GetQuestion() {return question;}

std::string FormQuestion::GetType(){
    if(std::holds_alternative<int>(value)) return "int";
    if(std::holds_alternative<float>(value)) return "float";
    if(std::holds_alternative<std::string>(value)) return "string";
    throw std::runtime_error("Unsupported value type in FormContent::GetType()");
}
void FormQuestion::GetInput(){
    std::string type = GetType();
    if(type == "string"){
        std::cin >> type;
        value = type;
    }
    else if(type == "int"){
        int num = 0;
        do{
            std::cin >> num;
        }
        while(IsInvalidInput());
        value = num;
    }
    else if(type == "float"){
        float num = 0;
        do{
            std::cin >> num;
        }
        while(IsInvalidInput());
        value = num;
    }
    else{
        std::cerr << std::endl << "Error: Unable to generate input form for type - " << type << std::endl; 
    }
}

void FormQuestion::PrintResponse()
{
    std::visit([](auto&& arg){
        std::cout << arg;
    },value);
}
