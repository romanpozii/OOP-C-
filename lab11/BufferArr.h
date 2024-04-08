#pragma once
#include <iostream>
#include <vector>
#include "Buffer.h"

using namespace std;

class BufferArr : public Buffer
{
private:
	vector<int> elements;
	size_t capacity;
public:
	BufferArr(size_t size) : capacity(size) {
		cout << "Konstruktor klasy BufferArr" << endl;
	}
	~BufferArr() {
		cout << "Destruktor klasy BufferArr" << endl;
	}

	void add(int a) override {
		if (elements.size() < capacity) {
			elements.push_back(a);
		}
		else {
			cout << "Nie mozna dodac elementu tablica jest pelna" << endl;
		}
	}

	void write() const override {
		cout << "Elementy w BufferArr: ";
		for (int element : elements) {
			cout << element << " ";
		}
		cout << endl;
	}

	const vector<int>& getElements() const {
		return elements;
	}

	void setElements(const vector<int>& newElements) {
		elements = newElements;
	}
};

