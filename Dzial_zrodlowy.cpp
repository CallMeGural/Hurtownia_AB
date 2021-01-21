#include "Dzial.h"
#include "Artykul.h"
#include <fstream>
#include <Windows.h>

int Dzial::nr_dzialu = 0;

Dzial::Dzial() {
	nr_dzialu++;
}

Dzial::Dzial(string _nazwa) {
	nazwa_dzialu = _nazwa;
}

Dzial::~Dzial() {
	nr_dzialu--;
}

Artykul* Dzial::szukaj_art() {
	string pom_nazw;
	Artykul* znaleziony = new Artykul;
	char opcja = 0;

	while (opcja != 'w' && opcja != 'W') {
		system("cls");
		cout << "=======================================================================================================================" << endl;
		cout << "----------------------------------------------- WYSZUKIWANIE - ARTYKULU -----------------------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;
		cout << "\n\tPodaj nazwe artykulu:";
		cin >> pom_nazw;
		cout << endl;
		znaleziony = this->szukaj_art_return_wsk(pom_nazw);
		if (znaleziony) {
			cout << "|" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			znaleziony->wyswietl_artykul_z_listy();
		}
		else {
			cout << "\n\tBrak artykulu o podanej nazwie na magazynie.\n\n";
		}

		cout << "\n=======================================================================================================================\n";
		cout << "[S - szukaj ponownie] [W - wyjdz] ";  if (znaleziony) cout << "[D - sprawdz dostepne dzialania dla znalezionego artykulu]";
		cout << "\nWybierz opcje: ";

		cin >> opcja;
		switch (opcja) {
		case 'w':

			break;
		case 'W':

			break;
		case 'S':

			break;
		case 's':

			break;
		case 'D':
			return znaleziony;
			break;
		case 'd':
			return znaleziony;
			break;
		default:
			cout << "\n\tNIE MA TAKIEJ OPCJI.";
			Sleep(2000);
			opcja = 'w';
			break;
		}
	}
	return nullptr;
}

Artykul* Dzial::szukaj_art_return_wsk(string nazw_art) {

	if (listaArt.czy_lista_pusta()) {
		Artykul* pom = new Artykul;
		pom = listaArt.head;
		while (pom && (pom->nazwaArtykulu != nazw_art)) pom = pom->next;
		if (pom != nullptr) {
			return pom;
		}
		else return nullptr;
	}
	else {
		return nullptr;
	}
}

void Dzial::sortuj_art_w_dziale() {
	listaArt.quickSort();
}

Artykul* Dzial::wyswietl_art_w_dziale() {
	Artykul* art = listaArt.wyswietl_liste_art();
	return art;
}
int Dzial::wyswietl_art_w_dziale_return_nr() {
	int k = listaArt.wyswietl_liste_art_return_nr();
	return k;

}

void Dzial::dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt) {
	listaArt.pushFront(_dzial, _nazwaArtykulu, _cena, _ilosc_szt);
}

void Dzial::dodaj_artykul() {
	string pom_nazw = "";
	float pom_cena = 0.;
	int pom_ilosc = 0;
	char decyzja = ' ';
	system("cls");
	cout << "=======================================================================================================================" << endl;
	cout << "------------------------------------------------- DODAWANIE - ARTYKUKU£U ----------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\n Dzia³: " << this->nazwa_dzialu << endl;
	cout << "\nPodaj nazwe artykulu: ";
	cin >> pom_nazw;

	if (listaArt.zmien_ilosc_art(pom_nazw)) {
		do {
			cout << "Podaj cene artykulu: ";
			cin >> pom_cena;
		} while (pom_cena <= 0.);///sprawdzanie poprawnosci danych
		do {
			cout << "Podaj ilosc [szt]: ";
			cin >> pom_ilosc;
		} while (pom_ilosc <= 0);///sprawdzanie poprawnosci danych

		cout << "\nCzy na pewno dodaæ ten artykul? [t/n]: ";
		cin >> decyzja;
		if (decyzja == 't') {
			listaArt.pushBack(this->nazwa_dzialu, pom_nazw, pom_cena, pom_ilosc);
			cout << "\nDodano artykul do dzialu." << endl;
		}
		else {
			cout << "\nAnulowano dodawanie artykulu." << endl;
		}
	}
	system("PAUSE");
}

void Dzial::usun_artykul() {
	string pom_nazw = "";
	char decyzja = ' ';
	Artykul* usuwany = new Artykul;

	system("cls");
	cout << "=======================================================================================================================" << endl;
	cout << "------------------------------------------------ USUWANIE - ARTYKUKU£U ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\n Dzia³: " << this->nazwa_dzialu << endl;
	cout << "\nPodaj nazwe artykulu, ktory chcesz usunac: ";
	cin >> pom_nazw;

	usuwany = this->szukaj_art_return_wsk(pom_nazw);
	this->listaArt.removeArt(usuwany);

	cout << "\nPomyslnie usunieto artykul z dzialu.\nWcisnij ENTER...";
	if (getchar()) return;
}

void Dzial::wczytaj_artykuly_z_pliku() {
	fstream plik_art;
	plik_art.open("artykuly.txt", ios::in);

	string pom_nazwD = "";
	string pom_nazwA = "";
	float pom_cena = 0.;
	int pom_ilosc = 0;

	if (plik_art.good()) {
		while (!plik_art.eof()) {
			plik_art >> pom_nazwD;
			plik_art >> pom_nazwA;
			plik_art >> pom_cena;
			plik_art >> pom_ilosc;
			listaArt.pushBack(pom_nazwD, pom_nazwA, pom_cena, pom_ilosc);
		}
	}
	plik_art.close();
}

void Dzial::zapisz_artykuly_do_pliku() {
	listaArt.zapis_do_pliku();
	cout << "Zapisano pomyslnie.\n";
}
