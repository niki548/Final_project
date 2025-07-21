#ifndef COSTUMER_SPECIAL_ACCOUNT_H
#define COSTUMER_SPECIAL_ACCOUNT_H

#include <QDialog>

namespace Ui {
class costumer_account_list;
}

class costumer_account_list : public QDialog
{
    Q_OBJECT

public:
    explicit costumer_account_list(QWidget *parent = nullptr);
    ~costumer_account_list();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::costumer_account_list *ui;
};

#endif // COSTUMER_SPECIAL_ACCOUNT_H
