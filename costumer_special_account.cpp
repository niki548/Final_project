#include "costumer_special_account.h"
#include "ui_costumer_special_account.h"
#include "List.h"
#include "costumer_page.h"
#include <QListWidgetItem>
#include <QMessageBox>

costumer_account_list::costumer_account_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::costumer_account_list)
{
    ui->setupUi(this);

    CNode* newcostumer = CList->getHead();
    for(int i=0; i< CList->getSize(); i++){
        if(Costumer::current_costumer_password == newcostumer->newcostumer.getPassword() && Costumer::current_costumer_username == newcostumer->newcostumer.getUsername()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    BNode* baccount = newcostumer->newcostumer.BList->getHead();
    LNode* laccount = newcostumer->newcostumer.LList->getHead();
    DNode* daccount = newcostumer->newcostumer.DList->getHead();

    for(int i=0; i<newcostumer->newcostumer.BList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(baccount->newAccount.getCard_number()));
        baccount = baccount->next;
    }

    for(int i=0; i<newcostumer->newcostumer.LList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(laccount->newAccount.getCard_number()));
        laccount = laccount->next;
    }

    for(int i=0; i<newcostumer->newcostumer.DList->getSize(); i++){
        ui->listWidget->addItem(QString::fromStdString(daccount->newAccount.getCard_number()));
        daccount = daccount->next;
    }
}

costumer_account_list::~costumer_account_list()
{
    delete ui;
}

void costumer_account_list::on_pushButton_clicked()
{
    int ptr = 0;

    QListWidgetItem* citem = ui->listWidget->currentItem();
    if(citem){
        CNode* newcostumer = CList->getHead();
        for(int i=0; i< CList->getSize(); i++){
            if(Costumer::current_costumer_password == newcostumer->newcostumer.getPassword() && Costumer::current_costumer_username == newcostumer->newcostumer.getUsername()){
                break;
            }
            newcostumer = newcostumer->next;
        }

        BNode* baccount = newcostumer->newcostumer.BList->getHead();
        LNode* laccount = newcostumer->newcostumer.LList->getHead();
        DNode* daccount = newcostumer->newcostumer.DList->getHead();

        for(int i=0; i<newcostumer->newcostumer.BList->getSize(); i++){
            if(citem->text().toStdString() == baccount->newAccount.getCard_number()){
                ptr = 1;
                break;
            }
            baccount = baccount->next;
        }

        for(int i=0; i<newcostumer->newcostumer.LList->getSize(); i++){
            if(citem->text().toStdString() == laccount->newAccount.getCard_number()){
                ptr = 2;
                break;
            }
            laccount = laccount->next;
        }


        for(int i=0; i<newcostumer->newcostumer.DList->getSize(); i++){
            if(citem->text().toStdString() == daccount->newAccount.getCard_number()){
                ptr = 3;
                break;
            }
            daccount = daccount->next;
        }

        if(ptr == 1){
            ui->ln_card_number->setText(QString::fromStdString(baccount->newAccount.getAccount_number()));
            ui->ln_number_account->setText(QString::fromStdString(baccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(baccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(baccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(baccount->newAccount.getDynamic_second_password()));
            ui->ln_f_second->setText(QString::fromStdString(baccount->newAccount.getFixed_second_password()));
            ui->ln_date->setText(QString::fromStdString(baccount->newAccount.getExpiration_date()));
            ui->ln_pin->setText(QString::fromStdString(baccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(baccount->newAccount.getShaba_number()));
            ui->ln_type->setText(QString::fromStdString("currunt account"));
        }

        else if(ptr == 2){
            ui->ln_card_number->setText(QString::fromStdString(laccount->newAccount.getAccount_number()));
            ui->ln_number_account->setText(QString::fromStdString(laccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(laccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(laccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(laccount->newAccount.getDynamic_second_password()));
            ui->ln_f_second->setText(QString::fromStdString(laccount->newAccount.getFixed_second_password()));
            ui->ln_date->setText(QString::fromStdString(laccount->newAccount.getExpiration_date()));
            ui->ln_pin->setText(QString::fromStdString(laccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(laccount->newAccount.getShaba_number()));
            ui->ln_type->setText(QString::fromStdString("Loan account"));
        }

        else if(ptr == 3){
            ui->ln_card_number->setText(QString::fromStdString(daccount->newAccount.getAccount_number()));
            ui->ln_number_account->setText(QString::fromStdString(daccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(daccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(daccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(daccount->newAccount.getDynamic_second_password()));
            ui->ln_f_second->setText(QString::fromStdString(daccount->newAccount.getFixed_second_password()));
            ui->ln_date->setText(QString::fromStdString(daccount->newAccount.getExpiration_date()));
            ui->ln_pin->setText(QString::fromStdString(daccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(daccount->newAccount.getShaba_number()));
            ui->ln_type->setText(QString::fromStdString("deposit account"));
        }

        else if(ptr == 0){
            QMessageBox* box = new QMessageBox;
            box->setText("account not fount.");
            box->show();
        }
    }

    else{
        QMessageBox* box = new QMessageBox;
        box->setText("you dont select any item.");
        box->show();
    }
}


void costumer_account_list::on_toolButton_clicked()
{
    costumer_page* newpage = new costumer_page;
    newpage->show();
    this->close();
}

