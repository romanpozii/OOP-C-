#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	shared_ptr<Node<T>> next;
	shared_ptr<Node<T>> prev;

	Node(const T& value) : data(value), next(nullptr), prev(nullptr) {
		cout << "Konstruktor klasy Node dla wartosci: " << value << endl;
	}

	~Node() {
		cout << "Destruktor klasy Node" << endl;
	}
};

