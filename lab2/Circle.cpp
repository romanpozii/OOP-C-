#include <iostream>
#include "Circle.h"
#include "Figure.h"

using namespace std;

Circle::Circle(float _r) {
	r = _r;
	cout << "Konstruktor w klasie Circle" << endl;
}

Circle::~Circle() {
	cout << "Destruktor w klasie Circle" << endl;
}

void Circle::calculateArea() {
	float p = 3.14 * r * r;
	setArea(p);
}