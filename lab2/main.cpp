#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years(Employee** array, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i]->getExperience() > 5) {
            cout << array[i]->getSurname() << " pracuje wiecej niz 5 lat." << endl;
        }
    }
}

void howManyEarnLessThanMeanBonus(Developer** array, int size) {
    int counter = 0;
    int averageBonus = 0;
    for (int i = 0; i < size; ++i) {
        averageBonus += array[i]->calculateBonus(2);
    }
    averageBonus = averageBonus / size;
    for (int i = 0; i < size; ++i) {
        if (array[i]->calculateBonus(2) < averageBonus) {
            counter++;
        }
    }
    cout << counter << " pracownikow otrzymuje premie nizsza niz srednia premia wszystkich pracownikow." << endl;
}

void zadanie2() {
    const int arraySize = 4;
    Employee* employees[arraySize];
    employees[0] = new Developer("Nowak", 30, 6, 6000);
    employees[1] = new TeamLeader("Kowalski", 35, 7, 7000);
    employees[2] = new Developer("Wisniewski", 28, 4, 5500);
    employees[3] = new TeamLeader("Smith", 40, 10, 8000);

    for (int i = 0; i < 4; ++i) {
        employees[i]->show();
    }

    whoWorkMoreThan5Years(employees, arraySize);
    howManyEarnLessThanMeanBonus(reinterpret_cast<Developer**>(employees), arraySize);

    for (int i = 0; i < arraySize; ++i) {
        delete employees[i];
    }
}

int main() {
    zadanie2();

    return 0;
}