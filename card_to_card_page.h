#ifndef CARD_TO_CARD_PAGE_H
#define CARD_TO_CARD_PAGE_H

#include <QDialog>
#include "List.h"
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class card_to_card_page;
}

class card_to_card_page : public QDialog
{
    Q_OBJECT

public:
    explicit card_to_card_page(QWidget *parent = nullptr);
    ~card_to_card_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::card_to_card_page *ui;
    CNode* CurrentCostumer;
    CNode* newCostumer;
    string type;
    string Ctype;
    BNode* Baccount;
    LNode* Laccount;
    DNode* Daccount;
    BNode* CBaccount;
    LNode* CLaccount;
    DNode* CDaccount;
    QLabel* label = new QLabel(this);
    QLineEdit* line = new QLineEdit(this);
};

#endif // CARD_TO_CARD_PAGE_H
