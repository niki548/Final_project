#pragma once
#include <iostream>
using namespace std;
class User
{
private:
	string name;
	string lastname;
	string NationalCode;
	string username;
	string password;
	int age;
public:
	void setName(string name);
	void setLastname(string lastname);
	void setNationalCode(string NationalCode);
	void setUsername(string username);
	void setpassword(string password);
	void setAge(int age);
	string getName();
	string getLastname();
	string getNationalCode();
	string getUsername();
	string getPassword();
	int getAge();
};
