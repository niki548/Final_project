#ifndef LIST_ACCOUNT_PAGE_H
#define LIST_ACCOUNT_PAGE_H

#include <QDialog>

namespace Ui {
class List_account_page;
}

class List_account_page : public QDialog
{
    Q_OBJECT

public:
    explicit List_account_page(QWidget *parent = nullptr);
    ~List_account_page();

private slots:
    void on_toolButton_clicked();

private:
    Ui::List_account_page *ui;
};

#endif // LIST_ACCOUNT_PAGE_H
