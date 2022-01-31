/*
 * List
 *
 *  Created on: Jan 26, 2020
 *      Author: joene
 */

#ifndef LIST_
#define LIST_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using std::cout;
using std::stringstream;
using std::cin;
using std::endl;
using std::string;
using std::ostream


class list {
public:
	list();
	friend ostream& operator<<(ostream& os, const list& obj);
	bool find(string uid);
	bool insert(string uid, int security);
	bool insertBefore(string uid, int security, string uid2);
	bool insertAfter(string uid, int security, string uid2);
	bool remove(string uid);


private:
	class node {
	public:
		string id;
		int sec;
		node* next;
		node* prev;
	};

	node* head;
	node* tail;

};



list::list() {
	head = nullptr;
	tail = nullptr;
}




bool list::find(string uid) {
	node* curNode = head;
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return false;
	}

	while (curNode->id != uid)
	{
		if (curNode == nullptr)
		{
			cout << "ID not found." << endl;
			return false;
		}
		curNode = curNode->next;
	}
	cout << "Found ID, security level is: " << curNode->sec << endl;
	return true;
}

bool list::insert(string uid, int security) {
	node* newNode = new node();
	newNode->id = uid;
	newNode->sec = security;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}


bool list::remove(string uid) {
	node* curNode = head;
	if (head == nullptr) {
		cout << "empty list" << endl;
		return false;
	}
	while (curNode->id != uid)
	{
		if (curNode == nullptr)
		{
			cout << "ID not found." << endl;
			return false;
		}
		curNode = curNode->next;
	}
	if (curNode == head) {
		node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr) {
			tail = nullptr;
		}
		return true;
	}

	if (curNode == tail)
	{
		node* temp2 = tail;
		tail = tail->prev;
		delete temp2;
		return true;
	}
	curNode->next->prev = curNode->prev;
	curNode->prev->next = curNode->next;
	return true;


	delete curNode;

}


bool list::insertBefore(string uid, int security, string uid2) {
	if (head == nullptr) {
		cout << "Empty list" << endl;
		return false;
	}

	node* curNode = head;
	while (curNode != nullptr)
	{
		if (curNode->id == uid2)
		{
			node* newNode = new node();
			newNode->id = uid;
			newNode->sec = security;

			if (curNode == head) {
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
			}


			else {
				curNode->prev->next = newNode;
				newNode->prev = curNode->prev;
				curNode->prev = newNode;
				newNode->next = curNode;

			}
			return true;
		}
		curNode = curNode->next;
	}
	return false;


}


bool list::insertBefore(string uid, int security, string uid2) {
	if (head == nullptr) {
		cout << "Empty list" << endl;
		return false;
	}

	node* curNode = head;
	while (curNode != nullptr)
	{
		if (curNode->id == uid2)
		{
			node* newNode = new node();
			newNode->id = uid;
			newNode->sec = security;

			if (curNode == tail) {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}


			else {
				curNode->next->prev = newNode;
				newNode->next = curNode->next;
				curNode->next = newNode;
				newNode->prev = curNode;

			}
			return true;
		}
		curNode = curNode->next;
	}
	return false;


}




#endif /* LIST_ */
