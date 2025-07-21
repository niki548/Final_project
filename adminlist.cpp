#include "adminlist.h"
using namespace std;
AdminList::AdminList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

void AdminList::Pushback(string name, string lastname, string nationalcode, string password, string username, int age){

    ANode* newadmin = new ANode;

    newadmin->newadmin.setName(name);
    newadmin->newadmin.setLastname(lastname);
    newadmin->newadmin.setNationalCode(nationalcode);
    newadmin->newadmin.setAge(age);
    newadmin->newadmin.setUsername(username);
    newadmin->newadmin.setpassword(password);

    newadmin->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newadmin;
        newadmin->next = this->tail;
    }
    else{

        this->tail->next = newadmin;
        this->tail = newadmin;
    }

    this->size++;
}

int AdminList::getSize(){ return this->size; }

ANode* AdminList::getHead(){ return this->head; }
