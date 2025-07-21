#include "account_costumer_list.h"
#include "ui_account_costumer_list.h"
#include "list.h"
#include "costumer_page.h"

account_costumer_list::account_costumer_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::account_costumer_list)
{
    ui->setupUi(this);

    CNode* newcostumer = CList->getHead();
    for(int i=0; i<CList->getSize(); i++){
        if(Costumer::current_costumer_password == newcostumer->newcostumer.getPassword() && Costumer::current_costumer_username == newcostumer->newcostumer.getUsername()){
            break;
        }
        newcostumer = newcostumer->next;
    }

    BNode* Baccount = newcostumer->newcostumer.BList->getHead();
    LNode* Laccount = newcostumer->newcostumer.LList->getHead();
    DNode* Daccount = newcostumer->newcostumer.DList->getHead();

    for(int i=0 ; i< newcostumer->newcostumer.LList->getSize(); i++){
        ui->list_loan->addItem(QString::fromStdString(Laccount->newAccount.getCard_number()));
        Laccount = Laccount->next;
    }

    for(int i=0 ; i< newcostumer->newcostumer.BList->getSize(); i++){
        ui->list_current->addItem(QString::fromStdString(Baccount->newAccount.getCard_number()));
        Baccount = Baccount->next;
    }

    for(int i=0 ; i< newcostumer->newcostumer.DList->getSize(); i++){
        ui->list_deposit->addItem(QString::fromStdString(Daccount->newAccount.getCard_number()));
        Daccount = Daccount->next;
    }
}

account_costumer_list::~account_costumer_list()
{
    delete ui;
}

void account_costumer_list::on_toolButton_clicked()
{
    costumer_page* newpage = new costumer_page;
    newpage->show();
    this->close();
}

