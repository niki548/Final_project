#include "bank_account_list.h"

Bank_account_list::Bank_account_list() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

Loan_accoun_list::Loan_accoun_list(){
    this->head = this->tail = nullptr;
    this->size = 0;
}

Deposit_account_list::Deposit_account_list(){
    this->head = this->tail = nullptr;
    this->size = 0;
}

void Bank_account_list::pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                                 string pin, string fixed_second_password,string dynamic_second_password){

    BNode* newaccount = new BNode;

    newaccount->newAccount.setAccount_number(account_number);
    newaccount->newAccount.setShaba_number(shaba_number);
    newaccount->newAccount.setCard_number(card_number);
    newaccount->newAccount.setCvv2(cvv2);
    newaccount->newAccount.setCash(cash);
    newaccount->newAccount.setExpiration_date(expiration_date);
    newaccount->newAccount.setPin(pin);
    newaccount->newAccount.setFixed_second_password(fixed_second_password);
    newaccount->newAccount.setDynamic_second_password(dynamic_second_password);

    newaccount->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newaccount;
        newaccount->next = this->tail;
    }
    else{

        this->tail->next = newaccount;
        this->tail = newaccount;
    }

    this->size++;

}

void Loan_accoun_list::pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                                string pin, string fixed_second_password,string dynamic_second_password){

    LNode* newaccount = new LNode;

    newaccount->newAccount.setAccount_number(account_number);
    newaccount->newAccount.setShaba_number(shaba_number);
    newaccount->newAccount.setCard_number(card_number);
    newaccount->newAccount.setCvv2(cvv2);
    newaccount->newAccount.setCash(cash);
    newaccount->newAccount.setExpiration_date(expiration_date);
    newaccount->newAccount.setPin(pin);
    newaccount->newAccount.setFixed_second_password(fixed_second_password);
    newaccount->newAccount.setDynamic_second_password(dynamic_second_password);

    newaccount->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newaccount;
        newaccount->next = this->tail;
    }
    else{

        this->tail->next = newaccount;
        this->tail = newaccount;
    }

    this->size++;
}

void Deposit_account_list::pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                                    string pin, string fixed_second_password,string dynamic_second_password){

    DNode* newaccount = new DNode;

    newaccount->newAccount.setAccount_number(account_number);
    newaccount->newAccount.setShaba_number(shaba_number);
    newaccount->newAccount.setCard_number(card_number);
    newaccount->newAccount.setCvv2(cvv2);
    newaccount->newAccount.setCash(cash);
    newaccount->newAccount.setExpiration_date(expiration_date);
    newaccount->newAccount.setPin(pin);
    newaccount->newAccount.setFixed_second_password(fixed_second_password);
    newaccount->newAccount.setDynamic_second_password(dynamic_second_password);

    newaccount->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newaccount;
        newaccount->next = this->tail;
    }
    else{

        this->tail->next = newaccount;
        this->tail = newaccount;
    }

    this->size++;
}

BNode* Bank_account_list::getHead() {return this->head; }

BNode* Bank_account_list::getTail() {return this->tail; }

int Bank_account_list::getSize() {return this->size; }


LNode* Loan_accoun_list::getHead() {return this->head; }

LNode* Loan_accoun_list::getTail() {return this->tail; }

int Loan_accoun_list::getSize() {return this->size; }


DNode* Deposit_account_list::getHead() {return this->head; }

DNode* Deposit_account_list::getTail() {return this->tail; }

int Deposit_account_list::getSize() {return this->size; }
