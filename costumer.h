#ifndef COSTUMER_H
#define COSTUMER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "user.h"
#include "bank_account_list.h"

class Costumer : public User
{
private:
    //bank acount
public:
    Costumer();

    Bank_account_list* BList = new Bank_account_list;
    Deposit_account_list* DList = new Deposit_account_list;
    Loan_accoun_list* LList = new Loan_accoun_list;
    static string current_costumer_username;
    static string current_costumer_password;
};

#endif // COSTUMER_H
