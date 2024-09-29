#include "DiamondBank/DiamondBank.h"
void LaunchDiamondBank(){
    DiamondBank bank;
    bank.Initialize();
    bank.LaunchUI();
}
int main(){
    LaunchDiamondBank();
}
