#pragma once
#include <iostream>
#include <string>
#include <conio.h> //_getch

//#define NUMER_SERYJNY 6

using namespace std;

class Artykul {
	friend class Kierownik;
	friend class Magazynier;
	friend void wyswietl_info(string nazwa_art);
protected:
	string dzial;
	string nazwa;
	double cena=-1;
	unsigned int ilosc=-1;
public:
	Artykul() {};
	~Artykul() {};
	void zmien_cene() {
		cout << "Zmien cene artykulu " << nazwa << ". Stara cena: " << cena << "\nPodaj nowa cene: ";
		double pom = cena;
		cin >> cena;
		cout << "Zmieniono cene artykulu " << nazwa << " na " << cena << "zl\nAby potwierdzic, nacisnij p.\nAby cofnac zmiany nacisnij c";
		if (_getch() == 'c') {
			cena = pom;
			cout << "Nie zapisano zmian. Stara cena: " << cena << endl;
		}
		else cout << "Potwierdzono zmiany\n";
	}
	void zmien_nazwe() {
		cout << "Zmien nazwe artykulu " << nazwa << "\nPodaj nowa nazwe: ";
		string pom = nazwa;
		cin >> nazwa;
		cout<<"Zmieniono nazwe artykulu na "<<nazwa<<"\nAby potwierdzic, nacisnij p.\nAby cofnac zmiany nacisnij c";
		if (_getch() == 'c') {
			nazwa = pom;
			cout << "Nie zapisano zmian. Stara nazwa: " << nazwa << endl;
		}
		else cout << "Potwierdzono zmiany\n";
	}
};
