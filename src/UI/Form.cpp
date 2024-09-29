#include "Form.h"

void Form::ClearFormData()
{
    for(auto& formQuestionPair : formData){
        formQuestionPair.second.ClearAndDeleteValidationRules();
    }
    formData.clear();
}

Form::~Form()
{
    ClearFormData();
}