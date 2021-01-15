#pragma once
#include <iostream>
#include <windows.h>
#include "Magazynier.h"
#include "Dzial.h"
#include "Klient.h"

using namespace std;

bool haslo_kierownik() {
	cout << "Podaj haslo uwierzytelniajace: ...\n\tHaslo: ";
	int haslo, proba = 3;
	while (proba > 0) {
		cin >> haslo;
		if (haslo == 1234) {
			cout << "\tHaslo prawidlowe\n";
			return true;
			break;
		}
		else {
			proba -= 1;
			cout << "\tBledne haslo! Pozostalo " << proba << " prob\n\tHaslo: ";
		}
	}
	return false;
	
}

void menu_magazynier(Dzial& _Dzial) {
	int opcja = -1;
	bool dzialanie = 1;
	while (dzialanie) {
		system("cls");
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------- MENU - MAGAZYNIER ----------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nWybierz opcje:" << endl;
		cout << "\t1. Wyswietl liste artykulow" << endl;
		cout << "\t2. Szukaj artykul" << endl;
		cout << "\t0. Wyloguj" << endl;
		cout << "\nPodaj numer opcji: ";
		cin >> opcja;

		switch (opcja) {
		case 1:
			_Dzial.wyswietl_art_w_dziale();
			break;
		case 2:
			_Dzial.szukaj_art();
			break;
		case 0:
			/// tu nwm czy calkiem czy nie 
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}

void menu_Klient(Dzial& _Dzial) {
	int opcja = -1;
	bool dzialanie = 1;
	while (dzialanie) {
		system("cls");
		cout << "=======================================================================================" << endl;
		cout << "----------------------------------- MENU - KLIENT ------------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nWybierz opcje:" << endl;
		cout << "\t1. Pzegladaj artykuly" << endl;
		cout << "\t0. Wyloguj" << endl;

		cout << "\nPodaj numer opcji: ";
		cin >> opcja;

		switch (opcja) {
		case 1:
			_Dzial.wyswietl_art_w_dziale();
			break;
		case 0:
			/// tu nwm czy calkiem czy nie 
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}

void menu_Kierownik(Dzial& _Dzial) {
	int opcja = -1;
	bool dzialanie = 1;
	while (dzialanie) {
		system("cls");
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------- MENU - KIEROWNIK -----------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nWybierz opcje:" << endl;
		cout << "\t1. Dodaj nowy artykul do magazynu" << endl;
		cout << "\t2. Usun artykul z magazynu" << endl;
		cout << "\t0. Wyloguj" << endl;
		cout << "\nPodaj numer opcji: ";
		cin >> opcja;

		switch (opcja) {
		case 1:
			_Dzial.dodaj_artykul();
			break;
		case 2:
			_Dzial.usun_artykul();
			break;
		case 0:
			/// tu nwm czy calkiem czy nie 
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}

bool logowanie_magazyn() {
	Magazynier m;
	int haslo_do_logowania=m.logowanie();
	if (m.logowanie_magazynier(haslo_do_logowania)) return true;
	else return false;
}

bool logowanie_klient() {
	Klient k;
	int haslo_do_logowania = k.logowanie();
	if (k.logowanie_klient(haslo_do_logowania)) return true;
	else return false;
}

void main_menu(Dzial & _Dzial) {
	int profil = -1;
	bool dzialanie = 1;
	while (dzialanie) {
		system("cls");
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------------- MENU -----------------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nLOGOWANIE - wybierz:" << endl;
		cout << "\t1. Klient" << endl;
		cout << "\t2. Magazynier" << endl;
		cout << "\t3. Kierownik" << endl;
		cout << "\t0. Zakoncz program" << endl;

		cout << "\nPodaj numer opcji: ";
		cin >> profil;

		switch (profil) {
		case 1: {
			if (logowanie_klient())
				menu_Klient(_Dzial);
			else {
				cout << "Odmowa dostepu!\n";
				Sleep(1000);
			}
		}
			break;
		case 2: {
			if (logowanie_magazyn())
				menu_magazynier(_Dzial);
			else {
				cout << "Odmowa dostepu!\n";
				Sleep(1000);
			}
		}
			break;
		case 3: {
			if (haslo_kierownik())
				menu_Kierownik(_Dzial);
			else {
				cout << "Odmowa dostepu\n!";
				Sleep(1000);
			}
		}
			  break;
		case 0:
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}

