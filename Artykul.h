#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Artykul {
	friend class ListaArtykulowWDziale;
	friend class Dzial;
	friend class ListaArtykulowWKoszyku;
	friend class Klient;
	friend class KoszykKlienta;
protected:
	string dzial;
	string nazwaArtykulu;
	float cena;
	unsigned int ilosc_szt;
	Artykul* next;
	Artykul* prev;
public:
	Artykul();
	void wprowadzanie_Artykulu(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt);
	~Artykul();
	void wyswietl_info();
	void wyswietl_artykul_z_listy();
	void zmien_nazwe_artykulu();
	void zmien_cene_artykulu();
};