#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "KoszykKlienta.h"

using namespace std;

class Klient {
private:
	string imie, nazwisko;
	int haslo;
	KoszykKlienta koszyk;
public:
	Klient();
	bool logowanie_klient(int pom);
	int logowanie();
	void menu_Klient(Dzial& _Dzial);
	void przegladaj_art_k(Dzial& _dzial);
	void szukaj_art_k(Dzial& _dzial);
	void przegladaj_koszyk();
	int wypisz_liste_klientow();
	void zaplac();
};