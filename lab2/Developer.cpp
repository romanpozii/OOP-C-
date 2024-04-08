#include "Developer.h"
#include <iostream>

using namespace std;

float Developer::calculateBonus(int value) {
    return (value + 0.2 * value * (getSalary() + getExperience()));
}

Developer::Developer(string _surname, int _age, int _experience, int _salary) : Employee(_surname, _age, _experience, _salary) {
    cout << " Konstruktor z parametrami - Developer" << std::endl;

}

int Developer::calculateSalary(int value) {
    return value + 0.2 * value * (getSalary() + getExperience());
}

void Developer::show() {
    cout << "Developer" << endl;
    Employee::show();
    cout << endl << endl;
}
