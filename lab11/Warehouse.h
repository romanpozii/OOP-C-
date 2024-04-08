#pragma once
#include <iostream>

using namespace std;

class Warehouse {
private:
    string itemName;
    int itemCount;

public:
    Warehouse(const string& name, int count) : itemName(name), itemCount(count) {
        cout << "Konstruktor klasy Warehouse dla '" << itemName << "'" << endl;
    }

    ~Warehouse() {
        cout << "Destruktor klasy Warehouse dla '" << itemName << "'" << endl;
    }

    const string& getItemName() const {
        return itemName;
    }

    void setItemName(const string& name) {
        itemName = name;
    }

    int getItemCount() const {
        return itemCount;
    }

    void setItemCount(int count) {
        itemCount = count;
    }

    void displayInfo() const {
        cout << "Pozycja: " << itemName << ", Liczba sztuk: " << itemCount << endl;
    }
};

