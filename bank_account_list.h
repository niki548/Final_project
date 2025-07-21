#ifndef BANK_ACCOUNT_LIST_H
#define BANK_ACCOUNT_LIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "loan_accoun.h"
#include "current_account.h"
#include "deposit_account.h"

class LNode{
public:
    Loan_accoun newAccount;
    LNode* next;
};

class DNode{
public:
    Deposit_account newAccount;
    DNode* next;
};

class BNode{
public:
    current_account newAccount;
    BNode* next;
};

class Bank_account_list
{
private:
    BNode* head;
    BNode* tail;
    int size;
public:
    Bank_account_list();
    void pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                  string pin, string fixed_second_password,string dynamic_second_password);
    BNode* getHead ();
    BNode* getTail();
    int getSize();
};

class Loan_accoun_list{
private:
    LNode* head;
    LNode* tail;
    int size;
public:
    Loan_accoun_list();
    void pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                  string pin, string fixed_second_password,string dynamic_second_password);
    LNode* getHead ();
    LNode* getTail();
    int getSize();
};

class Deposit_account_list{
private:
    DNode* head;
    DNode* tail;
    int size;
public:
    Deposit_account_list();
    void pushback(string card_number, string shaba_number, string account_number,string cvv2, string cash, string expiration_date,
                  string pin, string fixed_second_password,string dynamic_second_password);
    DNode* getHead ();
    DNode* getTail();
    int getSize();
};

#endif // BANK_ACCOUNT_LIST_H
