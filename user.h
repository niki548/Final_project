#ifndef USER_H
#define USER_H
#pragma once


#include <QMainWindow>
#include <QObject>
#include <QWidget>
using namespace std;

class User
{
private:
    string name;
    string lastname;
    string NationalCode;
    string username;
    string password;
    int age;
public:
    User();
    void setName(string name);
    void setLastname(string lastname);
    void setNationalCode(string NationalCode);
    void setUsername(string username);
    void setpassword(string password);
    void setAge(int age);
    string getName();
    string getLastname();
    string getNationalCode();
    string getUsername();
    string getPassword();
    int getAge();
    static void signin_admin(string name, string lastname, string nationalcode, string password, string username, int age);
    static bool login_admin(string username, string password);
    static bool login_costumer(string username, string password);
};

#endif // USER_H
