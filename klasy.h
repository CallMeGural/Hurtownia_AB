#pragma once
#include <iostream>
#include <string>
#include <fstream> //obsluga plikow
#include <conio.h> //getch

using namespace std;

class Uzytkownik {
protected:
	static int licznik;
	unsigned short int stanowisko;
	string nazwisko;
	string imie;
	string miejscowosc;
public:
	Uzytkownik() { licznik++; }
	~Uzytkownik() { licznik--; }
	void wypisz_dane(){
		cout << "Imie i nazwisko pracownika: " << imie << " " << nazwisko << endl;
	}
};

class Dzial {
	friend class Kierownik;
protected:
	static int nr_dzialu;
	string nazwa_dzialu;
	bool czy_dzial_pusty = true;
public:
	Dzial() {};
	~Dzial() {};
};

class Artykul {
	friend class Kierownik;
protected:
	string dzial;
	string nazwa;
	double cena;
	unsigned int ilosc;
public:
	Artykul() {};
	~Artykul() {};
	void wyswietl_info() {
		cout << "Wyswietlam informacje o artykule: \nNazwa artykulu: "<<nazwa<<"	Cena: "<<cena<<"	Dzial: "<<dzial<<"	Ilosc w magazynie: "<<ilosc<<endl;
	}
	void zmien_cene() {
		cout << "Zmien cene artykulu " << nazwa << ". Stara cena: " << cena << "\nPodaj nowa cene: ";
		double pom = cena;
		cin >> cena;
		cout << "Zmieniono cene artykulu " << nazwa << " na " << cena << "zl\nAby potwierdzic, nacisnij p.\nAby cofnac zmiany nacisnij c";
		if (getch() == 'c') {
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
		if (getch() == 'c') {
			nazwa = pom;
			cout << "Nie zapisano zmian. Stara nazwa: " << nazwa << endl;
		}
		else cout << "Potwierdzono zmiany\n";
	}
};

class Kierownik : public Uzytkownik {
public:
	Kierownik() {
		cout << "Podaj imie kierownika: ";
		cin >> imie;
		cout << "Podaj nazwisko kierownika: ";
		cin >> nazwisko;
		cout << "Podaj miejsce zamieszkania kierownika (miejscowosc): ";
		cin >> miejscowosc;
	};
	~Kierownik() {};

	void dodaj_artykul() {
		ofstream plik;
		plik.open("artykuly.txt");
		if (plik.good()) {
			Artykul pom_art;
			cout << "Dodawanie artykulu do magazynu.\nPodaj nazwe artykulu: ";
			cin >> pom_art.nazwa;
			plik << pom_art.nazwa;
			cout << "Podaj nr dzialu, do ktorego chcesz przypisac artykul " << pom_art.nazwa << ": ";
			cin >> pom_art.dzial;
			plik << pom_art.dzial;
			cout << "Podaj cene za jedna sztuke artykulu " << pom_art.nazwa << ": ";
			cin >> pom_art.cena;
			plik << pom_art.cena;
			cout << "Podaj ilosc danego artykulu: ";
			cin >> pom_art.ilosc;
			plik << pom_art.ilosc;
			plik.close();
			cout << "Artykul " << pom_art.nazwa << " dodano do magazynu.\n";
		}
		else cout << "Nie udalo sie otworzyc pliku z artykulami!\n";
	}
};