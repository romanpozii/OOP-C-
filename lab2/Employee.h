#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>

using namespace std;

class Employee
{
private:
	string surname;
	int age;
	int experience;
	int salary;
public:
	Employee(string surname, int age, int experience, int salary);
	Employee();
	virtual ~Employee();
	virtual void show();
	virtual int calculateSalary(int value) = 0;
	int ageEmployment();

	int getAge() const;
	string getSurname() const;
	int getExperience() const;
	int getSalary() const;
};
#endif
