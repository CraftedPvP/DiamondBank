#include "Form.h"

Form::~Form()
{
    for(auto& formQuestionPair : formData){
        formQuestionPair.second.ClearValidationRules();
    }
}