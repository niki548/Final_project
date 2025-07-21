#ifndef CHANGE_ADMIN_INFO_H
#define CHANGE_ADMIN_INFO_H

#include <QDialog>
#include "adminlist.h"

namespace Ui {
class change_admin_info;
}

class change_admin_info : public QDialog
{
    Q_OBJECT

public:
    explicit change_admin_info(QWidget *parent = nullptr);
    ~change_admin_info();

private slots:
    void on_t_name_clicked();

    void on_t_lastname_clicked();

    void on_t_code_clicked();

    void on_t_age_clicked();

    void on_t_username_clicked();

    void on_t_password_clicked();

    void on_toolButton_clicked();

private:
    Ui::change_admin_info *ui;
    ANode* newadmin;
};

#endif // CHANGE_ADMIN_INFO_H
