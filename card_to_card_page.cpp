#include "card_to_card_page.h"
#include "ui_card_to_card_page.h"
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QStringList>
#include <QDateEdit>
#include <QMessageBox>
#include <QRandomGenerator>
#include "costumer_page.h"

card_to_card_page::card_to_card_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::card_to_card_page)
{
    ui->setupUi(this);
    this->Baccount = nullptr;
    this->Daccount = nullptr;
    this->Laccount = nullptr;
    type = "unknown";
    CurrentCostumer = CList->getHead();
    for(int i=0; i<CList->getSize(); i++){
        if(Costumer::current_costumer_password == CurrentCostumer->newcostumer.getPassword() && Costumer::current_costumer_username == CurrentCostumer->newcostumer.getUsername()){
            break;
        }
        CurrentCostumer = CurrentCostumer->next;
    }
}

card_to_card_page::~card_to_card_page()
{
    delete ui;
}

void card_to_card_page::on_pushButton_clicked()
{
    string cardNumber = ui->ln_card_number->text().toStdString();
    string CcardNumber = ui->ln_origin->text().toStdString();
    bool status = false;
    bool e_date = true;
//finding destnation account
    newCostumer = CList->getHead();
    Baccount = newCostumer->newcostumer.BList->getHead();
    Laccount = newCostumer->newcostumer.LList->getHead();
    Daccount = newCostumer->newcostumer.DList->getHead();

        for(int i=0; i<CList->getSize(); i++){

        Baccount = newCostumer->newcostumer.BList->getHead();
        Laccount = newCostumer->newcostumer.LList->getHead();
        Daccount = newCostumer->newcostumer.DList->getHead();

            for(int j=0; j<newCostumer->newcostumer.BList->getSize(); j++){
                if(cardNumber == Baccount->newAccount.getCard_number()){
                    type = "current";
                    status = true;
                    QString fullName = QString::fromStdString(newCostumer->newcostumer.getName()) + " " + QString::fromStdString(newCostumer->newcostumer.getLastname());
                    QLabel* name_label = new QLabel(this);
                    name_label->setText(fullName);
                    name_label->setGeometry(110,160,191,20);
                    name_label->show();
                    break;
                }
                Baccount = Baccount->next;
            }

            for(int j=0; j<newCostumer->newcostumer.LList->getSize(); j++){
                if(cardNumber == Laccount->newAccount.getCard_number()){
                    type = "loan";
                    status = true;
                    QString fullName = QString::fromStdString(newCostumer->newcostumer.getName()) + " " + QString::fromStdString(newCostumer->newcostumer.getLastname());
                    QLabel* name_label = new QLabel(this);
                    name_label->setText(fullName);
                    name_label->setGeometry(110,160,191,20);
                    name_label->show();
                    status = true;
                    break;
                }
                Laccount = Laccount->next;
            }

            for(int j=0; j<newCostumer->newcostumer.DList->getSize(); j++){
                if(cardNumber == Daccount->newAccount.getCard_number()){
                    type = "deposit";
                    status = true;
                    QString fullName = QString::fromStdString(newCostumer->newcostumer.getName()) + " " + QString::fromStdString(newCostumer->newcostumer.getLastname());
                    QLabel* name_label = new QLabel(this);
                    name_label->setText(fullName);
                    name_label->setGeometry(110,160,191,20);
                    name_label->show();
                    status = true;
                    break;
                }
                Daccount = Daccount->next;
            }
            newCostumer = newCostumer->next;
        }
        //findin origin account
        CBaccount = CurrentCostumer->newcostumer.BList->getHead();
        CLaccount = CurrentCostumer->newcostumer.LList->getHead();
        CDaccount = CurrentCostumer->newcostumer.DList->getHead();

        for(int i=0; i<CurrentCostumer->newcostumer.BList->getSize(); i++){
            if(CcardNumber == CBaccount->newAccount.getCard_number()){
                Ctype = "current";
                break;
            }
            CBaccount = CBaccount->next;
        }

        for(int i=0; i<CurrentCostumer->newcostumer.LList->getSize(); i++){
            if(CcardNumber == CLaccount->newAccount.getCard_number()){
                Ctype = "loan";
                break;
            }
            CLaccount = CLaccount->next;
        }

        for(int i=0; i<CurrentCostumer->newcostumer.DList->getSize(); i++){
            if(CcardNumber == CDaccount->newAccount.getCard_number()){
                Ctype = "deposit";
                break;
            }
            CDaccount = CDaccount->next;
        }
        //if thie destnation card number was wrong
        if(status == false){
            QLabel* eror_label = new QLabel(this);
            eror_label->setText("The card number is invalid.");
            eror_label->setGeometry(110,160,191,20);
            //eror_label-> red color text
            eror_label->show();
        }
// checking date of origin account
        else if(status == true){

            if(Ctype == "current"){
                QStringList date = QString::fromStdString(CBaccount->newAccount.getExpiration_date()).split("/");

                int year = date.at(0).toInt();
                int month = date.at(1).toInt();

                int currentMonth = QDate::currentDate().month();
                int currentYear = QDate::currentDate().year();

                if(year < currentYear){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
                else if(year == currentYear && month < currentMonth){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
            }

            else if(Ctype == "loan"){

                QStringList date = QString::fromStdString(CLaccount->newAccount.getExpiration_date()).split("/");

                int year = date.at(0).toInt();
                int month = date.at(1).toInt();

                int currentMonth = QDate::currentDate().month();
                int currentYear = QDate::currentDate().year();

                if(year < currentYear){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
                else if(year == currentYear && month < currentMonth){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
            }

            else if(Ctype == "deposit"){

                QStringList date = QString::fromStdString(CDaccount->newAccount.getExpiration_date()).split("/");

                int year = date.at(0).toInt();
                int month = date.at(1).toInt();

                int currentMonth = QDate::currentDate().month();
                int currentYear = QDate::currentDate().year();

                if(year < currentYear){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
                else if(year == currentYear && month < currentMonth){
                    e_date = false;
                    QMessageBox* box = new QMessageBox;
                    box->setText("The card has expired.");
                    box->setWindowTitle("Date eror");
                    box->show();
                }
            }
        }
// if date and card number was right checking money
        if(status == true && e_date == true){
            int cash = ui->ln_cash->text().toInt();

            if(cash <= 100000){

                label->setText("second fixed password");
                label->setGeometry(110,360,181,20);
                label->show();

                line->setGeometry(110,380,251,28);
                line->show();
            }

            if(cash > 100000){

                label->setText("second Dynamic password");
                label->setGeometry(110,360,181,20);
                label->show();

                line->setGeometry(110,380,251,28);
                line->show();
            }
        }
}


void card_to_card_page::on_pushButton_3_clicked()
{
    double cash = ui->ln_cash->text().toDouble();
    if(cash <= 100000){

        if(Ctype == "current"){
            if(line->text().toStdString() == CBaccount->newAccount.getFixed_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CBaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CBaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Baccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Baccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }

        else if(Ctype == "loan"){
            if(line->text().toStdString() == CLaccount->newAccount.getFixed_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CLaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CLaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Laccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Laccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }

        else if(Ctype == "deposit"){
            if(line->text().toStdString() == CDaccount->newAccount.getFixed_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CDaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CDaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Daccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Daccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }
    }

    else if(cash > 100000){
        string Dpassword = line->text().toStdString();
        if(Ctype == "current"){
            if(Dpassword == CBaccount->newAccount.getDynamic_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CBaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CBaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Baccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Baccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }

        else if(Ctype == "loan"){
            if(Dpassword == CLaccount->newAccount.getDynamic_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CLaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CLaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Laccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Laccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }

        else if(Ctype == "deposit"){
            if(Dpassword == CDaccount->newAccount.getDynamic_second_password()){
                //Deduct the amount from the original account.
                int CMoney = stoi(CDaccount->newAccount.getCash());
                int CRemMoney = CMoney - cash;
                CDaccount->newAccount.setCash(to_string(CRemMoney));
                //Add amount from destination account
                cash -= 0.0001;
                int Money = stoi(Daccount->newAccount.getCash());
                double RemMoney = Money + cash;
                Daccount->newAccount.setCash(to_string(RemMoney));
            }
            else{
                QMessageBox* box = new QMessageBox;
                box->setText("The password is invalid.");
                box->setWindowTitle("password eror");
                box->show();
            }
        }
    }

    QMessageBox* box = new QMessageBox;
    box->setText("Payment was successful.");
    box->show();
}



void card_to_card_page::on_pushButton_2_clicked()
{
    if(Ctype == "current"){
        CBaccount->newAccount.setDynamic_second_password(to_string(QRandomGenerator::global()->bounded(100000,1000000)));
        QMessageBox* box = new QMessageBox;
        box->setText(QString::fromStdString(CBaccount->newAccount.getDynamic_second_password()));
        box->setWindowTitle("dynamic password");
        box->show();
    }

    else if(Ctype == "loan"){
        CLaccount->newAccount.setDynamic_second_password(to_string(QRandomGenerator::global()->bounded(100000,1000000)));
        QMessageBox* box = new QMessageBox;
        box->setText(QString::fromStdString(CLaccount->newAccount.getDynamic_second_password()));
        box->setWindowTitle("dynamic password");
        box->show();
    }

    else if(Ctype == "deposit"){
        CDaccount->newAccount.setDynamic_second_password(to_string(QRandomGenerator::global()->bounded(100000,1000000)));
        QMessageBox* box = new QMessageBox;
        box->setText(QString::fromStdString(CDaccount->newAccount.getDynamic_second_password()));
        box->setWindowTitle("dynamic password");
        box->show();
    }
}


void card_to_card_page::on_toolButton_clicked()
{
    costumer_page* newpage = new costumer_page;
    newpage->show();
    this->close();
}

