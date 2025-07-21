#ifndef CURRENT_ACCOUNT_PAGE_H
#define CURRENT_ACCOUNT_PAGE_H

#include <QDialog>

namespace Ui {
class Current_account_page;
}

class Current_account_page : public QDialog
{
    Q_OBJECT

public:
    explicit Current_account_page(QWidget *parent = nullptr);
    ~Current_account_page();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::Current_account_page *ui;
};

#endif // CURRENT_ACCOUNT_PAGE_H
