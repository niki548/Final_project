#include "special_account_page.h"
#include "ui_special_account_page.h"
#include "List.h"
#include "admin_page.h"
#include <QListWidgetItem>
#include <QMessageBox>

especial_account_page::especial_account_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::especial_account_page)
{
    ui->setupUi(this);

    CNode *newcostumer = CList->getHead();
    BNode* bnewaccount;

    for(int i=0; i<CList->getSize(); i++){
        bnewaccount = newcostumer->newcostumer.BList->getHead();
        for (int j=0; j< newcostumer->newcostumer.BList->getSize(); j++){
            ui->listWidget->addItem(QString::fromStdString(bnewaccount->newAccount.getCard_number()));
            bnewaccount = bnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }

    newcostumer = CList->getHead();

    LNode* lnewaccount;
    for(int i=0; i<CList->getSize(); i++){
        lnewaccount = newcostumer->newcostumer.LList->getHead();
        for (int j=0; j< newcostumer->newcostumer.LList->getSize(); j++){
            ui->listWidget->addItem(QString::fromStdString(lnewaccount->newAccount.getCard_number()));
            lnewaccount = lnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }

    newcostumer = CList->getHead();

    DNode* dnewaccount = newcostumer->newcostumer.DList->getHead();

    for(int i=0; i<CList->getSize(); i++){
        dnewaccount = newcostumer->newcostumer.DList->getHead();
        for (int j=0; j< newcostumer->newcostumer.DList->getSize(); j++){
            ui->listWidget->addItem(QString::fromStdString(dnewaccount->newAccount.getCard_number()));
            dnewaccount = dnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }
}

especial_account_page::~especial_account_page()
{
    delete ui;
}

void especial_account_page::on_pushButton_clicked()
{
    int point = 0;

    BNode* foundBAccount = nullptr;
    DNode* foundDAccount = nullptr;
    LNode* foundLAccount = nullptr;

    QListWidgetItem* citem = ui->listWidget->currentItem();
    if(citem){
        CNode *newcostumer = CList->getHead();
        BNode* baccount ;
        DNode* daccount ;
        LNode* laccount ;

        for(int i=0; i<CList->getSize(); i++){
            baccount = newcostumer->newcostumer.BList->getHead();
            daccount = newcostumer->newcostumer.DList->getHead();
            laccount = newcostumer->newcostumer.LList->getHead();

            for(int j=0; j<newcostumer->newcostumer.BList->getSize(); j++){
                if (citem->text().toStdString() == baccount->newAccount.getCard_number()){
                    foundBAccount = baccount;
                    point = 1;
                     goto foundAccount;
                }
                baccount = baccount->next;
            }

            for(int j=0; j<newcostumer->newcostumer.DList->getSize(); j++){
                if (citem->text().toStdString() == daccount->newAccount.getCard_number()){
                    foundDAccount = daccount;
                    point = 2;
                     goto foundAccount;
                }
                daccount = daccount->next;
            }

            for(int j=0; j<newcostumer->newcostumer.LList->getSize(); j++){
                if (citem->text().toStdString() == laccount->newAccount.getCard_number()){
                    foundLAccount = laccount;
                    point = 3;
                     goto foundAccount;
                }
                laccount = laccount->next;
            }
            newcostumer = newcostumer->next;
        }
foundAccount:
        if(point == 1){
            ui->ln_card_number->setText(QString::fromStdString(foundBAccount->newAccount.getCard_number()));
            ui->ln_number_account->setText(QString::fromStdString(foundBAccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(foundBAccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(foundBAccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(foundBAccount->newAccount.getDynamic_second_password()));
            ui->ln_date->setText(QString::fromStdString(foundBAccount->newAccount.getExpiration_date()));
            ui->ln_f_second->setText(QString::fromStdString(foundBAccount->newAccount.getFixed_second_password()));
            ui->ln_pin->setText(QString::fromStdString(foundBAccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(foundBAccount->newAccount.getShaba_number()));
        }

        else if(point == 2){
            ui->ln_card_number->setText(QString::fromStdString(foundDAccount->newAccount.getCard_number()));
            ui->ln_number_account->setText(QString::fromStdString(foundDAccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(foundDAccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(foundDAccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(foundDAccount->newAccount.getDynamic_second_password()));
            ui->ln_date->setText(QString::fromStdString(foundDAccount->newAccount.getExpiration_date()));
            ui->ln_f_second->setText(QString::fromStdString(foundDAccount->newAccount.getFixed_second_password()));
            ui->ln_pin->setText(QString::fromStdString(foundDAccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(foundDAccount->newAccount.getShaba_number()));
        }

        else if(point == 3){
            ui->ln_card_number->setText(QString::fromStdString(foundLAccount->newAccount.getCard_number()));
            ui->ln_number_account->setText(QString::fromStdString(foundLAccount->newAccount.getAccount_number()));
            ui->ln_chsh->setText(QString::fromStdString(foundLAccount->newAccount.getCash()));
            ui->ln_cvv2->setText(QString::fromStdString(foundLAccount->newAccount.getCvv2()));
            ui->ln_d_seccond->setText(QString::fromStdString(foundLAccount->newAccount.getDynamic_second_password()));
            ui->ln_date->setText(QString::fromStdString(foundLAccount->newAccount.getExpiration_date()));
            ui->ln_f_second->setText(QString::fromStdString(foundLAccount->newAccount.getFixed_second_password()));
            ui->ln_pin->setText(QString::fromStdString(foundLAccount->newAccount.getPin()));
            ui->ln_shaba->setText(QString::fromStdString(foundLAccount->newAccount.getShaba_number()));
        }
        else if(point == 0){
            QMessageBox* box = new QMessageBox;
            box->setText("account not found.");
            box->show();
        }
    }
    else{
        QMessageBox* box = new QMessageBox;
        box->setText("No account selected.");
        box->show();
    }
}


void especial_account_page::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

