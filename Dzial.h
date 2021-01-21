#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "ListaArtykulowWDziale.h"

using namespace std;

class Dzial {
	friend class Klient;

protected:
	static int nr_dzialu;
	string nazwa_dzialu;
	bool czy_dzial_pusty = true;
	ListaArtykulowWDziale listaArt;
public:
	Dzial();
	Dzial(string _nazwa);
	~Dzial();
	Artykul* szukaj_art();
	Artykul* szukaj_art_return_wsk(string nazw_art);
	void sortuj_art_w_dziale();
	Artykul* wyswietl_art_w_dziale();
	int wyswietl_art_w_dziale_return_nr();
	void dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt);
	void dodaj_artykul();
	void wczytaj_artykuly_z_pliku();
	void usun_artykul();
	void zapisz_artykuly_do_pliku();
};