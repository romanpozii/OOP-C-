#include <iostream>
#include <string>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

void przykladowe();
void zadanie1();
void zadanie2();

int howManyProtectedAnimals(Animal a[], int size);
void howManyTrackerDogs(Dog d[], int size);
void howManyCats(Cat c[], int size);

int main()
{
    //zadanie1();
    zadanie2();
    return 0;
}

void przykladowe() {
    cout << endl << "Obiekty klasy Person" << endl;
    Person o1("Grazyna", "Nowak", 45);
    o1.showInfoPerson();
    cout << "Czy pelnoletnia?: " << o1.is_18() << endl;
    o1.setAge(16);

    cout << endl << "Obiekty klasy Teacher" << endl;
    Teacher n1("Barbara", "Kowalska", 45, 30, "Phd");
    n1.showInfoTeacher();
    cout << "Czy ma Phd?: " << n1.is_Phd() << endl;
    n1.setAge(34);

    Person p1[3];
    Person* p2;
    Person* p3[3];
    Person** p4;

    for (int i = 0; i < 3; ++i) {
        p1[i].init("Anna", "Nowak", 20 + i);
        p1[i].showInfoPerson();
    }

    p2 = new Person[3];
    for (int i = 0; i < 3; ++i) {
        p2[i].init("Ola", "Adamek", 20 + i);
        p2[i].showInfoPerson();
    }

    for (int i = 0; i < 3; ++i) {
        p3[i] = new Person("Kasia", "Kowalska", 20 + i);
        p3[i]->showInfoPerson();
    }

    p4 = new Person * [3];
    for (int i = 0; i < 3; ++i) {
        p4[i] = new Person("Pawel", "Wojcik", 20 + i);
        p4[i]->showInfoPerson();
    }

    for (int i = 0; i < 3; ++i) {
        delete p3[i];
    }

    for (int i = 0; i < 3; ++i) {
        delete p4[i];
    }

    delete[] p4;
}

void zadanie1() {

    Student s1[3];
    Student* s2;
    Student* s3[3];
    Student** s4;

    for (int i = 0; i < 3; ++i) {
        s1[i].init("Pawel", "Nowak", 20 + i);
        s1[i].setIndex(to_string(i));
        s1[i].showInfoStudent();
    }
    cout << endl;

    s2 = new Student[3];
    for (int i = 0; i < 3; ++i) {
        s2[i].init("Mateusz", "Kowalski", 20 + i);
        s2[i].setIndex(to_string(i));
        s2[i].showInfoStudent();
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        s3[i] = new Student("Beata", "Milosz", 20 + i, to_string(i));
        s3[i]->showInfoStudent();
    }
    cout << endl;

    s4 = new Student * [3];
    for (int i = 0; i < 3; i++)
    {
        s4[i] = new Student("Anna", "Nowak", 20 + i, to_string(i));
        s4[i]->showInfoStudent();
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        delete s3[i];
    }

    for (int i = 0; i < 3; i++)
    {
        delete s4[i];
    }
    delete[] s4;
}

void zadanie2() {
    cout << "Testowanie klas:" << endl << "Animal: " << endl;
    cout << "Konstruktor bezparametrowy: " << endl;
    Animal animalBez;
    cout << "Konstruktor z parametrami i wartoscia domyslna: " << endl;
    Animal animal(5, "Lamina");
    animal.giveVoice();
    animal.info();
    cout << endl;

    cout << "Cat:" << endl;
    cout << "Konstruktor bezparametrowy: " << endl;
    Cat catBez;
    cout << "Konstruktor z parametrami: " << endl;
    Cat cat(4, "Carmel", false);
    int* mice = new int[5] {120, 95, 64, 101, 88};
    cat.initCat(10, mice);
    cat.giveVoice();
    cat.info();
    cout << endl;

    cout << "Dog:" << endl;
    cout << "Konstruktor bezparametrowy: " << endl;
    Dog dogBez;
    cout << "Konstruktor z parametrami: " << endl;
    Dog dog(4, "Terror", false, "Rasa", 3, 5);
    dog.giveVoice();
    dog.info();
    cout << endl;

    cout << "Testowanie funkcji:" << endl;

    Animal a[5] = { Cat(4, "Kot", false),
        Cat(4, "Rysio", false),
        Dog(4, "Reks", false, "Duzy", 6, 4),
        Animal(3, "Bobus"),
        Dog(4, "Pies", true) };

    cout << "Ilosc zwierzat chronionych: " << howManyProtectedAnimals(a, 5) << endl << endl;

    Dog d[3] = { Dog(4, "Pies1", true, "Rasa1", 7, 1),
        Dog(4, "Pies2", true, "Rasa2", 2, 4),
        Dog(3, "Pies3", false, "Rasa3", 5, 5)
    };
    cout << "Psy, ktorych poziom tropiciela jest wiekszy niz przewodnika: " << endl;
    howManyTrackerDogs(d, 3);
    cout << endl << endl;

    Cat c[3] = { Cat(4, "Kot1", false),
        Cat(4, "Kot2", false),
        Cat(4, "Kot3", false)
    };

    c[0].initMice(mice);
    mice = new int[5] {102, 99, 103, 100, 85};
    c[1].initMice(mice);
    mice = new int[5] {87, 82, 74, 99, 89};
    c[2].initMice(mice);

    howManyCats(c, 3);
}

int howManyProtectedAnimals(Animal a[], int size)
{
    int howMany = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i].isProtectedAnimal()) howMany++;
    }
    return howMany;
}

void howManyTrackerDogs(Dog d[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (d[i].getSkillLevel(0) >= d[i].getSkillLevel(1))
            d[i].info();
    }
}

void howManyCats(Cat c[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int myszy = 0;
        for (int j = 0; j < 5; j++)
        {
            myszy += c[i].getMice(j);
        }
        c[i].info();
        cout << "Upolowanych mysz w przeciagu 5 lat: " << myszy << endl;
    }
}