#include "admin_list.h"
#include "ui_admin_list.h"
#include "List.h"
#include "admin_page.h"

admin_list::admin_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_list)
{
    ui->setupUi(this);
}

admin_list::~admin_list()
{
    delete ui;
}

void admin_list::on_pushButton_clicked()
{
    ANode* newadmin = AList->getHead();
    for(int i=0; i<AList->getSize(); i++){
        ui->listWidget_name->addItem(QString::fromStdString(newadmin->newadmin.getName()));
        ui->listWidget_lastname->addItem(QString::fromStdString(newadmin->newadmin.getLastname()));
        ui->listWidget_username->addItem(QString::fromStdString(newadmin->newadmin.getUsername()));
        newadmin = newadmin->next;
    }

}





void admin_list::on_pushButton_2_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

