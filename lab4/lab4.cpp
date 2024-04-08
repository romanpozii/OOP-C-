#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <random>
#include <string>
#include "Even.h"
#include "Compare.h"
#include "Student.h"
#include "Citizen.h"
#include "City.h"
#include <set>

using namespace std;

template <typename T>
void show(T& con) {
    for (typename T::iterator it = con.begin(); it != con.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void print(int& el) {
    cout << el << "***";
}

void add10(int& el) {
    el += 10;
}

bool isEven(int x) {
    if (x % 2 == 0)
        return true;
    else
        return false;
}

void showMark(Student& s) {
    cout << s.getMark() << " ";
}

void showCities(const vector<City>& cities) {
    for (const auto& city : cities) {
        city.show_city();
        city.show_citizens();
        cout << "-----------------------------" << endl;
    }
}

void the_most(vector<City>& cities, int mode) {
    if (mode == 1) {
        string max_city_name;
        int max_postal_codes = 0;

        for (const auto& city : cities) {
            set<string> unique_postal_codes;
            for (const auto& citizen : city.citizens) {
                unique_postal_codes.insert(citizen.getPostalCode());
            }
            if (unique_postal_codes.size() > max_postal_codes) {
                max_postal_codes = unique_postal_codes.size();
                max_city_name = city.city_name;
            }
        }
        cout << "City with the most different postal codes: " << max_city_name << endl;
    }
    else if (mode == 2) {
        string min_city_name;
        int min_citizens = numeric_limits<int>::max();

        for (const auto& city : cities) {
            if (city.city_citizens() < min_citizens) {
                min_citizens = city.city_citizens();
                min_city_name = city.city_name;
            }
        }
        cout << "City with the fewest citizens: " << min_city_name << endl;
    }
}

void statistic(vector<City>& cities) {
    for (const auto& city : cities) {
        cout << "Statistics for city " << city.city_name << ":" << endl;
        cout << "Total citizens: " << city.city_citizens() << endl;
        cout << "Women: " << city.women() << endl;
        cout << "Men: " << city.city_citizens() - city.women() << endl;
        cout << "Adults: " << city.adults() << endl;
        cout << "Children: " << city.city_citizens() - city.adults() << endl;
        cout << "-----------------------" << endl;
    }
}

void sort_cities(vector<City>& cities) {
    sort(cities.begin(), cities.end(),
        [](const City& a, const City& b) {
            return a.city_citizens() < b.city_citizens();
        });
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void przykladowe_zadanie() {
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout << "Operator[]" << endl;
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;

    cout << "At" << endl;
    for (int i = 0; i < vec.size(); ++i)
        cout << vec.at(i) << " ";
    cout << endl;

    cout << "Iterator: " << endl;
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "begin() " << *vec.begin() << " front() " << vec.front() << endl;
    cout << "end() " << *(vec.end() - 1) << " back() " << vec.back() << endl;

    show(vec);
    vec.pop_back();
    show(vec);
    vec.erase(vec.begin() + 1, vec.begin() + 2);
    show(vec);
    vec.insert(vec.begin() + 1, 100);
    show(vec);
    vec.clear();
    show(vec);

    vector<float> vec2(5, 8.2);
    show(vec2);
    vec2.push_back(3.1);
    show(vec2);

    vector<int> num = { 3,6,3,8,9,1,3 };
    show(num);
    sort(num.begin(), num.end());
    show(num);

    cout << "binary search" << endl;
    cout << binary_search(num.begin(), num.end(), 3) << endl;

    cout << "count" << endl;
    cout << count(num.begin(), num.end(), 3);

    cout << "reverse" << endl;
    reverse(num.begin(), num.begin() + 4);
    show(num);

    cout << "random_shuffle" << endl;
    random_shuffle(num.begin(), num.end());
    show(num);

    cout << "max element" << endl;
    cout << *max_element(num.begin(), num.end()) << endl;

    cout << "merge" << endl;
    vector<int> num2(4, 6);
    vector<int> res(num.size() + num2.size());
    sort(num.begin(), num.end());
    merge(num.begin(), num.end(), num2.begin(), num2.end(), res.begin());
    show(res);

    for_each(num.begin(), num.end(), print);
    for_each(num.begin(), num.end(), add10);
    cout << endl;
    for_each(num.begin(), num.end(), print);
    cout << endl;
    cout << count_if(num.begin(), num.end(), isEven);

    vector<int> num3 = { 2,-6,7,3,0,8,-9,-2 };
    for_each(num3.begin(), num3.end(), print);
    int howMany = count_if(num3.begin(), num3.end(), bind2nd(greater<int>(), 0));
    cout << endl << "wersja1: wartosc > 0 " << howMany << endl;

    greater<int> f;
    howMany = count_if(num3.begin(), num3.end(), bind2nd(f, 0));
    cout << "wersja2: wartosc > 0 " << howMany << endl;

    cout << "Przed sortowaniem" << endl;
    for_each(num3.begin(), num3.end(), print);
    sort(num3.begin(), num3.end(), greater<int>());
    cout << endl << "Po sortowaniu" << endl;
    for_each(num3.begin(), num3.end(), print);

    for_each(num.begin(), num.end(), print);
    cout << endl;
    cout << count_if(num.begin(), num.end(), isEven) << endl;
    cout << count_if(num.begin(), num.end(), Even(2)) << endl;


    vector<Student>st;
    st.push_back(Student(1, "Ala"));
    st.push_back(Student(5, "Ola"));
    st.push_back(Student(2, "Piotr"));
    for_each(st.begin(), st.end(), showMark);
    cout << endl;
    sort(st.begin(), st.end(), Compare());
    for_each(st.begin(), st.end(), showMark);
}

void zadanie2() {
    cout << "Zadanie 2" << endl << endl;
    list<int> list;
    int i;
    int n = rand();

    for (i = 0; i < n; i++) {
        int j = -100 + rand() % 201;
        if (j >= 0)
            list.push_front(j);
        else
            list.push_back(j);
    }

    cout << "Lista dynamiczna list o wylosowanym rozmiarze " << n << ": " << endl;
    show(list);
    cout << endl;
}

//void zadanie3() {
//    vector<City> cities;
//
//    Citizen citizen1("Anna", "Nowak", 22, "F", "12345");
//    Citizen citizen2("Michal", "Kowalski", 44, "M", "12345");
//    Citizen citizen3("Piotr", "Wisniewski", 24, "M", "43123");
//    Citizen citizen4("Katarzyna", "Dabrowska", 30, "F", "43254");
//
//    City city1("City1");
//    City city2("City2");
//
//    city1.addCitizen(citizen1);
//    city1.addCitizen(citizen2);
//    city2.addCitizen(citizen3);
//    city2.addCitizen(citizen4);
//
//    cities.push_back(city1);
//    cities.push_back(city2);
//
//    showCities(cities);
//    the_most(cities, 1);
//    the_most(cities, 2);
//    statistic(cities);
//    sort_cities(cities);
//}

void zadanie4() {
    vector<int> numbers = { 23,43,653,93,12,53,67,6,323 };

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return sumOfDigits(a) < sumOfDigits(b);
        });

    cout << "Posortowano rosnaca wedlug sumy cyfr: \n";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << "\n\n";

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return to_string(a).length() > to_string(b).length();
        });

    cout << "Posortowano malejaca wedlug liczby cyfr:\n";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
        });
    cout << "\n";
}

int main()
{
    //przykladowe_zadanie();
    //zadanie2();
    zadanie4();
    return 0;
}
