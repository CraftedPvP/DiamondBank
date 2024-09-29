#include <iostream>
#include <string>
#include "UI/Menu.h"
#include "DiamondBank/DiamondBank.h"
using namespace std;
void OnChoose(int choice){
    cout << choice << endl;
}
void TestMenu(){
    Menu menu;
    string actions[]={"Greet","Quit"};

    menu.SetActions(actions,2);
    menu.SetChooseCallback(OnChoose);
    
    menu.Show();
}
void TestDiamondBank(){
    DiamondBank bank;
    bank.Initialize();
    bank.LaunchUI();
}
int main(){
    // TestMenu();
    TestDiamondBank();
}
