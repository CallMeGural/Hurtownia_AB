#include "ListaArtykulowWDziale.h"
#include <fstream>

#define ROZM_WYP_LIST 10

ListaArtykulowWDziale::ListaArtykulowWDziale() {
	iloscArtWMagazynie = 0;
	head = nullptr;
	tail = nullptr;
}

ListaArtykulowWDziale::~ListaArtykulowWDziale() {
	while (iloscArtWMagazynie) popFront();
}

Artykul* ListaArtykulowWDziale::wyswietl_liste_art() {
	///inicjalizacja zmiennych
	int i = 0;		/// minimalny numer do wyswietlenia na danej stronie
	int max_i = ROZM_WYP_LIST;	/// ostatni nuimer do wyswietlenia na danej strone
	Artykul* pom = head;
	char opcja = 0;/// dostaepne dzialania 
	int k = 0;/// potrzebne do poruszania siê po stronach listy asrtykulu
	int numer_art = -1;/// wybieranie artykulu
	int j = 0;///potrzebny przy wybieraniu artykulu
	///petla glowna - container
	while (opcja != 'w' && opcja != 'W') {
		system("cls");
		///graficzne przedstawienie
		cout << "=======================================================================================================================" << endl;
		cout << "------------------------------------------- LISTA - ARTYKULOW - W - MAGAZYNIE --------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;

		cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		///wyswietlanie artykulu
		if (pom) {
			do {
				cout << setw(5) << i << ".";
				pom->wyswietl_artykul_z_listy();
				i++;
				pom = pom->next;
			} while (pom && i < max_i);
		}
		cout << "\n=======================================================================================================================\n";
		cout << "[P - poprzednia strona] [N - nastepna strona] [W - wyjdz] [S - sortuj liste artykulow] [D - dzialania na artykule]" << endl;
		cout << "Wybierz opcje: ";

		cin >> opcja;
		switch (opcja) {
		case 'd':
		case 'D':
			cout << "Podaj numer artykulu: ";
			cin >> numer_art;
			pom = head;
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
			///przechodzenie miedzy poprzednia a nastepna strona
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
			pom = head;
			for (i = 0; i < k; i++) {
				pom = pom->next;
			}
			max_i = i + ROZM_WYP_LIST;
			break;
		case 'P':
			k = max_i - (2 * ROZM_WYP_LIST);
			if (k < 0)k = 0;
			pom = head;
			for (i = 0; i < k; i++) {
				pom = pom->next;
			}
			max_i = i + ROZM_WYP_LIST;
			break;
		case 'w':
		case 'W':
			return nullptr;
			break;
		case 'S':
		case 's':
			i = 0;
			max_i = ROZM_WYP_LIST;
			quickSort();
			pom = head;
			break;
		default:
			cout << "\n\tNIE MA TAKIEJ OPCJI.\nWcisnij dowolny przycisk...";
			system("PAUSE");
			return nullptr;
			break;

		}
	}

}

int ListaArtykulowWDziale::wyswietl_liste_art_return_nr() {
	///inicjalizacja zmiennych
	int i = 0;		/// minimalny numer do wyswietlenia na danej stronie
	int max_i = ROZM_WYP_LIST;	/// ostatni nuimer do wyswietlenia na danej strone
	Artykul* pom = head;
	char opcja = 0;/// dostaepne dzialania 
	int k = 0;/// potrzebne do poruszania siê po stronach listy asrtykulu
	int numer_art = -1;/// wybieranie artykulu
	int j = 0;///potrzebny przy wybieraniu artykulu
	///glowna petla - container
	while (opcja != 'w' && opcja != 'W') {
		system("cls");
		///przedstawienie graficzne
		cout << "=======================================================================================================================" << endl;
		cout << "------------------------------------------- LISTA - ARTYKULOW - W - MAGAZYNIE --------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;

		cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		///wyswietlanie artykulow
		if (pom) {
			do {
				cout << setw(5) << i << ".";
				pom->wyswietl_artykul_z_listy();
				i++;
				pom = pom->next;
			} while (pom->next && i < max_i);
		}
		cout << "\n=======================================================================================================================\n";
		cout << "[P - poprzednia strona] [N - nastepna strona] [W - wyjdz] [S - sortuj liste artykulow] [D - dzialania na artykule]" << endl;
		cout << "Wybierz opcje: ";

		cin >> opcja;
		switch (opcja) {
		case 'd':
		case 'D':
			cout << "Podaj numer artykulu: ";
			cin >> numer_art;
			pom = head;
			while (pom && (j < numer_art)) {
				pom = pom->next;
				j++;
			}
			if (pom && (j == numer_art)) return numer_art;
			else {
				cout << "\n\tNIE MA TAKIEGO ARTYKULU.\nWcisnij dowolny przyisk aby wrocic do MENU...";
				system("PAUSE");
				return -1;
			}
			break;
		case 'N':
			///przechodzenie miedzy poprzednia a nastepna strona
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
			pom = head;
			for (i = 0; i < k; i++) {
				pom = pom->next;
			}
			max_i = i + ROZM_WYP_LIST;
			break;
		case 'P':
			k = max_i - (2 * ROZM_WYP_LIST);
			if (k < 0)k = 0;
			pom = head;
			for (i = 0; i < k; i++) {
				pom = pom->next;
			}
			max_i = i + ROZM_WYP_LIST;
			break;
		case 'w':
		case 'W':
			return -1;
			break;
		case 'S':
		case 's':
			i = 0;
			max_i = ROZM_WYP_LIST;
			quickSort();
			pom = head;
			break;
		default:
			cout << "\n\tNIE MA TAKIEJ OPCJI.\nWcisnij dowolny przycisk...";
			system("PAUSE");
			return -1;
			break;

		}
	}

}
///dzialanie na liscie artykulow
void ListaArtykulowWDziale::pushFront(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt) {
	Artykul* pom = new Artykul;
	pom->dzial = _dzial;
	pom->nazwaArtykulu = _nazwaArtykulu;
	pom->cena = _cena;
	pom->ilosc_szt = _ilosc_szt;
	pom->prev = nullptr;
	pom->next = head;
	head = pom;
	iloscArtWMagazynie++;
	if (pom->next) pom->next->prev = pom; /// zachowanie ciaglosci wskaznikow prev 
	else tail = pom; /// gdy bedzie jedynym artykulem
}

