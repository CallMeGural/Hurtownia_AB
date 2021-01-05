#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "ListaArtykulowWDziale.h"
//#include "Artykul.h"

using namespace std;

class Dzial {
	friend class Kierownik;
	//friend class ListaArtykulowWDziale;
protected:
	static int nr_dzialu;
	string nazwa_dzialu;
	bool czy_dzial_pusty = true;	/// czy to potrzebne????? pewex - jesli dzial bedzie pusty, to bedzie mozna go usunac
	ListaArtykulowWDziale listaArt;
public:
	Dzial();
	Dzial(string _nazwa);
	~Dzial();
	
	void wyswietl_info(string nazwa_art) { /// zastanawiam sie nad tym, czy to powinno byc tutaj xd
	ifstream plik;
	string pom;
	int pom2;
	plik.open("artykuly.txt");
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> pom;
			if (pom == nazwa_art) cout << "Wyswietlam informacje o artykule: \nNazwa artykulu: " << nazwa_art << "	Cena: ";
			plik >> pom2;
			cout << pom2 << "	Dzial: ";
			plik >> pom;
			cout << pom << "	Ilosc w magazynie: ";
			plik >> pom2;
			cout<<pom2 << endl;
		}
	}
}
	void szukaj_art();
	void sortuj_art_w_dziale();
	void wyswietl_art_w_dziale();
	void dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena);
	void dodaj_artykul_koniec(string _dzial, string _nazwaArtykulu, float _cena);
};
