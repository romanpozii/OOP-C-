#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <math.h>
#include <assert.h>
#include <limits>

using namespace std;

class Error {
public:
    virtual void error() = 0;
    virtual ~Error() {};
};

class SquareRootError : public Error {
public:
    void error() {
        cout << "Pierwiastek z liczby ujemnej" << endl;
    }
};

bool valid1(int val) {
    if (val >= 0)
        return true;
    else
        return false;
}

int valid2(int val) {
    if (val < 0)
        return abs(val);
}

double sqrt_function(int a) {
    if (a < 0)
        throw - 1;
    else
        return sqrt(a);
}

double sqrt_function1(int a) {
    if (a < 0)
        throw SquareRootError();
    else
        return sqrt(a);
}

double sqrt_function2(int a) {
    if (a < 0)
        throw new SquareRootError();
    else
        return sqrt(a);
}

void function_bad_alloc1() {
    int* tab = new int[1000000000000];
}

class PrzekroczenieOczka : public exception {
public :
    const char* what() const noexcept override {
        return "Suma przekroczyla oczko";
    }
};

void przykladowe() {
    /*int a = 223;
    float b = 21.365;
    cout << "dec: " << dec << a << endl;

    cout << "hex bez showbase: " << hex << a << endl;
    cout << "hex z showbase: " << showbase << a << endl;
    cout << "oct z show base: " << oct << a << endl;
    cout << "oct bez show base: " << noshowbase << a << endl;

    cout << "dec z showpos: " << dec << showpos << a << endl;

    cout << "scientific: " << scientific << b << endl;

    cout << "setw z right: " << setw(20) << a << endl;
    cout << "setw z left i setfill: " << setw(20) << left << setfill('*') << a << endl;

    cout << "setprecision 3: " << resetiosflags(ios::scientific) << setprecision(3) << b << endl;

    string l1, l2, l3 = "Ala Nowak";
    int num;
    cout << "Konwersja: " << endl;
    istringstream isstream("123");
    isstream >> num;
    cout << num << endl;
    ostringstream osstream;
    osstream << 123;
    l1 = osstream.str();
    cout << l1 << endl;

    ostringstream osstream1;
    osstream1 << "Laboratorium " << 9 << ", zostalo jeszcze " << 6 << endl;
    cout << "Formatowanie: " << osstream1.str();

    string stringEx;
    int numberIntEx;
    float numberFloatEx;
    istringstream isstream1("Ala 10 3.45");
    isstream1 >> stringEx >> numberIntEx >> numberFloatEx;
    if (isstream1.fail()) {
        cout << "Parsowanie nie usalo sie" << endl;
    }
    else {
        cout << "Parsowanie udalo sie: " << endl;
        cout << "Napis: " << stringEx << endl;
        cout << "Liczba int: " << numberIntEx << endl;
        cout << "Liczba float: " << numberFloatEx << endl;
    }
    istringstream ss(l3);
    getline(ss, l1, ' ');
    getline(ss, l2, ' ');
    cout << l1 << " " << l2 << endl;*/

    /*ofstream fileOf("zapis.txt", ios::app);
    if (fileOf.is_open()) {
        cout << "Plik otworzyl sie poprawnie" << endl;
        fileOf << "8 Ala ma kota" << endl;
        fileOf << "a kot ma Ale" << endl;
        fileOf << 10 << endl;
        fileOf << 1.1 << endl;
        fileOf << 'a' << endl;
        fileOf.close();
    }
    else
        cerr << "Blad przy otwarciu pliku!" << endl;

    ifstream fileIf;
    fileIf.open("plik.txt");

    int number;
    fileIf >> number;

    string line;
    fileIf >> line;
    cout << number << " " << line << endl;

    string line1;
    string line2;
    getline(fileIf, line1);
    getline(fileIf, line2);
    cout << line1 << endl << line2 << endl;

    char c;
    c = fileIf.get();
    cout << c << endl;

    while (!fileIf.eof()) {
        getline(fileIf, line1);
        cout << line1 << endl;
    }

    fileIf.close();*/

    /*int num = -7;
    if (valid1(num))
        cout << sqrt(num) << endl;
    else
        cout << "Wartosc ujemna" << endl;
    num = valid2(num);
    cout << sqrt(num) << endl;

    cout << "Podaj liczbe: " << endl;
    if ((cin >> num) && num >= 0)
        cout << sqrt(num) << endl;
    else
        cout << "Wartosc ujemna" << endl;

    do {
        cin.clear();
        cin.ignore();
        cout << "Podaj liczbe: " << endl;
        cin >> num;
        cout << "Blednie wczytano!" << endl;
    } while (!cin);

    assert(num >= 0);
    cout << sqrt(num) << endl;
    */

    /*try {
    double result = sqrt_function(-5);
    cout << "Wynik to: " << result << endl;
    }
    catch (int w1) {
        cout << "Zlapany wyjatek int " << w1 << endl;
    }
    catch (...) {
        cout << "Brak zdefiniowanego wyjatku" << endl;
    }
    cout << "Po sekcji try" << endl;*/

    try {
        double result = sqrt_function1(-5);
        cout << "Wynik to: " << result << endl;
    }
    catch (SquareRootError p) {
        p.error();
    }

    try {
        double result = sqrt_function2(-5);
        cout << "Wynik to: " << result << endl;
    }
    catch (Error* b) {
        b->error();
        delete b;
    }

    try {
        double result = sqrt_function1(-5);
        cout << "Wynik to: " << result << endl;
    }
    catch (Error& b) {
        b.error();
    }

    try {
        function_bad_alloc1();
    }
    catch (bad_alloc &ba) {
        cout << "function bad alloc: " << ba.what() << endl;
    }

    try {
        function_bad_alloc1();
    }
    catch (exception& e) {
        cout << "function1 exception: " << e.what() << endl;
    }
}
void zadanie1() {
    try {
        ifstream inputFile("kod.txt");
        if (!inputFile.is_open()) {
            throw runtime_error("Nie mozliwo otworzyc tego pliku");
        }
        char currentChar, nextChar;
        while (inputFile.get(currentChar)) {
            if (currentChar == '/' && inputFile.peek() == '/') {
                while (inputFile.get(nextChar) && nextChar != '\n');
            }
            else {
                cout << currentChar;
            }
        }
        inputFile.close();
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
void oczko() {
    int oczko = 21,
        suma = 0,
        liczba,
        udaneProby = 0,
        nieudaneProby = 0;
    try {
        while (suma < oczko) {
            cout << "Podaj dodatnia liczbe calkowita: ";

            if (!(cin >> liczba)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Bledne dane. Podaj liczbe calkowita");
            }
            if (suma + liczba > oczko) {
                throw PrzekroczenieOczka();
            }
            suma += liczba;
            udaneProby++;
        }
        cout << "Wygrales" << endl;
    }
    catch (PrzekroczenieOczka& e) {
        cerr << "Blad: " << e.what() << endl;
        nieudaneProby++;
    }
    catch(exception& e) {
        cerr << "Blad:" << e.what() << endl;
        nieudaneProby++;
    }

    cout << "Liczba udanych prob: " << udaneProby << endl;
    cout << "Liczba nieudanych prob: " << nieudaneProby << endl;
}

int main()
{
    //przykladowe();
    //zadanie1();
    //oczko();
    return 0;
}