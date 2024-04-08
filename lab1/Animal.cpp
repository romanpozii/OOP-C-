#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	cout << "Konstruktor bezparametrowy klasy bazowej Animal" << endl;
}

Animal::Animal(int limbNr1, string name1, bool protectedAnimal1) {
	limbNr = limbNr1;
	name = name1;
	protectedAnimal = protectedAnimal1;
	cout << "Konstruktor klasy bazowej Animal" << endl;
}

void Animal::setLimbNr(int limbNr1) {
	limbNr = limbNr1;
}

void Animal::setName(string name1) {
	name = name1;
}

void Animal::setProtectedAnimal(bool protectedAnimal1) {
	protectedAnimal = protectedAnimal1;
}

int Animal::getLimbNr() {
	return limbNr;
}

string Animal::getName() {
	return name;
}

bool Animal::isProtectedAnimal() {
	return protectedAnimal;
}

void Animal::giveVoice() {
	cout << "Chrum, miau, hau, piiiii" << endl;
}

void Animal::info() {
	cout << "Zwierz o liczbu konczyn: " << limbNr << ", nazwie: " << name
		 << ", czy jest chroniony: " << protectedAnimal << endl;
}

