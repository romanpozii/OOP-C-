#include <iostream>
#include "Square.h"
#include "Figure.h"

using namespace std;

Square::Square(float _a):Figure() {
	a = _a;
	cout << "Konstruktor klasy Square" << endl;
}

Square::~Square() {
	cout << "Destruktor klasy Square" << endl;
}

void Square::calculateArea() {
	float p = a * a;
	setArea(p);
}

void Square::show() {
	cout << "Show w klasie Sqaure, pole: " << getArea() << endl;
}