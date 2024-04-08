#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "Employee.h"

class TeamLeader : public Employee {
public:
    TeamLeader(string _surname, int _age, int _experience, int _salary);

    int calculateBonus(int value);
    int Employee::calculateSalary(int value);
    void show();
};

#endif
