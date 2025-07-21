#ifndef ACCOUNT_WITH_COSTUMER_H
#define ACCOUNT_WITH_COSTUMER_H

#include <QDialog>

namespace Ui {
class account_with_costumer;
}

class account_with_costumer : public QDialog
{
    Q_OBJECT

public:
    explicit account_with_costumer(QWidget *parent = nullptr);
    ~account_with_costumer();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::account_with_costumer *ui;
};

#endif // ACCOUNT_WITH_COSTUMER_H
