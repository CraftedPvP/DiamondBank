#ifndef FORM_H
#define FORM_H

#include "UIBase.h"
#include <map>
#include <string>
#include <iostream>
#include <variant>

/**
 * Used to access other bank features for verification or whatever
 */
class Form : public UIBase {
public:
    struct FormContent{
        std::string question;
        std::variant<int,float,std::string> value;

        public: 
        template <typename T>
        void Set(std::string question, T value){
            this->question = question;
            this->value = value;
        }

        template<typename T>
        T Get(){
            if(std::holds_alternative<int>(valueType)) return std::get<int>(value);
            if(std::holds_alternative<float>(valueType)) return std::get<float>(value);
            if(std::holds_alternative<std::string>(valueType)) return std::get<std::string>(value);
            throw std::runtime_error("Unsupported value type");
        }
    };
protected:
    /**
     * Form id, form content
     */
    std::map<std::string,FormContent> formData;
    /**
     * Set the form data here
     */
    virtual void Initialize() = 0;
    /**
     * Main loop
     */
    virtual void AskForUserInput() = 0;
    /**
     * Complete or repeat menu
     */
    virtual void OnComplete() = 0;
};

#endif