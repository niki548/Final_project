#include "costumer_login.h"
#include "ui_costumer_login.h"
#include "costumerlist.h"
#include "QMessageBox.h"

costumer_login::costumer_login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::costumer_login)
{
    ui->setupUi(this);
}

costumer_login::~costumer_login()
{
    delete ui;
}

void costumer_login::on_pushButton_clicked()
{
    std::string username, password;

    username = ui->lnc_username->text().toStdString();
    password = ui->lnc_password->text().toStdString();

    if(User::login_costumer(username,password) == true){

        Costumer::current_costumer_username = username;
        Costumer::current_costumer_password = password;

        this->close();
    }

    else{
        QMessageBox* box = new QMessageBox;
        box->setText("password or username are not found.");
        box->setWindowTitle("information eror");
        box->show();
    }
}

