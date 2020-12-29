#pragma once
#include "Artykul.h"

class ListaArtykulowWDziale {
	friend class Dzial;
protected:
	Artykul Art;
	unsigned int iloscArtWMagazynie;
	Artykul* head;
	Artykul* tail;
public:
	ListaArtykulowWDziale();
	~ListaArtykulowWDziale();
	void wyswietl_liste_art();
	void pushFront(string _dzial, string _nazwaArtykulu, float _cena);
	void pushBack(string _dzial, string _nazwaArtykulu, float _cena);
	void removeArt(Artykul* _art);
	void quickSort();
	void partitionList(Artykul* _lArt, Artykul* _pArt);
	void popFront();
	void popBack();

	///sortowanie raczej w klasie Dzial
	///void sortuj_liste_art();
	///wyszukiwanie raczej w klasie Dzial
	///void szukaj_art();
	void dodaj_art();
	bool czy_lista_pusta();

};