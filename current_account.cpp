#include "current_account.h"

current_account::current_account() {}

void current_account::profit(){
    int money;
    money = stoi(this->getCash());
    money = money * 0.05;

    this->mprofit = to_string(money);
}
