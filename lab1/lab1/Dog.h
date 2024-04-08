#pragma once

#include <iostream>
#include "Animal.h"

using namespace std;

class Dog: public Animal {
private:
	string breed;
	int levelOfGuideSkills;
	int levelOfTrackerSkills;
public:
    Dog(int _limbNr, string _name, bool _protectedAnimal, string _breed, int _levelOfGuideSkills, int _levelOfTrackerSkills);
    Dog(int _limbNr, string _name, bool _protectedAnimal);
    Dog();
    void setSkillLevel(int type, int value);
    int getSkillLevel(int type);
    void giveVoice();
    void info();
};

