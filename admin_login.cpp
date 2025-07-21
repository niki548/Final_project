#include "admin_login.h"
#include "ui_admin_login.h"
#include "admin.h"
#include <QMessageBox>
using namespace std;

//UserList *UList = new UserList ;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signin_admin_1(){
    string name, lastname, nationalcode, password, username, age;
    int age1;
    bool status = true;
    name = ui->ln_name_si->text().toStdString();
    lastname = ui->ln_lastname_si->text().toStdString();
    nationalcode = ui->ln_nationa_si->text().toStdString();
    password = ui->ln_password_si->text().toStdString();
    username = ui->ln_username_si->text().toStdString();
    age = ui->ln_age_si->text().toStdString();
    if(name == "" || nationalcode == "" || password == "" || lastname == "" || username == "" || age == ""){
        QMessageBox* box = new QMessageBox;
        box->setText("a plce is empty.");
        box->setWindowTitle("information eror");
        box->show();
        status = false;
    }
    age1 = stoi(age);
    if(status == true){
         User::signin_admin(name, lastname, nationalcode, password, username, age1);
    }
}

void MainWindow::login_admin_1(){
    string password, username;

    password = ui->ln_password->text().toStdString();
    username = ui->ln_username->text().toStdString();

    if(User::login_admin(username, password) == true){

        this->close();

        Admin::current_admin_username = username;
        Admin::current_admin_password = password;
    }

    else{
        QMessageBox* box = new QMessageBox;
        box->setText("password or username are not found.");
        box->setWindowTitle("information eror");
        box->show();
    }
}

void MainWindow::on_signin_btn_clicked()
{
    signin_admin_1();
}




void MainWindow::on_login_btn_clicked()
{
    login_admin_1();
}

