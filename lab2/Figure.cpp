#include <iostream>
#include "Figure.h"

using namespace std;

Figure::Figure() {
	cout << "Konstruktor klasy bazowej Figure" << endl;
}

Figure:: ~Figure() {
	cout << "Wirtualny destruktor klasy bazowej Figure" << endl;
}

float Figure::getArea() {
	return area;
}

void Figure::setArea(float _area) {
	area = _area;
}

void Figure::show() {
	cout << "Pole: " << area << endl;
}