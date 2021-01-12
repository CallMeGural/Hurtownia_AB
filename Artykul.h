#pragma once
#include <iostream>
#include <string>
#include <conio.h> //_getch

using namespace std;

class Artykul {
	friend class Kierownik;
	friend class Magazynier;
	friend void wyswietl_info(string nazwa_art);
	friend class Lista_artykulow;
	friend class Wypozyczenie;
	friend class Zakup;
	friend class Klient;
	friend class Koszyk_klienta;
protected:
	string dzial;
	string nazwa;
	double cena = -1;
	unsigned int ilosc = -1;
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
		fstream plik;
		plik.open("artykuly.txt", ios::out | ios::app);
		string pom1,pom2;
		cout << "Zmien nazwe artykulu.\nPodaj nazwe artykulu do zmiany: ";
		cin >> pom2;
		while (!plik.eof()) {
			plik >> pom1;
			if (pom1 == pom2) {
				cout << "\nPodaj nowa nazwe: ";
				cin >> pom1;
				///DOKONCZYC USUWANIE LINIJKI I DODAWANIE NOWEJ ZE ZMIENIONA NAZWA
			}
		}
		string pom = nazwa;
		cin >> nazwa;
		cout << "Zmieniono nazwe artykulu na " << nazwa << "\nAby potwierdzic, nacisnij p.\nAby cofnac zmiany nacisnij c";
		if (_getch() == 'c') {
			nazwa = pom;
			cout << "Nie zapisano zmian. Stara nazwa: " << nazwa << endl;
		}
		else cout << "Potwierdzono zmiany\n";
	}
	void dane_art() {
		cout << "Nazwa artykulu: " << nazwa << ". Dzial: " << dzial << ". Cena za sztuke: " << cena << ". Ilosc w magazynie: " << ilosc << endl;
	}
};