#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QDialog>

namespace Ui {
class admin_page;
}

class admin_page : public QDialog
{
    Q_OBJECT

public:
    explicit admin_page(QWidget *parent = nullptr);
    ~admin_page();

private slots:

    void on_add_costumer_clicked();

    void on_remove_cos_clicked();

    void on_change_my_info_clicked();

    void on_change_cos_info_clicked();

    void on_admin_list_clicked();

    void on_deposit_btn_clicked();

    void on_current_btn_clicked();

    void on_loan_btn_clicked();

    void on_list_acount_clicked();

    void on_veiw_user_acount_clicked();

    void on_information_special_acount_clicked();

    void on_toolButton_clicked();

private:
    Ui::admin_page *ui;
};

#endif // ADMIN_PAGE_H
