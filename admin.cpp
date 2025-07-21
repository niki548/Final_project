#include "admin.h"
#include "List.h"
Admin::Admin() {}

string Admin::current_admin_password = "0";
string Admin::current_admin_username = "0";

void Admin::AddCostumer(string name, string lastname, string nationalcode, string username, string password, int age){

    CList->Pushback(name,lastname,nationalcode,password,username,age);

}

void Admin::deleteCostumer(QListWidgetItem* citem){

    CList->deleteData(citem);
}
