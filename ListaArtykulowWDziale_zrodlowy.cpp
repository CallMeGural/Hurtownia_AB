#include "ListaArtykulowWDziale.h"
#include <fstream>

ListaArtykulowWDziale::ListaArtykulowWDziale() {
	iloscArtWMagazynie = 0;
	head = nullptr;
	tail = nullptr;
}

ListaArtykulowWDziale::~ListaArtykulowWDziale() {
	while (iloscArtWMagazynie) popFront();
}

void ListaArtykulowWDziale::wyswietl_liste_art() {
	int i = 0;
	Artykul* pom = head;

	system("cls");
	cout << "=======================================================================================================================" << endl;
	cout << "------------------------------------------- LISTA - ARTYKULOW - W - DZIALE --------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "=======================================================================================================================" << endl;

	cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	
	while (pom) {
		cout << setw(5) << i << ".";
		pom->wyswietl_artykul_z_listy();
		i++;
		pom = pom->next;
	}
	cout << "\n=======================================================================================================================\n\n";
}

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

void ListaArtykulowWDziale::quickSort() {
	if (iloscArtWMagazynie > 1) {
		pushFront("", "", 0., 0);	/// lewy wartownik 
		pushBack("", "", 0., 0);	/// prawy wartownik
		partitionList(head, tail);	/// dzielimy liste
		popFront();	/// usuwamy wartownika z lewej
		popBack();	/// usuwamy wartownika z prawej
	}
}

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

void ListaArtykulowWDziale::zapis_do_pliku() {
	Artykul *pom = new Artykul;
	pom = head;
	string linia;
	fstream plik_art;
	plik_art.open("artykuly.txt");
	while (pom!=NULL) {
		plik_art <<pom->dzial<<' '<< pom->nazwaArtykulu << ' ' << pom->cena << ' ' << pom->ilosc_szt << endl;
		pom = pom->next;
	}
	plik_art.close();
}

void ListaArtykulowWDziale::szukaj_artykulu(string nazwa) {
	Artykul* pom = new Artykul;
	pom = head;
	while (pom != NULL && pom->nazwaArtykulu != nazwa) pom = pom->next;
	if (pom == NULL) cout << "Nie ma towaru o takiej nazwie\n";
	else cout << "\tNazwa artykulu: " << pom->nazwaArtykulu << "\n\tCena artykulu: " << pom->cena << "\n\tIlosc w magazynie [szt]: " << pom->ilosc_szt << endl;
}
