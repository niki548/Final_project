#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void signin_admin_1();
    void login_admin_1();

private slots:
    void on_signin_btn_clicked();

    void on_login_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // ADMIN_LOGIN_H
