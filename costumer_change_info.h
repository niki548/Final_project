#ifndef COSTUMER_CHANGE_INFO_H
#define COSTUMER_CHANGE_INFO_H

#include <QDialog>
#include "costumerlist.h"
namespace Ui {
class costumer_change_info;
}

class costumer_change_info : public QDialog
{
    Q_OBJECT

public:
    explicit costumer_change_info(QWidget *parent = nullptr);
    ~costumer_change_info();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_toolButton_name_clicked();

    void on_toolButton_lastname_clicked();

    void on_toolButton_code_clicked();

    void on_toolButton_age_clicked();

    void on_toolButton_username_clicked();

    void on_toolButton_password_clicked();

    void on_toolButton_clicked();

private:
    Ui::costumer_change_info *ui;
    CNode* newcostumer;
};

#endif // COSTUMER_CHANGE_INFO_H
