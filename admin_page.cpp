#include "admin_page.h"
#include "ui_admin_page.h"
#include "signin_costumer.h"
#include "delete_costumer.h"
#include "change_admin_info.h"
#include "costumer_change_info.h"
#include "admin_list.h"
#include "diposit_account_page.h"
#include "loan_account_page.h"
#include "current_account_page.h"
#include "list_account_page.h"
#include "account_with_costumer.h"
#include "special_account_page.h"
#include "first_page.h"

admin_page::admin_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_page)
{
    ui->setupUi(this);
}

admin_page::~admin_page()
{
    delete ui;
}




void admin_page::on_add_costumer_clicked()
{
    signin_costumer* newpage = new signin_costumer;
    newpage->show();
    this->close();
}



void admin_page::on_remove_cos_clicked()
{
    delete_costumer* newpage = new delete_costumer;
    newpage->show();
    this->close();
}


void admin_page::on_change_my_info_clicked()
{
    change_admin_info* newpage = new change_admin_info;
    newpage->show();
    this->close();

}


void admin_page::on_change_cos_info_clicked()
{
    costumer_change_info* newpage = new costumer_change_info;
    newpage->show();
    this->close();
}


void admin_page::on_admin_list_clicked()
{
    admin_list* newpage = new admin_list;
    newpage->show();
    this->close();
}


void admin_page::on_deposit_btn_clicked()
{
    diposit_account_page* newpage = new diposit_account_page;
    newpage->show();
    this->close();
}


void admin_page::on_current_btn_clicked()
{
    Current_account_page* newpage = new Current_account_page;
    newpage->show();
    this->close();
}


void admin_page::on_loan_btn_clicked()
{
    Loan_account_page* newpage = new Loan_account_page;
    newpage->show();
    this->close();
}


void admin_page::on_list_acount_clicked()
{
    List_account_page* newpage = new List_account_page;
    newpage->show();
    this->close();
}


void admin_page::on_veiw_user_acount_clicked()
{
    account_with_costumer* newpage = new account_with_costumer;
    newpage->show();
    this->close();
}


void admin_page::on_information_special_acount_clicked()
{
    especial_account_page* newpage = new especial_account_page;
    newpage->show();
    this->close();
}


void admin_page::on_toolButton_clicked()
{
    first_page* newpage = new first_page;
    newpage->show();
    this->close();
}

