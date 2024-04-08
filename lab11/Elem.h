#pragma once
#include <iostream>

using namespace std;

class Elem {
public:
	shared_ptr<Elem> next;
	shared_ptr<Elem> prev;
	~Elem() {
		cout << "Destruktor Elem" << endl;
	}
};