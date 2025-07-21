#include "loan_accoun.h"

Loan_accoun::Loan_accoun() {}

void Loan_accoun::profit(){

    int money;
    money = stoi(this->getCash());
    money = money * 0.05;

    this->mprofit = to_string(money);
}
