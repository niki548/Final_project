#include "user.h"

user::user() {}

#include "user.h"
using namespace std;

void user::setAge(int age) { this->age = age; }

void user::setLastname(string lastname) { this->lastname = lastname; }

void user::setName(string name) { this->name = name; }

void user::setNationalCode(string NationalCode) { this->NationalCode = NationalCode; }

void user::setpassword(string password) { this->password = password; }

void user::setUsername(string username) { this->username = username; }

string user::getName() { return this->name; }

string user::getLastname() { return this->lastname; }

string user::getNationalCode() { return this->NationalCode; }

string user::getUsername() { return this->username; }

string user::getPassword() { return this->password; }

int user::getAge() { return this->age; }
