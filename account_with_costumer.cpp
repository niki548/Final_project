#include "account_with_costumer.h"
#include "ui_account_with_costumer.h"
#include "List.h"
#include "admin_page.h"
#include <QListWidgetItem>

account_with_costumer::account_with_costumer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::account_with_costumer)
{
    ui->setupUi(this);

    CNode* newcostumer = CList->getHead();

    for(int i=0; i<CList->getSize(); i++){
        ui->listWidget_username->addItem(QString::fromStdString(newcostumer->newcostumer.getUsername()));
        newcostumer = newcostumer->next;
    }
}

account_with_costumer::~account_with_costumer()
{
    delete ui;
}

void account_with_costumer::on_pushButton_clicked()
{
    QListWidgetItem* citem = ui->listWidget_username->currentItem();
    CNode* newcostumer = CList->getHead();
    for( int i=0; i<CList->getSize(); i++){
        if(newcostumer->newcostumer.getUsername() == citem->text().toStdString()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    BNode* baccount;
    LNode* laccount;
    DNode* daccount;

    baccount = newcostumer->newcostumer.BList->getHead();
    laccount = newcostumer->newcostumer.LList->getHead();
    daccount = newcostumer->newcostumer.DList->getHead();

    for(int j=0; j< newcostumer->newcostumer.BList->getSize(); j++){
        ui->listWidget_current->addItem(QString::fromStdString(baccount->newAccount.getCard_number()));
        baccount = baccount->next;
    }
    for(int j=0; j< newcostumer->newcostumer.DList->getSize(); j++){
        ui->listWidget_deposit->addItem(QString::fromStdString(daccount->newAccount.getCard_number()));
        daccount = daccount->next;
    }
    for(int j=0; j< newcostumer->newcostumer.LList->getSize(); j++){
        ui->listWidget_loan->addItem(QString::fromStdString(laccount->newAccount.getCard_number()));
        laccount = laccount->next;
    }

}


void account_with_costumer::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}


void account_with_costumer::on_pushButton_2_clicked()
{
    ui->listWidget_current->clear();
    ui->listWidget_deposit->clear();
    ui->listWidget_loan->clear();
}

