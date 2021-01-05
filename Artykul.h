#pragma once
#include <iostream>
#include <iomanip>
#include <string>

//#define NUMER_SERYJNY 6

using namespace std;

class Artykul {
	friend class ListaArtykulowWDziale;
	friend class Dzial;
protected:
	string dzial;
	string nazwaArtykulu;
	float cena;
	Artykul* next;
	Artykul* prev;
	//char numerSeryjny[NUMER_SERYJNY];
public:
	Artykul();
	//Artykul(string _dzial, string _nazwaArtykulu, float _cena, char _numerSeryjny[]);
	void wprowadzanie_Artykulu(string _dzial, string _nazwaArtykulu, float _cena);
	~Artykul();
	void wyswietl_info();
	void wyswietl_artykul_z_listy();
	void wycofaj_artykul();
	void zmien_nazwe_artykulu();
	void zmien_cene_artykulu();
};
