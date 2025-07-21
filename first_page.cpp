#include "first_page.h"
#include "ui_first_page.h"
#include "admin_login.h"
#include "costumer_login.h"
first_page::first_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::first_page)
{
    ui->setupUi(this);
}

first_page::~first_page()
{
    delete ui;
}



void first_page::on_pushButton_clicked()
{
    MainWindow* new_window = new MainWindow;
    new_window->show();
    this->close();
}


void first_page::on_pushButton_2_clicked()
{
    costumer_login* new_window = new costumer_login;
    new_window->show();
    this->close();
}

