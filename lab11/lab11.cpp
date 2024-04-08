#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Person.h"
#include "Elem.h"
#include "Buffer.h"
#include "BufferArr.h"
#include "BufferFile.h"
#include "Warehouse.h"
#include "Shop.h"
#include "LinkedList.h"

using namespace std;

void funcUniqueModify(unique_ptr<int>& uptr) {
    *uptr = 112;
}

void funcUniqueDeleter(int* p) {
    delete[] p;
    cout << "funcUniqueDeleter: usunieta tablica" << endl;
}

void funDeleter(Person* p) {
    cout << "usunieta osoba: ";
    p->info();
    delete p;
}

unique_ptr<int[]> funUniqueArray(int n) {
    unique_ptr<int[]> arr(new int[n]);
    for (int i = 0; i < n; ++i)
        arr[i] = i + 7;

    return arr;
}

void przykladowe() {
    unique_ptr <int> uptr1(new int);
    *uptr1 = 12;
    cout << "Wartosc uptr1: " << *uptr1 << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;

    unique_ptr <int> uptr2;
    cout << "Przed move: " << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;
    cout << "Adres uptr2: " << uptr2.get() << endl;
    uptr2 = move(uptr1);
    cout << "Po move: " << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;
    cout << "Adres uptr2: " << uptr2.get() << endl;

    funcUniqueModify(uptr2);
    cout << "Wartosc uptr2: " << *uptr2 << endl;

    cout << "Przed reset: Adres uptr2: " << uptr2.get() << endl;
    uptr2.reset();
    cout << "Po reset: Adres uptr2: " << uptr2.get() << endl;


    unique_ptr <int[]> tab1(new int[4]);
    cout << "Elementy tablicy tab1: " << endl;
    for (int i = 0; i < 4; ++i) {
        tab1[i] = i + 7;
        cout << tab1[i] << endl;
    }

    unique_ptr<int[]> tab3 = funUniqueArray(5);
    cout << "Elementy tablicy tab3: " << endl;
    for (int i = 0; i < 5; ++i)
        cout << tab3[i] << endl;
    unique_ptr<int[], void(*)(int*)>
        tab2(new int[10], funcUniqueDeleter);

    vector<unique_ptr<int>> vec;
    unique_ptr<int> i1(new int);
    *i1 = 3;
    vec.push_back(move(i1));
    cout << "Element w wektorze: " << *vec[0] << endl;


    shared_ptr <Person> sptr1(new Person("Ola", 32));
    shared_ptr <Person> sptr2(new Person("Ula", 52));
    sptr1->info();
    cout << "Licznik sptr1: " << sptr1.use_count() << endl;
    cout << "Licznik sptr2: " << sptr2.use_count() << endl;

    vector<shared_ptr<Person>> firstInOffice;
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);

    cout << "Po dodaniu do kontenera" << endl;
    cout << "Licznik sptr1: " << sptr1.use_count() << endl;
    cout << "Licznik sptr2: " << sptr2.use_count() << endl;

    for (shared_ptr<Person> ptr : firstInOffice)
        ptr->info();
    cout << endl;

    firstInOffice.resize(3);

    cout << "Po resize" << endl;
    cout << "Licznik sptr1: " << sptr1.use_count() << endl;
    cout << "Licznik sptr2: " << sptr2.use_count() << endl;

    shared_ptr<Person> sptr3(new Person("Magda", 22), funDeleter);
    sptr3->info();


    shared_ptr <Elem> el1(new Elem);
    shared_ptr <Elem> el2(new Elem);
    el1->next = el2;
    el1->prev = el1;
    shared_ptr<Elem> tempEl(el2->prev);
    cout << "Adres: " << tempEl << endl;

}

void bufor() {
    vector<unique_ptr<Buffer>> buffers;

    buffers.push_back(make_unique<BufferArr>(2));
    buffers.push_back(make_unique<BufferArr>(4));
    buffers.push_back(make_unique<BufferArr>(6));
    buffers.push_back(make_unique<BufferFile>("output.txt"));
    buffers.push_back(make_unique<BufferFile>("output2.txt"));
    buffers.push_back(make_unique<BufferFile>("output3.txt"));

    for (auto& buffer : buffers) {
        buffer->add(1);
        buffer->add(2);
        buffer->add(3);
        buffer->write();
        cout << "---------------------------" << endl;
    }
}

void sklepy() {
    auto warehouse1 = make_shared<Warehouse>("Ksiazki", 100);
    auto warehouse2 = make_shared<Warehouse>("Komputery", 50);
    auto warehouse3 = make_shared<Warehouse>("Lozka", 20);

    Shop shop1("Ksiegarnia");
    Shop shop2("Sklep z elektronika");
    Shop shop3("Sklep meblowy");

    shop1.addWarehouse(warehouse1);
    shop2.addWarehouse(warehouse2);
    shop3.addWarehouse(warehouse3);

    warehouse1->displayInfo();
    warehouse2->displayInfo();
    warehouse3->displayInfo();

    cout << "------------------------" << endl;

    shop1.displayWarehouses();
    shop2.displayWarehouses();
    shop3.displayWarehouses();

    cout << "------------------------" << endl;

    shop1.sellItem("Ksiazki", 20);
    shop2.sellItem("Komputery", 10);
    shop3.sellItem("Lyzki", 5);

    cout << "------------------------" << endl;

    warehouse1->displayInfo();
    warehouse2->displayInfo();
    warehouse3->displayInfo();
}

void lista() {
    LinkedList<int> list;

    cout << "Dodanie na poczatek: 5, 3, 1" << endl;
    list.addToFront(1);
    list.addToFront(3);
    list.addToFront(5);
    list.displayList();

    cout << "Dodanie na koniec: -1, -3, -5" << endl;
    list.addToBack(-1);
    list.addToBack(-3);
    list.addToBack(-5);
    list.displayList();

    cout << "Usuwanie z poczatku" << endl;
    list.removeFromFront();
    list.displayList();

    cout << "Usuwanie z konca" << endl;
    list.removeFromBack();
    list.displayList();

    cout << "Czy lista jest pusta?" << (list.isEmpty() ? "Tak" : "Nie") << endl;
}

int main()
{
    //przykladowe();
    //bufor();
    //sklepy();
    lista();
    return 0;
}
