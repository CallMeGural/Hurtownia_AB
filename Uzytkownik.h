#pragma once
#include <iostream>
#include <string>

using namespace std;

class Uzytkownik {
protected:
	unsigned short int stanowisko;
	string nazwisko;
	string imie;
	string miejscowosc;
public:
	void wypisz_dane() {
		cout << "Imie i nazwisko pracownika: " << imie << " " << nazwisko << endl;
	}
};