#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED

#include "Employee.h"

class Developer : public Employee
{
public:
	Developer(string _surname, int _age, int _experience, int _salary);
	float calculateBonus(int value);
	int Employee::calculateSalary(int value);
	void show();
};
#endif
