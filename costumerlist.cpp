#include "costumerlist.h"
#include "list.h"
#include <QDebug>
CostumerList::CostumerList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

void CostumerList::Pushback(string name, string lastname, string nationalcode, string password, string username, int age){

    CNode* newcostumer = new CNode;

    newcostumer->newcostumer.setName(name);
    newcostumer->newcostumer.setLastname(lastname);
    newcostumer->newcostumer.setNationalCode(nationalcode);
    newcostumer->newcostumer.setAge(age);
    newcostumer->newcostumer.setUsername(username);
    newcostumer->newcostumer.setpassword(password);


    newcostumer->next = nullptr;

    if(this->size == 0){
        this->tail = this->head = newcostumer;
        newcostumer->next = this->tail;
    }
    else{

        this->tail->next = newcostumer;
        this->tail = newcostumer;
    }

    this->size++;
}

int CostumerList::getSize(){ return this->size; }

CNode* CostumerList::getHead(){ return this->head; }

void CostumerList::show(){

    CNode* newcostumer = CList->getHead();
    for(int i=0; i<CList->getSize(); i++){
        qDebug() << newcostumer->newcostumer.getName();
    }
}

void CostumerList::deleteData(QListWidgetItem* citem){

    int ptr = 0;

    CNode* newcostumer = this->head;
    CNode* newcostumer1 = this->head->next;

    if(newcostumer->newcostumer.getUsername() == citem->text().toStdString()){
        this->head = newcostumer->next;
        delete newcostumer;
    }

    else{

        for(int i=1; i<this->size; i++){
            if(newcostumer1->newcostumer.getUsername() == citem->text().toStdString()){
                ptr = i;
                break;
            }
            newcostumer = newcostumer->next;
            newcostumer1 = newcostumer1->next;
        }
    }


    if(ptr == this->size){
        this->tail = newcostumer;
        newcostumer->next = newcostumer1->next;
        delete newcostumer1;
    }

    else if(ptr != 0){
        newcostumer->next = newcostumer1->next;
        delete newcostumer1;
    }

    this->size--;
}
