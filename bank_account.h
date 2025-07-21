#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
using namespace std;

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Bank_account
{
private:
    string card_number;
    string shaba_number;
    string account_number;
    string cvv2;
    string cash;
    string expiration_date;
    string pin;
    string fixed_second_password;
    string dynamic_second_password;
public:
    Bank_account();
    virtual void account_profit(){};
    void setCard_number(string card_number);
    void setShaba_number(string shaba_number);
    void setAccount_number(string account_number);
    void setCvv2(string cvv2r);
    void setCash(string cash);
    void setExpiration_date(string expiration_date);
    void setPin(string pin);
    void setFixed_second_password(string fixed_second_password);
    void setDynamic_second_password(string dynamic_second_password);
    string getCard_number();
    string getShaba_number();
    string getAccount_number();
    string getCvv2();
    string getCash();
    string getExpiration_date();
    string getPin();
    string getFixed_second_password();
    string getDynamic_second_password();
    virtual void profit(){}
    string mprofit;
};

#endif // BANK_ACCOUNT_H
