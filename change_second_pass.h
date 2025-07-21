#ifndef CHANGE_SECOND_PASS_H
#define CHANGE_SECOND_PASS_H

#include <QDialog>
#include "list.h"

namespace Ui {
class change_second_pass;
}

class change_second_pass : public QDialog
{
    Q_OBJECT

public:
    explicit change_second_pass(QWidget *parent = nullptr);
    ~change_second_pass();

private slots:
    void on_pushButton_current_clicked();

    void on_pushButton_loan_clicked();

    void on_pushButton_deposit_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_second_pass *ui;
    CNode* newcostumer;
    string type;
    BNode* Baccount;
    LNode* Laccount;
    DNode* Daccount;
};

#endif // CHANGE_SECOND_PASS_H
