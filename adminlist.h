#ifndef ADMINLIST_H
#define ADMINLIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "admin.h"

class ANode{
public:
    Admin newadmin;
    ANode* next;
};

class AdminList
{
private:
    ANode* head;
    ANode* tail;
    int size;
public:
    AdminList();
    void Pushback(string name, string lastname, string nationalcode, string password, string username, int age);
    int getSize();
    ANode* getHead();
};

#endif // ADMINLIST_H
