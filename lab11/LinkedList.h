#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList
{
private:
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> tail;
public:
	LinkedList() : head(nullptr), tail(nullptr) {
		cout << "Konstruktor klasy LinkedList" << endl;
	}

	~LinkedList() {
		cout << "Destruktor klasy LinkedList" << endl;
	}

	void addToFront(const T& value) {
		auto newNode = make_shared<Node<T>>(value);
		if (!head) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void addToBack(const T& value) {
		auto newNode = make_shared<Node<T>>(value);
		if (!tail) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void removeFromFront() {
		if (!head) {
			cout << "Lista jest pusta. Nie da sie usunac pierwszy element" << endl;
			return;
		}
		auto temp = head;
		head = head->next;
		if (head) {
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
	}

	void removeFromBack() {
		if (!tail) {
			cout << "Lista jest pusta. Nie da sie usunac ostatni element" << endl;
			return;
		}

		auto temp = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
	}

	void displayList() const {
		auto current = head;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	bool isEmpty() const {
		return head == nullptr;
	}

};

