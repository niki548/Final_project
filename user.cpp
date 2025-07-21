#include "user.h"
#include "admin_page.h"
#include <QMessageBox>
/*#include "userlist.h"
#include "adminlist.h"
#include "costumerlist.h"*/
#include "List.h"
#include "costumer_page.h"

/*UserList *UList = new UserList ;
AdminList* AList = new AdminList;
CostumerList* CList = new CostumerList;*/

User::User() {}

void User::setAge(int age) { this->age = age; }

void User::setLastname(string lastname) { this->lastname = lastname; }

void User::setName(string name) { this->name = name; }

void User::setNationalCode(string NationalCode) { this->NationalCode = NationalCode; }

void User::setpassword(string password) { this->password = password; }

void User::setUsername(string username) { this->username = username; }

string User::getName() { return this->name; }

string User::getLastname() { return this->lastname; }

string User::getNationalCode() { return this->NationalCode; }

string User::getUsername() { return this->username; }

string User::getPassword() { return this->password; }

int User::getAge() { return this->age; }

void User::signin_admin(string name, string lastname, string nationalcode, string password, string username, int age){

    UList->pushBack(name,lastname,nationalcode,password,username,age);
    AList->Pushback(name,lastname,nationalcode,password,username,age);

    QMessageBox* box = new QMessageBox;
    box->setText("signin was sucssesfully.");
    box->show();
}

bool User::login_admin(string username, string password){
    bool status = false;

    ANode* newadmin = AList->getHead();
    for(int i=0; i< AList->getSize();i++){
        if(username == newadmin->newadmin.getUsername() && password == newadmin->newadmin.getPassword()){
            admin_page* newpage = new admin_page;
            newpage->show();
            status = true;
        }
        newadmin = newadmin->next;
    }
    return status;
}

bool User::login_costumer(string username, string password){

    bool status = false;

   CNode* newcostumer = CList->getHead();
    for(int i=0; i< CList->getSize();i++){
        if(username == newcostumer->newcostumer.getUsername() && password == newcostumer->newcostumer.getPassword()){
            costumer_page* newpage = new costumer_page;
            newpage->show();
            //this->close();
            status = true;
        }
        newcostumer = newcostumer->next;
    }
}
