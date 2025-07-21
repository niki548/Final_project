#ifndef DIPOSIT_ACCOUNT_PAGE_H
#define DIPOSIT_ACCOUNT_PAGE_H

#include <QDialog>

namespace Ui {
class diposit_account_page;
}

class diposit_account_page : public QDialog
{
    Q_OBJECT

public:
    explicit diposit_account_page(QWidget *parent = nullptr);
    ~diposit_account_page();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::diposit_account_page *ui;
};

#endif // DIPOSIT_ACCOUNT_PAGE_H
