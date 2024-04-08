#pragma once
#include <iostream>

using namespace std;

class Citizen
{
private:
	string name, surname, postal_code;
	int age;
	char sex;
public:
	Citizen() : name(""), surname(""), age(0), sex(' '), postal_code("") {}
	Citizen(const string& name, const string& surname, int age, char sex, const string& postal_code)
		: name(name), surname(surname), age(age), sex(sex), postal_code(postal_code) {}
	string getName() const {
		return name;
	}

	string getSurname() const {
		return surname;
	}

	int getAge() const {
		return age;
	}
	char getSex() const {
		return sex;
	}
	string getPostalCode() const {
		return postal_code;
	}
	void show() const {
		cout << "Name: " << name << ", Surname: " << surname
			<< ", Age: " << age << ", Sex: " << sex
			<< ", Psotal code: " << postal_code << endl;
	}

};

