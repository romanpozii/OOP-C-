#pragma once
#include <iostream>
#include <map>

using namespace std;

class Dictionary
{
private:
	map<string, string> words;
public:
	Dictionary() {}
	void dodajSlowo(const string& slowo, const string& tlumaczenie);
	void usunSlowo();
	void wyswietlZawartosc();
	void wyswietlTlumaczenie();
	void wyswietlZawartoscAlfabetycznie();
};

