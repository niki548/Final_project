#include "costumer_page.h"
#include "ui_costumer_page.h"
#include "change_costumer_password.h"
#include "costumer_special_account.h"
#include "card_to_card_page.h"
#include "change_second_pass.h"
#include "first_page.h"
#include "account_costumer_list.h"

costumer_page::costumer_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::costumer_page)
{
    ui->setupUi(this);
}

costumer_page::~costumer_page()
{
    delete ui;
}




void costumer_page::on_change_pass_clicked()
{
    change_costumer_password* newpage = new change_costumer_password;
    newpage->show();
    this->close();
}


void costumer_page::on_epecial_account_clicked()
{
    costumer_account_list* newpage = new costumer_account_list;
    newpage->show();
    this->close();
}



void costumer_page::on_account_list_clicked()
{
    account_costumer_list* newpage = new account_costumer_list;
    newpage->show();
    this->close();
}


void costumer_page::on_change_second_pass_clicked()
{
    change_second_pass* newpage = new change_second_pass;
    newpage->show();
    this->close();
}


void costumer_page::on_card_to_card_clicked()
{
    card_to_card_page* newpage = new card_to_card_page;
    newpage->show();
    this->close();
}



void costumer_page::on_toolButton_clicked()
{
    first_page* newpage = new first_page;
    newpage->show();
    this->close();
}

