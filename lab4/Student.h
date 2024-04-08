#pragma once
#include <iostream>

using namespace std;

class Student
{
private:
	int mark;
	string name;
public:
	Student(int mark, string name);
	int getMark();
};