void ListaArtykulowWDziale::pushBack(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt) {
	Artykul* pom = new Artykul;
	pom->dzial = _dzial;
	pom->nazwaArtykulu = _nazwaArtykulu;
	pom->cena = _cena;
	pom->ilosc_szt = _ilosc_szt;
	pom->prev = tail;
	pom->next = nullptr;
	tail = pom;
	iloscArtWMagazynie++;
	if (pom->prev) pom->prev->next = pom; /// zachowanie ciaglosci wskaznikow next 
	else head = pom; /// gdy bedzie jedynym artykulem
}
///usuwanie artykulu z listy
void ListaArtykulowWDziale::removeArt(Artykul* _art) {
	iloscArtWMagazynie--;
	if (_art->prev) _art->prev->next = _art->next; ///poprzedni wskazuje na nastepny
	else head = _art->next;	/// nie ma poprzednika czyli pierwszy element
	if (_art->next) _art->next->prev = _art->prev; ///nastepny wskazuje na poprzeni
	else tail = _art->prev; /// nie ma nastepnika czyli ostatni element

	delete _art; /// zwalniamy pamiec
}

void ListaArtykulowWDziale::popFront() {
	if (head) removeArt(head);
}

void ListaArtykulowWDziale::popBack() {
	if (tail) removeArt(tail);
}
///sortowanie listy
void ListaArtykulowWDziale::quickSort() {
	if (iloscArtWMagazynie > 1) {
		pushFront("", "", 0., 0);	/// lewy wartownik 
		pushBack("", "", 0., 0);	/// prawy wartownik
		partitionList(head, tail);	/// dzielimy liste
		popFront();	/// usuwamy wartownika z lewej
		popBack();	/// usuwamy wartownika z prawej
	}
}
/// metoda pomocnicza do quickSort
void ListaArtykulowWDziale::partitionList(Artykul* _lArt, Artykul* _pArt) {///_lArt - head | _pArt - tail
	Artykul* pivot = _lArt->next;
	Artykul* pom_i = pivot->next;
	Artykul* pom_j;

	if (pivot->next != _pArt) {
		do {	///	szukanie mniejszego niz pivot
			pom_j = pom_i;
			pom_i = pom_i->next;
			if (pom_j->nazwaArtykulu < pivot->nazwaArtykulu) {
				pom_j->prev->next = pom_j->next;	/// wyciagamy znaleziony element
				pom_j->next->prev = pom_j->prev;	/// ^^^
				pom_j->next = pivot;	/// znaleziony element przed pivot
				pom_j->prev = pivot->prev;	/// zachowanie ciaglosci
				pivot->prev = pom_j;		/// ^^^
				pom_j->prev->next = pom_j;	/// ^^^
			}
		} while (pom_i != _pArt);
		if (_lArt->next != pivot) partitionList(_lArt, pivot);
		if (pivot->next != _pArt) partitionList(pivot, _pArt);
	}
}

bool ListaArtykulowWDziale::czy_lista_pusta() {
	if (head == nullptr) return 0;
	else return 1;
}
/// zapisywanie danych z listy artykulow do pliku
void ListaArtykulowWDziale::zapis_do_pliku() {
	Artykul* pom = new Artykul;
	pom = head;
	string linia;
	fstream plik_art;
	plik_art.open("artykuly.txt");
	while (pom != NULL) {
		plik_art << endl << pom->dzial << ' ' << pom->nazwaArtykulu << ' ' << pom->cena << ' ' << pom->ilosc_szt;
		pom = pom->next;
	}
	plik_art.close();
}
///wyszukiwanie towaru o podanej nazwie
void ListaArtykulowWDziale::szukaj_artykulu(string nazwa) {
	Artykul* pom = new Artykul;
	pom = head;
	while (pom != NULL && pom->nazwaArtykulu != nazwa) pom = pom->next;
	if (pom == NULL) cout << "Nie ma towaru o takiej nazwie\n";
	else cout << "\tNazwa artykulu: " << pom->nazwaArtykulu << "\n\tCena artykulu: " << pom->cena << "\n\tIlosc w magazynie [szt]: " << pom->ilosc_szt << endl;
}
/// zmiana ilosci artykulu - gdy bedzie np dostawa
bool ListaArtykulowWDziale::zmien_ilosc_art(string nazwa) {
	Artykul* pom = new Artykul;
	pom = head;
	int nowa_ilosc = 0;
	///przechodzenie do odpowiedniego artykulu
	while (pom != NULL && pom->nazwaArtykulu != nazwa) pom = pom->next;
	if (pom == NULL) return true;
	else {
		cout << "STARE DANE:" << endl;
		cout << "\tNazwa artykulu: " << pom->nazwaArtykulu << "\n\tCena artykulu: " << pom->cena << "\n\tIlosc w magazynie [szt]: " << pom->ilosc_szt << endl;
		cout << "\nPodaj ilosc artykulu w dostawie: ";
		cin >> nowa_ilosc;

		pom->ilosc_szt += nowa_ilosc;

		cout << "\nPomyslnie przyjeto towar na magazyn" << endl;
		system("Pause");
	}
	return false;
}
