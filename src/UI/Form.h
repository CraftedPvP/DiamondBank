#ifndef FORM_H
#define FORM_H

#include "UIBase.h"
#include "FormQuestion.h"
#include <map>
#include <string>
#include <iostream>
#include <variant>

/**
 * Used to access other bank features for verification or whatever
 */
class Form : public UIBase {
protected:
    /**
     * Form id, FormQuestion
     */
    std::map<std::string,FormQuestion> formData;
public:
    /**
     * Set the form data here
     */
    virtual void Initialize() = 0;
    /**
     * Clears input validation rules made that was added into the FormQuestion if there is any
     */
    ~Form();
};

#endif