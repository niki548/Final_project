#include "loan_account_page.h"
#include "ui_loan_account_page.h"
#include "List.h"
#include "admin_page.h"
#include <QMessageBox>

Loan_account_page::Loan_account_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Loan_account_page)
{
    ui->setupUi(this);
    CNode* newcostumer = CList->getHead();
    for(int i=0; i<CList->getSize();i++){
        ui->listWidget->addItem(QString::fromStdString(newcostumer->newcostumer.getUsername()));
        newcostumer = newcostumer->next;
    }
}

Loan_account_page::~Loan_account_page()
{
    delete ui;
}

void Loan_account_page::on_pushButton_clicked()
{
    string card_number, shaba_number, account_number, cvv2, cash, expiration_date, pin, fixed_second_password, dynamic_second_password;

    QListWidgetItem* citem = ui->listWidget->currentItem();

    CNode* newcostumer = CList->getHead();
    for(int i=0; i<CList->getSize();i++){
        if(newcostumer->newcostumer.getUsername() == citem->text().toStdString()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    card_number = ui->ln_card_number->text().toStdString();
    shaba_number = ui->ln_shaba->text().toStdString();
    account_number = ui->ln_number_account->text().toStdString();
    cvv2 = ui->ln_cvv2->text().toStdString();
    cash = ui->ln_chsh->text().toStdString();
    expiration_date = ui->ln_date->text().toStdString();
    pin = ui->ln_pin->text().toStdString();
    fixed_second_password = ui->ln_f_second->text().toStdString();
    dynamic_second_password = ui->ln_d_seccond->text().toStdString();

    newcostumer->newcostumer.LList->pushback(card_number, shaba_number, account_number, cvv2, cash, expiration_date,
                                             pin, fixed_second_password, dynamic_second_password);

    QMessageBox* box = new QMessageBox;
    box->setText("adding account was sucssesfully.");
    box->show();
}


void Loan_account_page::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

