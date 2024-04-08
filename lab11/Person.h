#pragma once
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(string _name, int _age) {
		name = _name;
		age = _age;
	}
	void info() {
		cout << name << " " << age << endl;
	}
};

