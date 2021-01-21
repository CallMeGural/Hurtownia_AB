#pragma once
#include <iostream>
#include <fstream>
#include "Dzial.h"
#include <Windows.h>

using namespace std;

class Magazynier {
private:
	int haslo;
	string imie, nazwisko;
	Magazynier* next;
public:
	Magazynier();
	void menu_magazynier(Dzial& _Dzial);
	bool logowanie_magazynier(int pom);
	int logowanie();
	void przegladaj_art_m(Dzial& _dzial);
	int wypisz_liste_magazynierow();
	void szukaj_art_m(Dzial& _dzial);
};