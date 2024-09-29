#ifndef FORMQUESTION_H
#define FORMQUESTION_H

#include <iostream>
#include <string>
#include <variant>
#include <stdexcept>

class FormQuestion{
    std::string question;
    std::variant<int,float,std::string> value;

    bool IsInvalidInput();

    public:
    std::string GetQuestion();

    template <typename T>
    void Set(std::string question, T value){
        this->question = question;
        this->value = value;
    }

    template<typename T>
    T GetResponse() {
        if(std::holds_alternative<T>(value)) return std::get<T>(value);
        throw std::runtime_error("You're trying to access the FormQuestion Response with the incorrect type");
    }
    // auto GetResponse(){
    //     if(std::holds_alternative<int>(value)) return std::get<int>(value);
    //     if(std::holds_alternative<float>(value)) return std::get<float>(value);
    //     // if(std::holds_alternative<std::string>(value)) return std::get<std::string>(value);
    //     throw std::runtime_error("Unsupported value type in FormContent::GetResponse()");
    // }
    std::string GetType();
    void GetInput();
    void PrintResponse();
};
#endif