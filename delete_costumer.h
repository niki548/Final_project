#ifndef DELETE_COSTUMER_H
#define DELETE_COSTUMER_H

#include <QDialog>

namespace Ui {
class delete_costumer;
}

class delete_costumer : public QDialog
{
    Q_OBJECT

public:
    explicit delete_costumer(QWidget *parent = nullptr);
    ~delete_costumer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_toolButton_clicked();

private:
    Ui::delete_costumer *ui;
};

#endif // DELETE_COSTUMER_H
