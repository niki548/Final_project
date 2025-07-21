#ifndef COSTUMER_LOGIN_H
#define COSTUMER_LOGIN_H

#include <QDialog>

namespace Ui {
class costumer_login;
}

class costumer_login : public QDialog
{
    Q_OBJECT

public:
    explicit costumer_login(QWidget *parent = nullptr);
    ~costumer_login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::costumer_login *ui;
};

#endif // COSTUMER_LOGIN_H
