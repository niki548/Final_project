#ifndef ADMIN_LIST_H
#define ADMIN_LIST_H

#include <QDialog>

namespace Ui {
class admin_list;
}

class admin_list : public QDialog
{
    Q_OBJECT

public:
    explicit admin_list(QWidget *parent = nullptr);
    ~admin_list();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::admin_list *ui;
};

#endif // ADMIN_LIST_H
