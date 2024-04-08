#include "TeamLeader.h"
#include <iostream>

using namespace std;

int TeamLeader::calculateBonus(int value) {
    return value * (1 + getSalary() + getExperience());
}

void TeamLeader::show() {
    cout << "TeamLeader" << endl;
    cout << "Jestem Team Leader z " << getExperience() << " letnim doswiadczeniem" << endl;
    Employee::show();
    cout << endl << endl;
}

int TeamLeader::calculateSalary(int value) {
    return value + 0.2 * value * (getSalary() + getExperience());
}

TeamLeader::TeamLeader(string _surname, int _age, int _experience, int _salary) : Employee(_surname, _age, _experience, _salary) {
    cout << " Konstruktor z parametrami - TeamLead" << endl;

}