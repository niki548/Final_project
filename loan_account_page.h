#ifndef LOAN_ACCOUNT_PAGE_H
#define LOAN_ACCOUNT_PAGE_H

#include <QDialog>

namespace Ui {
class Loan_account_page;
}

class Loan_account_page : public QDialog
{
    Q_OBJECT

public:
    explicit Loan_account_page(QWidget *parent = nullptr);
    ~Loan_account_page();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::Loan_account_page *ui;
};

#endif // LOAN_ACCOUNT_PAGE_H
