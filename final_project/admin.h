#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Admin : public user
{
public:
    Admin();
    void viewAllUser();
    void viewAllAcount();
    void CustomerRegistration();
    void deleteCostumer();
    void viewAdminList();
    void changeMyInformation();
    void changeCostumerInformation();
    void ViewSpecificBankAccount();
};

#endif // ADMIN_H
