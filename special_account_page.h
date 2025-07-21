#ifndef SPECIAL_ACCOUNT_PAGE_H
#define SPECIAL_ACCOUNT_PAGE_H

#include <QDialog>

namespace Ui {
class especial_account_page;
}

class especial_account_page : public QDialog
{
    Q_OBJECT

public:
    explicit especial_account_page(QWidget *parent = nullptr);
    ~especial_account_page();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::especial_account_page *ui;
};

#endif // SPECIAL_ACCOUNT_PAGE_H
