#pragma once
#include <iostream>
#include <fstream>
#include "Buffer.h"

using namespace std;

class BufferFile : public Buffer
{
private:
	string filePath;
	shared_ptr<ofstream> fileStream;
public:
	BufferFile(const string& path) : filePath(path) {
		fileStream = make_shared<ofstream>(filePath, ios::app);
		if (!fileStream->is_open()) {
			cerr << "Blad otwarcia pliku" << endl;
		}

		cout << "Konstruktor klasy BufferFile" << endl;
	}
	~BufferFile() {
		fileStream->close();
		cout << "Destruktor klasy BufferFile" << endl;
	}

	void add(int a) override {
		*fileStream << a << endl;
	}
	
	void write() const override {
		ifstream file(filePath);
		if (file.is_open()) {
			cout << "Zawartosc pliku BufferFile: " << endl;
			int number;
			while (file >> number) {
				cout << number << " ";
			}
			cout << endl;
			file.close();
		}
		else {
			cerr << "Blad otwarcia pliku do odczytu" << endl;
		}
	}
};

