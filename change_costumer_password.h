#ifndef CHANGE_COSTUMER_PASSWORD_H
#define CHANGE_COSTUMER_PASSWORD_H

#include <QDialog>
#include "List.h"

namespace Ui {
class change_costumer_password;
}

class change_costumer_password : public QDialog
{
    Q_OBJECT

public:
    explicit change_costumer_password(QWidget *parent = nullptr);
    ~change_costumer_password();

private slots:
    void on_pushButton_current_clicked();

    void on_pushButton_loan_clicked();

    void on_pushButton_deposit_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_costumer_password *ui;
    CNode* newcostumer;
    string type;
    BNode* Baccount;
    LNode* Laccount;
    DNode* Daccount;
};

#endif // CHANGE_COSTUMER_PASSWORD_H
