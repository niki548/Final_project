#pragma once
#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "bank_account.h"

class current_account: public Bank_account
{
public:
    current_account();
    virtual void profit();
};

#endif // CURRENT_ACCOUNT_H
