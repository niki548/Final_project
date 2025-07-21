#include "list_account_page.h"
#include "ui_list_account_page.h"
#include "List.h"
#include "admin_page.h"
#include <QListWidgetItem>

List_account_page::List_account_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::List_account_page)
{
    ui->setupUi(this);

    CNode *newcostumer = CList->getHead();
    BNode* bnewaccount;

    for(int i=0; i<CList->getSize(); i++){
        bnewaccount = newcostumer->newcostumer.BList->getHead();
        for (int i=0; i< newcostumer->newcostumer.BList->getSize(); i++){
            ui->list_current->addItem(QString::fromStdString(bnewaccount->newAccount.getCard_number()));
            bnewaccount = bnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }

    newcostumer = CList->getHead();

    LNode* lnewaccount;
    for(int i=0; i<CList->getSize(); i++){
        lnewaccount = newcostumer->newcostumer.LList->getHead();
        for (int i=0; i< newcostumer->newcostumer.LList->getSize(); i++){
            ui->list_loan->addItem(QString::fromStdString(lnewaccount->newAccount.getCard_number()));
            lnewaccount = lnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }

    newcostumer = CList->getHead();

    DNode* dnewaccount = newcostumer->newcostumer.DList->getHead();

    for(int i=0; i<CList->getSize(); i++){
        dnewaccount = newcostumer->newcostumer.DList->getHead();
        for (int i=0; i< newcostumer->newcostumer.DList->getSize(); i++){
            ui->list_deposit->addItem(QString::fromStdString(dnewaccount->newAccount.getCard_number()));
            dnewaccount = dnewaccount->next;
        }
        newcostumer = newcostumer->next;
    }

}

List_account_page::~List_account_page()
{
    delete ui;
}

void List_account_page::on_toolButton_clicked()
{
    admin_page* newpage = new admin_page;
    newpage->show();
    this->close();
}

