
#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"
#include "Uzytkownik.h"

using namespace std;
/// =======OPIS KLASY=======
///	Pola:
///		te same co w klasie Uzytkownik
///	Metody:
///		dodaj_artykul() - jako kierownik mozemy dodac artykul do magazynu. Stan magazynu zapisany jest w pliku artykuly.txt. Metoda ta 
///						  dodaje na koniec pliku takie dane jak: nazwa artykulu, przynaleznosc do dzialu, cena za sztuke, ilosc
/// =======OPIS KLASY=======
class Kierownik : public Uzytkownik {
public:
	/*Kierownik() {
		cout << "Podaj imie kierownika: ";
		cin >> imie;
		cout << "Podaj nazwisko kierownika: ";
		cin >> nazwisko;
		cout << "Podaj miejsce zamieszkania kierownika (miejscowosc): ";
		cin >> miejscowosc;
	};*/
	Kierownik() {
		cout << "Wybierz swoje dane z listy lub utwórz nowego kierownika.\n";
		fstream plik;
		string im, nazw, miejs;
		plik.open("kierownicy.txt");
		if (plik.good()) {
			int licznik = 0;
			while (!plik.eof()) {
				plik >> im;
				plik >> nazw;
				plik >> miejs;
				cout << licznik << ". " << im << " " << nazw << ", " << miejs << endl;
			}
			cout << licznik << ". Utworz nowego Kierownika\n";
			//DODANIE WYBORU KIEROWNIKA -> podajesz numer <1;x> i tworzy sie kierownika o danych ktore juz ktos podal, albo tworzy sie nowego wariata
		}
		else cout << "BLAD OTWARCIA PLIKU kierownicy.txt!\n";
		plik.close();
	};
	~Kierownik() {};

	void dodaj_artykul() {
		ofstream plik;
		plik.open("artykuly.txt",ios::out | ios::app); ///ios::out|ios::app nadpisywanie
		if (plik.good()) {
			Artykul pom_art;
			cout << "Dodawanie artykulu do magazynu.\nPodaj nazwe artykulu: ";
			cin >> pom_art.nazwa;
			plik << pom_art.nazwa+"\n";
			cout << "Podaj nr dzialu, do ktorego chcesz przypisac artykul " << pom_art.nazwa << ": ";
			cin >> pom_art.dzial;
			plik << pom_art.dzial << "\n";
			cout << "Podaj cene za jedna sztuke artykulu " << pom_art.nazwa << ": ";
			cin >> pom_art.cena;
			plik << pom_art.cena << "\n";
			cout << "Podaj ilosc danego artykulu: ";
			cin >> pom_art.ilosc;
			plik << pom_art.ilosc <<endl;
			plik.close();
			cout << "Artykul " << pom_art.nazwa << " dodano do magazynu.\n";
		}
		else cout << "Nie udalo sie otworzyc pliku z artykulami!\n";
	}
};