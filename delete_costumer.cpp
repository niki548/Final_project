#include "delete_costumer.h"
#include "ui_delete_costumer.h"
#include "List.h"
#include "admin_page.h"
#include <QMessageBox>
delete_costumer::delete_costumer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_costumer)
{
    ui->setupUi(this);
}

delete_costumer::~delete_costumer()
{
    delete ui;
}

void delete_costumer::on_pushButton_clicked()
{
    CNode* newcostumer = CList->getHead();

    for(int i=0; i<CList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(newcostumer->newcostumer.getUsername()));
        newcostumer = newcostumer->next;
    }
}


void delete_costumer::on_pushButton_2_clicked()
{
    QListWidgetItem* currentitem;
    currentitem = ui->listWidget->currentItem();

    Admin::deleteCostumer(currentitem);

    QMessageBox* box = new QMessageBox;
    box->setText("Customer deleted was successful.");
    box->show();
}


void delete_costumer::on_pushButton_3_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}


void delete_costumer::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

