#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <functional>
#include "UIBase.h"

class Menu : public UIBase{
    bool keepShowing = true;
    int choice = 0;

    using ChooseCallback = std::function<void(int)>;
    ChooseCallback onChoose;
    
    // last element will always close the menu
    std::vector<std::string> actions;
public:
    std::string name = "Default menu";

    void Log(std::string content, bool isError = false);
    void DisplayBanner();
    void SetActions(const std::string actionsToSet[], int numOfActions);
    void SetChooseCallback(ChooseCallback callback);
    void Content() override;
    void ProcessInput() override;

    int GetChoice();
};


#endif