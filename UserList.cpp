#include <iostream>
#include "User.h"
using namespace std;
class Node {
public:
	User newUser;
	Node* next;
};
class userlist {
	int size;
	Node* head;
	Node* tail;
public:
	userlist() {
		this->head = this->tail = nullptr;
		this->size = 0;
	}
	void addFront() {
		string name, lastname, NationalCode, username, password;
		int age;
		cout << "pleas enter your name: ";
		cin >> name;
		cout << "pleas enter your lastname: ";
		cin >> lastname;
		cout << "pleas enter yor national code: ";
		cin >> NationalCode;
		cout << "pleas enter your age: ";
		cin >> age;
		cout << "pleas enter your username: ";
		cin >> username;
		cout << "pleas enter your password: ";
		cin >> password;
		Node* newuser = new Node;

	}
	void pushBack() {

	}
};