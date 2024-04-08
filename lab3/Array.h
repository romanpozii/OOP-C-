#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Array {
private:
    T* tab;
    int size;
    int index;
public:
    Array(int size) {
        this->tab = new T[size];
        this->size = size;
        this->index = 0;
    }
    Array() {
        this->tab = new T[10];
        this->size = 10;
        this->index = 0;
    }
    virtual ~Array() {
        delete[] tab;
    }
    void sort() {
        for (int i = 1; i < index; i++) {
            int temp = tab[i];
            int j = i - 1;
            while (j >= 0 && tab[j] > temp) {
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = temp;
        }
    }
    T max() {
        T max = tab[0];
        for (int i = 1; i < index; i++) {
            if (tab[i] > max)
                max = tab[i];
        }
        return max;
    }
    void show() {
        for (int i = 0; i < index - 1; i++) {
            cout << tab[i] << ",";
        }
        cout << tab[index - 1] << endl;
    }
    void add(T val) {
        if (index < size)
            tab[index++] = val;
        else
            cout << "Brak miesjca" << endl;
    }
    T getElement(int pos) {
        return tab[pos];
    }
};

template <>
class Array<string> {
private:
    string* tab;
    int size;
    int index;
public:
    Array(int size) {
        this->tab = new string[size];
        this->size = size;
        this->index = 0;
    }
    Array() {
        this->tab = new string[10];
        this->size = 10;
        this->index = 0;
    }
    virtual ~Array() {
        delete[] tab;
    }
    void sort() {
        for (int i = 1; i < index; i++) {
            string temp = tab[i];

            int j = i - 1;
            while (j >= 0 && temp.length() < tab[j].length()) {
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = temp;
        }
    }
    string max() {
        string maxLength = tab[0];
        for (int i = 1; i < index; i++) {
            if (tab[i].length() > maxLength.length())
                maxLength = tab[i];
        }
        return maxLength;
    }
    void show() {
        for (int i = 0; i < index - 1; i++) {
            cout << tab[i] << ",";
        }
        cout << tab[index - 1] << endl;
    }
    void add(string val) {
        if (index < size)
            tab[index++] = val;
        else
            cout << "Brak miesjca" << endl;
    }
    string getElement(int pos) {
        return tab[pos];
    }
};