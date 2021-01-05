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
	bool czy_dzial_pusty = true;	/// czy to potrzebne?????
	ListaArtykulowWDziale listaArt;
public:
	Dzial();
	Dzial(string _nazwa);
	~Dzial();
	void szukaj_art();
	void sortuj_art_w_dziale();
	void wyswietl_art_w_dziale();
	void dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena);
	void dodaj_artykul_koniec(string _dzial, string _nazwaArtykulu, float _cena);
};