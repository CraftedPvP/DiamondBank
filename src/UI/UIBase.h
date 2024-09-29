#ifndef UIBASE_H
#define UIBASE_H

#include "IUI.h"
#include <string>
/**
 * User interface base
 */
class UIBase : public IUI {
protected:
    bool keepShowing = true;
    std::string name;
    std::string content;
public:
    virtual void DisplayBanner();

    void Show() override;
    void Hide() override;

    virtual void Content();
    virtual void AskForInput();
    
    void Pause();
    void ClearScreen();
    void ClearInput();
};

#endif