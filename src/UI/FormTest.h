#ifndef FORMTEST_H
#define FORMTEST_H

#include "Form.h"

/**
 * Used to access other bank features for verification or whatever
 */
class FormTest : public Form {
    FormQuestion question;
public:
    /**
     * Set the form data here
     */
    void Initialize() override;
    void Content() override;
    void ProcessInput() override;
};

#endif