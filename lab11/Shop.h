#pragma once
#include <iostream>
#include <vector>
#include "Warehouse.h"

using namespace std;


class Shop {
private:
    string shopName;
    vector<shared_ptr<Warehouse>> warehouses;

public:
    Shop(const string& name) : shopName(name) {
        cout << "Konstruktor klasy Shop dla sklepu: " << shopName << endl;
    }

    ~Shop() {
        cout << "Destruktor klasy Shop dla sklepu: " << shopName << endl;
    }

    void addWarehouse(const shared_ptr<Warehouse>& warehouse) {
        warehouses.push_back(warehouse);
    }

    void sellItem(const string& itemName, int itemCount) {
        for (const auto& warehouse : warehouses) {
            if (warehouse->getItemName() == itemName && warehouse->getItemCount() >= itemCount) {
                warehouse->setItemCount(warehouse->getItemCount() - itemCount);
                cout << "Sprzedano " << itemCount << " " << itemName << " z magazynu." << endl;
                return;
            }
        }
        cout << "Pozycja jest niedostepna w zadnym magazynie" << endl;
    }

    void displayWarehouses() const {
        cout << "Magazyny wykorzystane sklepem " << shopName << ": " << endl;
        for (const auto& warehouse : warehouses) {
            cout << "- " << warehouse->getItemName() << endl;
        }
    }

    void displayShopName() const {
        cout << "Nazwa sklepu: " << shopName << endl;
    }
};

