#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
using namespace std;

class user
{
private:
    string name;
    string lastname;
    string NationalCode;
    string username;
    string password;
    int age;
public:
    user();
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
};

#endif // USER_H
