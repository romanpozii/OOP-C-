#include <iostream>
#include "Adding.h"
#include "Student.h"
#include "Array.h"

using namespace std;

void zadanie1();
void zadanie2();
void zadanie3();

template <typename T>
void mySwap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void showAll(T* tab[], int n) {
    for (int i = 0; i < n; ++i) {
        tab[i]->show();
    }
}

template <typename T>
void checkType(T a) {
    T val = numeric_limits<T>::max();
    cout << val << endl;
}

template <typename T>
T getMin(T* tab, int size) {
    T min = tab[0];
    for (int i = 1; i < size; i++) {
        if (tab[i] < min)
            min = tab[i];
    }
    return min;
}

int main()
{
    //zadanie1();
    //zadanie2();
    zadanie3();
    return 0;
}

void zadanie1() {
    int x1 = 6;
    int x2 = 8;
    cout << "przed: " << x1 << "  " << x2 << endl;
    mySwap<int>(x1, x2);
    cout << "po:    " << x1 << "  " << x2 << endl;

    Adding<int> a1(5);
    a1.add(6);
    a1.show();

    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();

    Student<float> s1(5, "Ala");
    s1.showMark();
    Student<int> s2(5, "Ala");
    s2.showMark();
    Student<string> s3(5, "Ala");
    s3.showMark();

    Adding<int>* arrAdd[3];
    for (int i = 0; i < 3; i++) {
        arrAdd[i] = new Adding<int>(i);
    }
    showAll(arrAdd, 3);

    Student<string>* arrStu[3];
    for (int i = 0; i < 3; i++) {
        arrStu[i] = new Student<string>(i + 2, "Ala");
    }
    showAll(arrStu, 3);

    for (int i = 0; i < 3; i++) {
        delete arrAdd[i];
        delete arrStu[i];
    }

    checkType<int>(3);
}

void zadanie2() {
    int x1[9] = { 100, 23, 5, 7, 10, -1, 12, 0, 15 };
    cout << getMin(x1, 9) << endl;

    string x2[3] = { "b", "C", "A" };
    cout << getMin(x2, 3) << endl;

    float x3[5] = { 1.22, 9.2, 1.0, 0.999999, 123.456 };
    cout << getMin(x3, 5) << endl;

    Student<string>* x4[3] = {
        new Student<string>(4, "Ala"),
        new Student<string>(3, "Grzegorz"),
        new Student<string>(5, "Hanna")
    };
    cout << getMin(x4, 3) << endl;
}

void zadanie3() {
    Array<int>* arr1 = new Array<int>();
    arr1->add(4);
    arr1->add(2);
    arr1->add(6);
    arr1->add(1);
    arr1->add(-19);
    cout << "Przed: ";
    arr1->show();
    arr1->sort();
    cout << "Po:    ";
    arr1->show();
    cout << "Element maksymalny: " << arr1->max() << endl;
    cout << "Element na pozycji 2: " << arr1->getElement(2) << endl << endl;
    delete arr1;

    Array<string>* arr2 = new Array<string>();
    arr2->add("Ala");
    arr2->add("ma");
    arr2->add("kota");
    cout << "Przed: ";
    arr2->show();
    arr2->sort();
    cout << "Po:    ";
    arr2->show();
    cout << "Element maksymalny (najdluzszy): " << arr2->max() << endl;
    cout << "Element na pozycji 1: " << arr2->getElement(1) << endl << endl;
    delete arr2;
}