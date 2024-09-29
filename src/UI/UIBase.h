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
    std::string name = "UI name";
public:
    virtual void DisplayBanner();

    /**
     * Main loop
     */
    void Show() override;
    
    /**
     * stops the Main loop
     */
    void Hide() override;

    virtual void Content() = 0;
    virtual void ProcessInput();
    
    void Pause();
    void ClearScreen();
    void ClearInput();
    
    void Log(std::string content, bool isError = false);
};

#endif