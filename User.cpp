#include "User.h"
#include <iostream>
using namespace std;
void User::setAge(int age) { this->age = age; }

void User::setLastname(string lastname) { this->lastname = lastname; }

void User::setName(string name) { this->name = name; }

void User::setNationalCode(string NationalCode) { this->NationalCode = NationalCode; }

void User::setpassword(string password) { this->password = password; }

void User::setUsername(string username) { this->username = username; }

string User::getName() { return this->name; }

string User::getLastname() { return this->lastname; }

string User::getNationalCode() { return this->NationalCode; }

string User::getUsername() { return this->username; }

string User::getPassword() { return this->password; }

int User::getAge() { return this->age; }