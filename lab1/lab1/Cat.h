#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <iostream>
#include "Animal.h"

using namespace std;

class Cat : public Animal
{
private:
    int levelOfMouseHunting;
    int mice[5];
public:
    Cat(int _limbNr, string _name, bool _protectedAnimal);
    Cat();
    void initMice(int _mice[5]);
    void initCat(int _levelOfMouseHunting, int _mice[5]);
    void setLevelOfMouseHunting(int value);
    int getLevelOfMouseHunting();
    int getMice(int index);
    void giveVoice();
    void info();
};

#endif // CAT_H_INCLUDED

