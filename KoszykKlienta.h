#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"
#include "ListaArtykulowWKoszyku.h"

using namespace std;

class KoszykKlienta {
protected:
	ListaArtykulowWKoszyku listaZakupow;

public:
	Artykul* wypisz_koszyk();
	void dodaj_do_koszyka(Artykul* art, int ilosc);
};