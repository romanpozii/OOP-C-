#include "Employee.h"

using namespace std;
Employee::Employee(string _surname, int _age, int _experience, int _salary) {
    surname = _surname;
    age = _age;
    experience = _experience;
    salary = _salary;
    cout << "Konstruktor z parametrami - Employee" << endl;

}

Employee::Employee() { cout << "Konstruktor bez parametrow - Employee" << endl; }

string Employee::getSurname() const {
    return surname;
}

int Employee::getAge() const {
    return age;
}

int Employee::getExperience() const {
    return experience;
}

int Employee::getSalary() const {
    return salary;
}

int Employee::ageEmployment() {
    return age - experience;
}

Employee::~Employee() {
    cout << "Destruktor w klasie Employee" << endl;
}

void Employee::show() {
    cout << "Nazwisko: " << surname << endl;
    cout << "Wiek: " << age << endl;
    cout << "Doswiadczenie: " << experience << " lat" << endl;
    cout << "Miesieczna wyplata: " << salary << " PLN" << endl;
}