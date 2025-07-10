#ifndef USERLIST_H
#define USERLIST_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QWidget>
#include "user.h"
using namespace std;

class Node {
public:
    user newUser;
    Node* next;
};

class userlist
{
private:
    int size;
    Node* head;
    Node* tail;
public:
    userlist();
    void addFront();
    void pushBack();

};

#endif // USERLIST_H
