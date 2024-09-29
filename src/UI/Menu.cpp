#include "Menu.h"
#include <stdlib.h> // to do system("") calls
#include <iostream>
#include <limits> // to invalidate/clear the console input

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

void Menu::SetChooseCallback(ChooseCallback callback) { onChoose = callback; }

void Menu::Show()
{
    choice = 0;
    keepShowing = true;
    do{
        // clear screen
        system("cls");
        // clear input buffer
        ClearInput();
        // start of content
        DisplayBanner();

        for (size_t i = 1; i < actions.size()+1; i++)
            cout << "\t" << i << ". " << actions[i-1] << endl;

        cout << "Action 1-" << actions.size() << ": ";
        cin >> choice;

        if(choice > actions.size() || choice <= 0){
            Log("Invalid input", true);
            Pause();
            continue;
        }

        if (onChoose) {
            onChoose(choice);
            if(choice == actions.size()){
                Hide();
                break;
            }
        }
        else Log("OnChoose Callback not set for " + name, true);

        if(keepShowing) Pause();
    }
    while(keepShowing);
}

void Menu::Hide() { keepShowing = false; }
int Menu::GetChoice() { return choice; }
void Menu::Pause() { system("pause"); }

void Menu::ClearInput()
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void Menu::Log(std::string content, bool isError)
{
    if(isError) cerr << "Error: " << content << endl;
    else cout << content << endl;
}