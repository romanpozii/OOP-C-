#pragma once
#include <vector>
#include <iostream>
#include "Citizen.h"

using namespace std;

class City
{
public:
	vector<Citizen> citizens;
	string city_name;
	City(const string& name) : city_name(name) {}
	void addCitizen(const Citizen& citizen);
	void deleteCitizen(const string& surname, int age);
	void show_citizens() const;
	void show_city() const;
	int women() const;
	int city_citizens() const;
	int adults() const;
	void postal_codes() const;
};

