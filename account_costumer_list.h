#ifndef ACCOUNT_COSTUMER_LIST_H
#define ACCOUNT_COSTUMER_LIST_H

#include <QDialog>

namespace Ui {
class account_costumer_list;
}

class account_costumer_list : public QDialog
{
    Q_OBJECT

public:
    explicit account_costumer_list(QWidget *parent = nullptr);
    ~account_costumer_list();

private slots:
    void on_toolButton_clicked();

private:
    Ui::account_costumer_list *ui;
};

#endif // ACCOUNT_COSTUMER_LIST_H
