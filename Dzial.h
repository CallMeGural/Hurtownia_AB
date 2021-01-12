#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Artykul.h"
#include "Magazynier.h"

using namespace std;
/// =======OPIS KLASY=======
///	Pola:
///		nr_dzialu - nr ten podajemy podczas dodawania art do dzialu - dzieki temu nie musimy podawac dokladnej nazwy dzialu
///		nazwa_dzialu - logicznie
///		czy_dzial_pusty - blokada usuwania dzialu. Usuniecie dzialu przez Kierownika bedzie mozliwe jesli dzial bedzie pusty
///	Metody:
///	szukaj_art - metoda przechodzi przez plik .txt, i wyswietla dane artykulu o podanej nazwie w danym dziale
///	sortuj_art_w_dziale - sortuje po nazwie artykuly w danym dziale
///
/// =======OPIS KLASY=======
class Dzial {
	friend class Kierownik;
	//friend class ListaArtykulowWDziale;
protected:
	static int nr_dzialu;
	string nazwa_dzialu;
	bool czy_dzial_pusty = true;	/// czy to potrzebne????? pewex - jesli dzial bedzie pusty, to bedzie mozna go usunac
	//ListaArtykulowWDziale listaArt;
public:
	Dzial();
	Dzial(string _nazwa);
	~Dzial();

	
	void szukaj_art() {
		cout << "Szukaj art w dziale po nazwie\n";
	}
	void sortuj_art_w_dziale() {
		cout << "Sortuj art w dziale - po nazwie\n";
	}
	void wyswietl_art_w_dziale() {
		cout << "Wyswietlam art w dziale - tutaj bedzie lista, przez ktora bedziemy przechodzic i bedzie wyswietlany caly ten syf\n";
	}
	void dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena);
	void dodaj_artykul_koniec(string _dzial, string _nazwaArtykulu, float _cena);
};

