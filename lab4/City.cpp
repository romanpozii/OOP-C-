#include "City.h"
#include <algorithm>
#include <set>

using namespace std;

void City::addCitizen(const Citizen& citizen)
{
	citizens.push_back(citizen);
}

void City::deleteCitizen(const string& surname, int age)
{
	auto it = remove_if(citizens.begin(), citizens.end(),
		[&surname, age](const Citizen& citizen) {
			return citizen.getSurname() == surname && citizen.getAge() == age;
		});

	citizens.erase(it, citizens.end());
}

void City::show_citizens() const
{
	cout << "Citizens in " << city_name << ":" << endl;
	for (const auto& citizen : citizens) {
		citizen.show();
	}
}

void City::show_city() const
{
	cout << "City: " << city_name << endl;
}

int City::women() const
{
	return count_if(citizens.begin(), citizens.end(),
		[](const Citizen& citizen) {
			return citizen.getSex() == 'F' || citizen.getSex() == 'f';
		});
}

int City::city_citizens() const
{
	return citizens.size();
}

int City::adults() const
{
	return count_if(citizens.begin(), citizens.end(),
		[](const Citizen& citizen) {
			return citizen.getAge() >= 18;
		});
}

void City::postal_codes() const
{
	set<string> unique_postal_codes;
	for (const auto& citizen : citizens) {
		unique_postal_codes.insert(citizen.getPostalCode());
	}

	cout << "Postal codes in " << city_name << ":" << endl;
	for (const auto& postal_code : unique_postal_codes) {
		int count = count_if(citizens.begin(), citizens.end(),
			[&postal_code](const Citizen& citizen) {
				return citizen.getPostalCode() == postal_code;
			});
		cout << postal_code << " -> " << count << " citizens" << endl;
	}
}
