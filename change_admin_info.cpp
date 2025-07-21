#include "change_admin_info.h"
#include "ui_change_admin_info.h"
#include "List.h"
#include "admin_page.h"
using namespace std;

//ANode* newadmin = AList->getHead();

change_admin_info::change_admin_info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::change_admin_info)
{
    ui->setupUi(this);

    newadmin = AList->getHead();
    for(int i=0; i<AList->getSize(); i++){
        if(Admin::current_admin_username == newadmin->newadmin.getUsername() && Admin::current_admin_password == newadmin->newadmin.getPassword()){
            break;
        }
        newadmin = newadmin->next;
    }

    ui->ln_name->setText(QString::fromStdString(newadmin->newadmin.getName()));
    ui->ln_lastname->setText(QString::fromStdString(newadmin->newadmin.getLastname()));
    ui->ln_code->setText(QString::fromStdString(newadmin->newadmin.getNationalCode()));
    ui->ln_age->setText(QString::number(newadmin->newadmin.getAge()));
    ui->ln_username->setText(QString::fromStdString(newadmin->newadmin.getUsername()));
    ui->ln_password->setText(QString::fromStdString(newadmin->newadmin.getPassword()));

   /* ui->ln_name1->hide();
    ui->ln_lastname1->hide();
    ui->ln_code1->hide();
    ui->ln_age1->hide();
    ui->ln_username1->hide();
    ui->ln_password1->hide();*/
}

change_admin_info::~change_admin_info()
{
    delete ui;
}

void change_admin_info::on_t_name_clicked()
{
   newadmin->newadmin.setName(ui->ln_name1->text().toStdString());
   ui->ln_name->setText(QString::fromStdString(newadmin->newadmin.getName()));
}


void change_admin_info::on_t_lastname_clicked()
{
    newadmin->newadmin.setLastname(ui->ln_lastname1->text().toStdString());
    ui->ln_lastname->setText(QString::fromStdString(newadmin->newadmin.getLastname()));
}


void change_admin_info::on_t_code_clicked()
{
    newadmin->newadmin.setNationalCode(ui->ln_code1->text().toStdString());
    ui->ln_code->setText(QString::fromStdString(newadmin->newadmin.getNationalCode()));
}


void change_admin_info::on_t_age_clicked()
{
    newadmin->newadmin.setAge(ui->ln_age1->text().toInt());
    ui->ln_age->setText(QString::number(newadmin->newadmin.getAge()));
}


void change_admin_info::on_t_username_clicked()
{
    newadmin->newadmin.setUsername(ui->ln_username1->text().toStdString());
    ui->ln_username->setText(QString::fromStdString(newadmin->newadmin.getUsername()));
}


void change_admin_info::on_t_password_clicked()
{
    newadmin->newadmin.setpassword(ui->ln_password1->text().toStdString());
    ui->ln_password->setText(QString::fromStdString(newadmin->newadmin.getPassword()));
}


void change_admin_info::on_toolButton_clicked()
{

    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

