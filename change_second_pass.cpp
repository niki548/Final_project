#include "change_second_pass.h"
#include "ui_change_second_pass.h"
#include "costumer_page.h"
#include <QMessageBox>

change_second_pass::change_second_pass(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::change_second_pass)
{
    ui->setupUi(this);
    this->Baccount = nullptr;
    this->Daccount = nullptr;
    this->Laccount = nullptr;
}

change_second_pass::~change_second_pass()
{
    delete ui;
}

void change_second_pass::on_pushButton_current_clicked()
{

    newcostumer = CList->getHead();
    for(int i=0; i<CList->getSize(); i++){
        if(Costumer::current_costumer_password == newcostumer->newcostumer.getPassword() && Costumer::current_costumer_username == newcostumer->newcostumer.getUsername()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    BNode* baccount = newcostumer->newcostumer.BList->getHead();
    for(int i=0; i< newcostumer->newcostumer.BList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(baccount->newAccount.getCard_number()));
        baccount = baccount->next;
    }

    type = "current";
}


void change_second_pass::on_pushButton_loan_clicked()
{
    LNode* laccount = newcostumer->newcostumer.LList->getHead();
    for(int i=0; i< newcostumer->newcostumer.LList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(laccount->newAccount.getCard_number()));
        laccount = laccount->next;
    }

    type = "loan";
}


void change_second_pass::on_pushButton_deposit_clicked()
{
    DNode* daccount = newcostumer->newcostumer.DList->getHead();
    for(int i=0; i< newcostumer->newcostumer.DList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(daccount->newAccount.getCard_number()));
        daccount = daccount->next;
    }

    type = "deposit";
}


void change_second_pass::on_pushButton_clicked()
{
     QListWidgetItem* citem = ui->listWidget->currentItem();
    if(citem){
         if(type == "current"){
             Baccount = newcostumer->newcostumer.BList->getHead();;

             for(int i=0; i< newcostumer->newcostumer.BList->getSize(); i++){
                 if(citem->text().toStdString() == Baccount->newAccount.getCard_number()){
                     break;
                 }
                 Baccount = Baccount->next;
             }

             ui->lineEdit_first->setText(QString::fromStdString(Baccount->newAccount.getFixed_second_password()));
         }

         else if(type == "loan"){
             Laccount = newcostumer->newcostumer.LList->getHead();;

             for(int i=0; i< newcostumer->newcostumer.LList->getSize(); i++){
                 if(citem->text().toStdString() == Laccount->newAccount.getCard_number()){
                     break;
                 }
                 Laccount = Laccount->next;
             }

             ui->lineEdit_first->setText(QString::fromStdString(Laccount->newAccount.getFixed_second_password()));
         }

         else if(type == "deposit"){
             Daccount = newcostumer->newcostumer.DList->getHead();;

             for(int i=0; i< newcostumer->newcostumer.DList->getSize(); i++){
                 if(citem->text().toStdString() == Daccount->newAccount.getCard_number()){
                     break;
                 }
                 Daccount = Daccount->next;
             }

             ui->lineEdit_first->setText(QString::fromStdString(Daccount->newAccount.getFixed_second_password()));
         }
    }
    else{
        QMessageBox* box = new QMessageBox;
        box->setText("you dont select any item.");
        box->show();
    }
}


void change_second_pass::on_toolButton_clicked()
{
    string password = ui->lineEdit_change->text().toStdString();

    if(type == "current"){
        Baccount->newAccount.setPin(password);
        ui->lineEdit_first->setText(QString::fromStdString(Baccount->newAccount.getFixed_second_password()));
    }

    else if(type == "loan"){
        Laccount->newAccount.setPin(password);
        ui->lineEdit_first->setText(QString::fromStdString(Laccount->newAccount.getFixed_second_password()));
    }

    else if(type == "deposit"){
        Daccount->newAccount.setPin(password);
        ui->lineEdit_first->setText(QString::fromStdString(Daccount->newAccount.getFixed_second_password()));
    }
}


void change_second_pass::on_toolButton_2_clicked()
{
    costumer_page* newpage = new costumer_page;
    newpage->show();
    this->close();
}


void change_second_pass::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}

