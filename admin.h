#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListWidgetItem>
#include "user.h"
class Admin :public User
{
public:
    Admin();
    static void AddCostumer(string name, string lastname, string nationalcode, string username, string password, int age);
    static void deleteCostumer(QListWidgetItem* item);
    static string current_admin_username;
    static string current_admin_password;
};

#endif // ADMIN_H
