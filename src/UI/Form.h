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
    // Known problem - if formData is being looped in a for-each loop but
    //      it contains no questions, it's going to say "You're trying to
    //      cast the Response for the FormQuestion ("") with the incorrect
    //      type. You should have used int". The only way to fix it is to
    //      call the Initialize() and add some questions.
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