#ifndef COSTUMERLIST_H
#define COSTUMERLIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListWidgetItem>
#include "costumer.h"

class CNode{
public:
    Costumer newcostumer;
    CNode* next;
};

class CostumerList
{
private:
    CNode* head;
    CNode* tail;
    int size;
public:
    CostumerList();
    void Pushback(string name, string lastname, string nationalcode, string password, string username, int age);
    void deleteData(QListWidgetItem* citem);
    int getSize();
    CNode* getHead();
    void show();
};

#endif // COSTUMERLIST_H
