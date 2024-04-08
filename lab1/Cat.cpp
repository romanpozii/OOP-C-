#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat(int _limbNr, string _name, bool _protectedAnimal) :
    Animal(_limbNr, _name, _protectedAnimal)
{
    cout << "Konstruktor klasy pochodnej Cat z ustawieniem tylko skladowych klasy Animal" << endl;
}

Cat::Cat()
{
    cout << "Konstruktor bezparametrowy klasy pochodnej Cat" << endl;
}

void Cat::initMice(int _mice[5])
{
    for (int i = 0; i < 5; i++)
        mice[i] = _mice[i];
}

void Cat::initCat(int _levelOfMouseHunting, int _mice[5])
{
    levelOfMouseHunting = _levelOfMouseHunting;
    for (int i = 0; i < 5; i++)
        mice[i] = _mice[i];
}

void Cat::setLevelOfMouseHunting(int value)
{
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting()
{
    return levelOfMouseHunting;
}

int Cat::getMice(int index)
{
    return mice[index];
}

void Cat::giveVoice()
{
    cout << "Miau miau" << endl;
}

void Cat::info()
{
    Animal::info();
    cout << "Poziom umiejetnosci lowienia myszy: " << levelOfMouseHunting
        << ", liczba upolowanych myszy w ciagu 5 lat: ";
    for (int i = 0; i < 4; i++)
    {
        cout << mice[i] << ", ";
    }
    cout << mice[4];
    cout << endl;
}
