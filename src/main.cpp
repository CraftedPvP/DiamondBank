#include "DiamondBank/DiamondBank.h"
#include "UI/FormTest.h"
void LaunchDiamondBank(){
    DiamondBank bank;
    bank.Initialize();
    bank.LaunchUI();
}
void TestForm(){
    FormTest form;
    form.Initialize();
    form.Show();
}
int main(){
    // LaunchDiamondBank();
    TestForm();
}
