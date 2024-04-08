#pragma once

#include <iostream>

using namespace std;

class Animal
{
private:
	int limbNr;
	string name;
	bool protectedAnimal;
public:
	Animal();
	Animal(int limbNr1, string name1, bool protectedAnimal1 = true);
	void setLimbNr(int libNr1);
	void setName(string name1);
	void setProtectedAnimal(bool protectedAnimal1);
	int getLimbNr();
	string getName();
	bool isProtectedAnimal();
	void giveVoice();
	void info();
};

