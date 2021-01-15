#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <time.h>
#include "Artykul.h"
#include "Uzytkownik.h"
#include "Reklamacja.h"
#include "Zakup.h"
#include "Wypozyczenie.h"
#include "Magazynier.h"


using namespace std;

class Klient : public Uzytkownik {
	friend class Magazynier;
	friend class Zakup;
private:
	string nr_konta;

protected:
	unsigned short int id_klienta;

public:
	Koszyk_klienta* koszyk_klienta;
	Reklamacja reklamacja;
	Wypozyczenie wypozycz;
	Klient() {
		cout << "Tworze klienta\n";
	}
	~Klient() {
		cout << "Usuwam klienta\n";
	}
	virtual void wyswietl_dane_klienta() {
		cout << "\nImie i nazwisko klienta:\n" << Uzytkownik::imie << " " << Uzytkownik::nazwisko << "\nNumer ID klienta:\n" << id_klienta << endl;
	}
	void zglos_reklamacje() {
		cout << "Dla jakiego artykulu chcesz zlozyc formularz by dokonac reklamacji?\n";
		Artykul art;
		reklamacja.art = art;
	}
	void wyswietl_artykuly() {
		fstream plik;
		Artykul art;
		int licznik = 1;
		plik.open("artykuly.txt", ios::out | ios::app);
		if (plik.good()) {
			while (!plik.eof()) {
				plik >> art.nazwa;
				plik >> art.dzial;
				plik >> art.cena;
				plik >> art.ilosc;
				cout << licznik << ". ";
				art.dane_art();
				licznik++;
			}
		}
		else cout << "BLAD OTWARCIA PLIKU artykuly.txt!\n";
		plik.close();
	}
	void kupuj() {
		Zakup kupno(koszyk_klienta);
		wyswietl_artykuly();
		kupno.dodaj_art_do_koszyka();
	}
	//void wypozycz() {
		//wypozycz.dodaj_do_koszyka();
		//time_t t = time(0);   // get time now
		//tm* now = localtime(&t);
		//cout << now->tm_year + 1900 << '-' << now->tm_mon + 1 << '-' << now->tm_mday << "\n";
		/*
		wypozycz.data_wypozyczenia = time(NULL);
		wypozycz.data_zdania = wypozycz.data_wypozyczenia + wypozycz.liczba_dni;
		wypozycz.koszt_wypozyczenia = wypozycz.art.cena * 0.1;
		*/
	//}
};