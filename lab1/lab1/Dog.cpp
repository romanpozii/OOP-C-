#include <iostream>
#include "Dog.h"
#include "Animal.h"

using namespace std;

Dog::Dog(int _limbNr, string _name, bool _protectedAnimal, string _breed, int _levelOfGuideSkills, int _levelOfTrackerSkills) :
    Animal(_limbNr, _name, _protectedAnimal)
{
    breed = _breed;
    levelOfGuideSkills = _levelOfGuideSkills;
    levelOfTrackerSkills = _levelOfTrackerSkills;
    cout << "Konstruktor klasy pochodnej Dog" << endl;
}

Dog::Dog(int _limbNr, string _name, bool _protectedAnimal) :
    Animal(_limbNr, _name, _protectedAnimal)
{
    cout << "Konstruktor klasy pochodnej Dog z ustawieniem tylko skladowych klasy Animal" << endl;
}

Dog::Dog()
{
    cout << "Konstruktor bezparametrowy klasy pochodnej Dog" << endl;
}

void Dog::setSkillLevel(int type, int value)
{
    if (type == 0)
    {
        levelOfGuideSkills = value;
    }
    else
        levelOfTrackerSkills = value;
}

int Dog::getSkillLevel(int type)
{
    if (type == 0)
    {
        if (levelOfGuideSkills >= 1 && levelOfGuideSkills <= 10)
            return levelOfGuideSkills;
        else
            return 0;
    }
    else if (levelOfTrackerSkills >= 1 && levelOfTrackerSkills <= 10)
        return levelOfTrackerSkills;
    else return 0;
}

void Dog::giveVoice()
{
    cout << "Hau, hau" << endl;
}

void Dog::info()
{
    Animal::info();
    cout << "Rasa psa: " << breed << ", poziom umiejetnosci przewodnika: " << levelOfGuideSkills
        << ", poziom umiejetnosci tropiciela: " << levelOfTrackerSkills << endl;
}

