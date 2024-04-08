#pragma once
#include <iostream>

using namespace std;

class Car
{
private:
	string model;
	int year;
	double engineCapacity;
public:
	Car(string model, int year, double engineCapacity)
		: model(model), year(year), engineCapacity(engineCapacity) {}

	string getModel() {
		return model;
	}

	int getYear() {
		return year;
	}

	double getEngineCapacity() {
		return engineCapacity;
	}

	void setModel(string _model) {
		model = _model;
	}

	void setYear(int _year) {
		year = _year;
	}

	void setEngineCapacity(double _capacity) {
		engineCapacity = _capacity;
	}

	void info(int carNumber) {
		cout << "Car " << carNumber << " - Model: " << model
			<< ", Year: " << year
			<< ", Engine Capacity: " << engineCapacity << "L" << endl;
	}
};

