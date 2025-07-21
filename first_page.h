#ifndef FIRST_PAGE_H
#define FIRST_PAGE_H

#include <QDialog>

namespace Ui {
class first_page;
}

class first_page : public QDialog
{
    Q_OBJECT

public:
    explicit first_page(QWidget *parent = nullptr);
    ~first_page();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::first_page *ui;
};

#endif // FIRST_PAGE_H
