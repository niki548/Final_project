#pragma once
#ifndef DEPOSIT_ACCOUNT_H
#define DEPOSIT_ACCOUNT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "bank_account.h"

class Deposit_account : public Bank_account
{
public:
    Deposit_account();
    virtual void profit();
};

#endif // DEPOSIT_ACCOUNT_H
