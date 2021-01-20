#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"

#define ROZM_WYP_LIST 10

using namespace std;

class ListaArtykulowWKoszyku {
	friend class Koszyk_klienta;
	
protected:
	///Artykul art;
	int ilosc_art_na_liscie;
	Artykul* head_koszyk;
	Artykul* tail_koszyk;
public:
	ListaArtykulowWKoszyku() {
		ilosc_art_na_liscie = 0;
		head_koszyk = nullptr;
		tail_koszyk = nullptr;
	}


	Artykul* wyswietl_liste_art() {
		ifstream plik;
		string nazwa_art = "";
		string nazwa_dzialu = "";
		float cena_art = 0.;
		int _ilosc = 0;
		plik.open("zakup.txt");
		

		int i = 0;		/// minimalny numer do wyswietlenia na danej stronie
		int max_i = ROZM_WYP_LIST;	/// ostatni nuimer do wyswietlenia na danej strone
		Artykul* pom = head_koszyk;
		char opcja = 0;	/// dostaepne dzialania 
		int k = 0;/// potrzebne do poruszania siê po stronach listy asrtykulu
		int numer_art = -1;/// wybieranie artykulu
		int j = 0;///potrzebny przy wybieraniu artykulu

		while (opcja != 'w' && opcja != 'W') {
			system("cls");
			cout << "=======================================================================================================================" << endl;
			cout << "------------------------------------------ LISTA - ARTYKULOW - W - KOSZYKU --------------------------------------------" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "=======================================================================================================================" << endl;

			cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

			if (plik.good())
				while (!plik.eof()) {
					plik >> nazwa_dzialu;
					plik >> nazwa_art;
					plik >> cena_art;
					plik >> _ilosc;

					cout << setw(5) << i << ".|" << setw(10) << nazwa_dzialu << " |" << setw(30) << nazwa_art << " |" << setw(20) << cena_art << " |" << setw(20) << _ilosc << endl;
					i++;
				}
			plik.close();

			cout << "\n=======================================================================================================================\n";
			cout << "[P - poprzednia strona] [N - nastepna strona] [W - wyjdz] [D - dzialania na artykule]" << endl;
			cout << "Wybierz opcje: ";

			cin >> opcja;
			switch (opcja) {
			case 'd':
			case 'D':
				cout << "Podaj numer artykulu: ";
				cin >> numer_art;
				pom = head_koszyk;
				while (pom && (j < numer_art)) {
					pom = pom->next;
					j++;
				}
				if (pom && (j == numer_art)) return pom;
				else {
					cout << "\n\tNIE MA TAKIEGO ARTYKULU.\nWcisnij dowolny przyisk aby wrocic do MENU...";
					system("PAUSE");
					return nullptr;
				}
				break;
			case 'N':
				if (!(pom->next)) {
					cout << "Nie ma nastepnej strony.";
					system("PAUSE");
					opcja = 'w';
				}
				else max_i += ROZM_WYP_LIST;
				break;
			case 'n':
				if (!pom->next) {
					cout << "Nie ma nastepnej strony.";
					system("PAUSE");
					opcja = 'w';
				}
				else max_i += ROZM_WYP_LIST;
				break;
			case 'p':
				k = max_i - (2 * ROZM_WYP_LIST);
				if (k < 0)k = 0;
				pom = head_koszyk;
				for (i = 0; i < k; i++) {
					pom = pom->next;
				}
				max_i = i + ROZM_WYP_LIST;
				break;
			case 'P':
				k = max_i - (2 * ROZM_WYP_LIST);
				if (k < 0)k = 0;
				pom = head_koszyk;
				for (i = 0; i < k; i++) {
					pom = pom->next;
				}
				max_i = i + ROZM_WYP_LIST;
				break;
			case 'w':
			case 'W':
				return nullptr;
				break;
			default:
				cout << "\n\tNIE MA TAKIEJ OPCJI.\nWcisnij dowolny przycisk...";
				system("PAUSE");
				return nullptr;
				break;

			}
		}
	}

	void removeArt(Artykul* _art) {
		ilosc_art_na_liscie--;
		if (_art->prev) _art->prev->next = _art->next; ///poprzedni wskazuje na nastepny
		else head_koszyk = _art->next;	/// nie ma poprzednika czyli pierwszy element
		if (_art->next) _art->next->prev = _art->prev; ///nastepny wskazuje na poprzeni
		else tail_koszyk = _art->prev; /// nie ma nastepnika czyli ostatni element

		delete _art; /// zwalniamy pamiec
	}

	void pushBack(string nazwa_art, float cene_art, string nazwa_dzialu, int _ilosc) {
		Artykul* pom = new Artykul;
		pom->dzial = nazwa_dzialu;
		pom->nazwaArtykulu = nazwa_art;
		pom->cena = cene_art;
		pom->ilosc_szt = _ilosc;
		pom->prev = tail_koszyk;
		pom->next = nullptr;
		tail_koszyk = pom;
		ilosc_art_na_liscie++;
		if (pom->prev) pom->prev->next = pom; /// zachowanie ciaglosci wskaznikow next 
		else head_koszyk = pom; /// gdy bedzie jedynym artykulem
	}
};