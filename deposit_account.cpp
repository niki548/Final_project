#include "deposit_account.h"

Deposit_account::Deposit_account() {}

void Deposit_account::profit(){

    int money;
    money = stoi(this->getCash());
    money = money * 0.05;

    this->mprofit = to_string(money);
}
