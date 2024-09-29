#ifndef FORMQUESTION_H
#define FORMQUESTION_H

#include <iostream>
#include <string>
#include <variant>
#include <stdexcept>

class FormQuestion{
    std::string question;
    std::variant<int,float,std::string> response;

    bool IsInvalidInput();

    public:
    std::string GetQuestion();

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
    std::string GetType();
    void GetInput();
    void PrintResponse();
};
#endif