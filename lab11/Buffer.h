#pragma once
#include <iostream>

using namespace std;

class Buffer
{
public:
	virtual void add(int a) = 0;
	virtual void write() const = 0;
	Buffer() {
		cout << "Konstruktor Buffer" << endl;
	}
	~Buffer() {
		cout << "Destruktor Buffer" << endl;
	}
};

