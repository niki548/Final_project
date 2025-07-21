#include "userlist.h"

UserList::UserList() {
    this->tail = this->head = nullptr;
    this->size = 0;
}

void UserList::pushBack(string name, string lastname, string nationalcode, string password, string username, int age){
    Node* newuser = new Node;
    newuser->newuser.setName(name);
    newuser->newuser.setLastname(lastname);
    newuser->newuser.setNationalCode(nationalcode);
    newuser->newuser.setAge(age);
    newuser->newuser.setUsername(username);
    newuser->newuser.setpassword(password);

    newuser->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newuser;
        newuser->next = this->tail;
    }
    else{

        this->tail->next = newuser;
        this->tail = newuser;
    }

    this->size++;
}

int UserList::getSize(){ return this->size; }
