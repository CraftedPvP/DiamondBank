#include "DiamondAccountCheckBalance.h"
#include <functional>
#include "../Utility/TextHelper.h"

DiamondAccountCheckBalance::DiamondAccountCheckBalance()
{
    name = "Diamond Account Balance";
}

void DiamondAccountCheckBalance::Content()
{
    ShowBalance();
}

void DiamondAccountCheckBalance::ProcessInput()
{
    Hide();
}

void DiamondAccountCheckBalance::ShowBalance()
{
    if(!GetBank()->GetAccountLogin()->IsLoggedIn()){
        Log("You have to be signed in to do this action", true);
        return;
    }
    AccountInfo user = GetBank()->GetAccountLogin()->GetUser();
    float amountStored = GetBank()->GetAccountDatabase()->GetMoney(user.Email);
    Log("You have " + TextHelper::FixedFloat(amountStored) + " diamond(s).");
}
