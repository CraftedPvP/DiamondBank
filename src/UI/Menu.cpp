#include "Menu.h"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

void Menu::DisplayBanner()
{
    cout << endl << "===============\n" << name << "\n===============" << endl;
}

void Menu::SetActions(const std::string actionsToSet[], int numOfActions)
{
    for (size_t i = 0; i < numOfActions; i++)
        actions.push_back(actionsToSet[i]);
}

void Menu::SetChooseCallback(ChooseCallback callback)
{
    onChoose = callback;
}

void Menu::Show()
{
    choice = 0;
    keepShowing = true;
    do{
        system("cls");
        DisplayBanner();

        for (size_t i = 1; i < actions.size()+1; i++)
            cout << "\t" << i << ". " << actions[i-1] << endl;

        cout << "Action 1-" << actions.size() << ": ";
        cin >> choice;

        if(choice == actions.size()){
            Hide();
            break;
        }
        else if(choice > actions.size() || choice <= 0){
            Log("Invalid input", true);
            system("pause");
            continue;
        }
        if (onChoose) onChoose(choice);
        else Log("OnChoose Callback not set for " + name, true);
        system("pause");
    }
    while(true);
}

void Menu::Hide() { keepShowing = false; }

int Menu::GetChoice() { return choice; }

void Menu::Log(std::string content, bool isError){
    if(isError) cerr << "Error: " << content << endl;
    else cout << "Info: " << content << endl;
}