#include "signin_costumer.h"
#include "ui_signin_costumer.h"
#include "admin.h"
#include "first_page.h"
#include "admin_page.h"
#include "QMessageBox"
using namespace std;

signin_costumer::signin_costumer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signin_costumer)
{
    ui->setupUi(this);
}

signin_costumer::~signin_costumer()
{
    delete ui;
}

void signin_costumer::on_add_btn_clicked()
{
    string name, lastname, nationalcode, age, username, password;
    int age1;

    name = ui->ln_name->text().toStdString();
    lastname = ui->ln_lastname->text().toStdString();
    nationalcode = ui->ln_code->text().toStdString();
    age = ui->ln_age->text().toStdString();
    username = ui->ln_username->text().toStdString();
    password = ui->ln_password->text().toStdString();

    age1 = stoi(age);

    Admin::AddCostumer(name,lastname,nationalcode,username,password,age1);

    QMessageBox* box = new QMessageBox;
    box->setText("Customer addition was successful.");
    box->show();
}


void signin_costumer::on_close_btn_clicked()
{
    this->close();
}


void signin_costumer::on_pushButton_7_clicked()
{
    first_page* newpage = new first_page;
    newpage->show();
    this->close();
}


void signin_costumer::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

