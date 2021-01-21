#pragma once
#include "Artykul.h"

class ListaArtykulowWDziale {
	friend class Dzial;
	friend class Klient;
protected:
	Artykul Art;
	unsigned int iloscArtWMagazynie;
	Artykul* head;
	Artykul* tail;
public:
	ListaArtykulowWDziale();
	~ListaArtykulowWDziale();
	Artykul* wyswietl_liste_art();
	int wyswietl_liste_art_return_nr();
	void pushFront(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt);
	void pushBack(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt);
	void removeArt(Artykul* _art);
	void quickSort();
	void partitionList(Artykul* _lArt, Artykul* _pArt);
	void popFront();
	void popBack();
	void zapis_do_pliku();
	void szukaj_artykulu(string nazwa);
	bool zmien_ilosc_art(string nazwa);
	void zmien_nazwe_art(string nazwa);
	bool czy_lista_pusta();
};