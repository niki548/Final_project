#include "costumer_change_info.h"
#include "ui_costumer_change_info.h"
#include "List.h"
#include "admin_page.h"
#include <QListWidgetItem>

costumer_change_info::costumer_change_info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::costumer_change_info)
{
    ui->setupUi(this);
    newcostumer = CList->getHead();
}

costumer_change_info::~costumer_change_info()
{
    delete ui;
}

void costumer_change_info::on_pushButton_2_clicked()
{
    CNode* newcostumer = CList->getHead();
    for (int i=0; i<CList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(newcostumer->newcostumer.getUsername()));
        newcostumer = newcostumer->next;
    }
}


void costumer_change_info::on_pushButton_3_clicked()
{

    newcostumer = CList->getHead();
    QListWidgetItem* citem = ui->listWidget->currentItem();

    for(int i=0; i<CList->getSize(); i++){
        if(newcostumer->newcostumer.getUsername() == citem->text().toStdString()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    ui->ln_name->setText(QString::fromStdString(newcostumer->newcostumer.getName()));
    ui->ln_lastname->setText(QString::fromStdString(newcostumer->newcostumer.getLastname()));
    ui->ln_code->setText(QString::fromStdString(newcostumer->newcostumer.getNationalCode()));
    ui->ln_age->setText(QString::number(newcostumer->newcostumer.getAge()));
    ui->ln_username->setText(QString::fromStdString(newcostumer->newcostumer.getUsername()));
    ui->ln_password->setText(QString::fromStdString(newcostumer->newcostumer.getPassword()));
}


void costumer_change_info::on_toolButton_name_clicked()
{
    newcostumer->newcostumer.setName(ui->ln_name1->text().toStdString());
    ui->ln_name->setText(QString::fromStdString(newcostumer->newcostumer.getName()));
}


void costumer_change_info::on_toolButton_lastname_clicked()
{
    newcostumer->newcostumer.setLastname(ui->ln_lastname1->text().toStdString());
    ui->ln_lastname->setText(QString::fromStdString(newcostumer->newcostumer.getLastname()));
}


void costumer_change_info::on_toolButton_code_clicked()
{
    newcostumer->newcostumer.setNationalCode(ui->ln_code1->text().toStdString());
    ui->ln_code->setText(QString::fromStdString(newcostumer->newcostumer.getNationalCode()));
}


void costumer_change_info::on_toolButton_age_clicked()
{
    newcostumer->newcostumer.setAge(ui->ln_age1->text().toInt());
    ui->ln_age->setText(QString::number(newcostumer->newcostumer.getAge()));
}


void costumer_change_info::on_toolButton_username_clicked()
{
    newcostumer->newcostumer.setUsername(ui->ln_username1->text().toStdString());
    ui->ln_username->setText(QString::fromStdString(newcostumer->newcostumer.getUsername()));
}



void costumer_change_info::on_toolButton_password_clicked()
{
    newcostumer->newcostumer.setpassword(ui->ln_password1->text().toStdString());
    ui->ln_password->setText(QString::fromStdString(newcostumer->newcostumer.getPassword()));
}


void costumer_change_info::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

