#ifndef USERLIST_H
#define USERLIST_H
#pragma once
#include "user.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
using namespace std;

class Node {
public:
    User newuser;
    Node* next;
};

class UserList
{    
public:
    int size;
    Node* head;
    Node* tail;
    UserList();
    void pushBack(string name, string lastname, string nationalcode, string password, string username, int age);
    int getSize();

};

#endif // USERLIST_H
