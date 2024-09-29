#include "Bank.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

Bank::~Bank()
{
    delete accountDatabase;
    delete accountCreate;
    delete accountLogin;
    delete accountCheckBalance;
    delete accountDeposit;
    delete accountWithdraw;
    delete accountClose;
}
