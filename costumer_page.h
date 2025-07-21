#ifndef COSTUMER_PAGE_H
#define COSTUMER_PAGE_H

#include <QDialog>

namespace Ui {
class costumer_page;
}

class costumer_page : public QDialog
{
    Q_OBJECT

public:
    explicit costumer_page(QWidget *parent = nullptr);
    ~costumer_page();

private slots:

    void on_change_pass_clicked();

    void on_epecial_account_clicked();

    void on_account_list_clicked();

    void on_change_second_pass_clicked();

    void on_card_to_card_clicked();

    void on_toolButton_clicked();

private:
    Ui::costumer_page *ui;
};

#endif // COSTUMER_PAGE_H
