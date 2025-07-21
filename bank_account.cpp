#include "bank_account.h"

Bank_account::Bank_account() {}

void Bank_account::setAccount_number(string account_number){ this->account_number = account_number; }

void Bank_account::setShaba_number(string shaba_number){ this->shaba_number = shaba_number; }

void Bank_account::setCard_number(string card_number){ this->card_number = card_number; }

void Bank_account::setCash(string cash){ this->cash = cash; }

void Bank_account::setCvv2(string cvv2){ this->cvv2 = cvv2; }

void Bank_account::setDynamic_second_password(string dynamic_second_password){ this->dynamic_second_password = dynamic_second_password; }

void Bank_account::setFixed_second_password(string fixed_second_password){ this->fixed_second_password = fixed_second_password; }

void Bank_account::setExpiration_date(string expiration_date){ this->expiration_date = expiration_date; }

void Bank_account::setPin(string pin){ this->pin = pin; }

string Bank_account::getAccount_number(){return this->account_number; }

string Bank_account::getShaba_number(){return this->shaba_number; }

string Bank_account::getCard_number(){return this->card_number; }

string Bank_account::getCash(){return this->cash; }

string Bank_account::getCvv2(){return this->cvv2; }

string Bank_account::getDynamic_second_password(){return this->dynamic_second_password; }

string Bank_account::getFixed_second_password(){return this->fixed_second_password; }

string Bank_account::getExpiration_date(){return this->expiration_date; }

string Bank_account::getPin(){return this->pin; }
