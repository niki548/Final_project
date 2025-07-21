#pragma once
#ifndef LOAN_ACCOUN_H
#define LOAN_ACCOUN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "bank_account.h"

class Loan_accoun : public Bank_account
{
public:
    Loan_accoun();
    virtual void profit();
};

#endif // LOAN_ACCOUN_H
