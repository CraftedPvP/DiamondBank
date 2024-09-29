#include "UIBase.h"
#include <iostream>
#include <stdlib.h> // to do system("") calls
#include <limits> // to invalidate/clear the console input

using std::cin;
using std::cout;
using std::endl;
void UIBase::DisplayBanner()
{
    cout << endl << "===============\n" << name << "\n===============" << endl;
}
void UIBase::Pause() { system("pause"); }
void UIBase::ClearScreen() { system("cls"); }

void UIBase::Show()
{
    keepShowing = true;
    do{
        ClearScreen();
        ClearInput();

        DisplayBanner();
        Content();

        AskForInput();

        if(keepShowing) Pause();
    }
    while(keepShowing);
}

void UIBase::Hide() { keepShowing = false; }

void UIBase::AskForInput()
{
    // ask input here
    // you can set keepShowing false in this section
    keepShowing = false;
}

void UIBase::ClearInput()
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}