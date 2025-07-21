#ifndef SIGNIN_COSTUMER_H
#define SIGNIN_COSTUMER_H

#include <QDialog>

namespace Ui {
class signin_costumer;
}

class signin_costumer : public QDialog
{
    Q_OBJECT

public:
    explicit signin_costumer(QWidget *parent = nullptr);
    ~signin_costumer();

private slots:
    void on_add_btn_clicked();

    void on_close_btn_clicked();

    void on_pushButton_7_clicked();

    void on_toolButton_clicked();

private:
    Ui::signin_costumer *ui;
};

#endif // SIGNIN_COSTUMER_H
