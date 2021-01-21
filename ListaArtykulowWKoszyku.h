#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"

#define ROZM_WYP_LIST 10

using namespace std;

class ListaArtykulowWKoszyku {
	friend class KoszykKlienta;

protected:
	int ilosc_art_na_liscie;
	Artykul* head_koszyk;
	Artykul* tail_koszyk;
public:
	ListaArtykulowWKoszyku();
	Artykul* wyswietl_liste_art();
	void removeArt(Artykul* art);
	void pushBack(string nazwa_art, float cene_art, string nazwa_dzialu, int ilosc);
};