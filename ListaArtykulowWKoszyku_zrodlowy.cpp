#include "ListaArtykulowWKoszyku.h"

ListaArtykulowWKoszyku::ListaArtykulowWKoszyku() {
	ilosc_art_na_liscie = 0;
	head_koszyk = nullptr;
	tail_koszyk = nullptr;
}

Artykul* ListaArtykulowWKoszyku::wyswietl_liste_art() {
	///inicjalizacja potrzebnych zmiennych
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


	///wielka petla - contaner
	while (opcja != 'w' && opcja != 'W') {
		system("cls");
		///graficzne przedstawienie
		cout << "=======================================================================================================================" << endl;
		cout << "------------------------------------------ LISTA - ARTYKULOW - W - KOSZYKU --------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;

		cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		/// wypisanie artykulow
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
		/// cd graficznego przedstawienia
		cout << "\n=======================================================================================================================\n";
		cout << "[P - poprzednia strona] [N - nastepna strona] [W - wyjdz] [D - dzialania na artykule]" << endl;
		cout << "Wybierz opcje: ";
		cin >> opcja;
		switch (opcja) {
		case 'd':
		case 'D':
			///jesli uzytkownik wybral "dzialanie na artykule"
			cout << "Podaj numer artykulu: ";
			cin >> numer_art;
			pom = head_koszyk;
			///petla dodawania do koszyka klienta
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
			/// przejscie do nastepnej strony wyswietlania artykulow
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
			/// przejscie do poprzedniej strony
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
			///wyjscie z listy artykulow
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

void ListaArtykulowWKoszyku::removeArt(Artykul* _art) {
	///usuwanie artykulu z koszyka
	ilosc_art_na_liscie--;
	if (_art->prev) _art->prev->next = _art->next; ///poprzedni wskazuje na nastepny
	else head_koszyk = _art->next;	/// nie ma poprzednika czyli pierwszy element
	if (_art->next) _art->next->prev = _art->prev; ///nastepny wskazuje na poprzeni
	else tail_koszyk = _art->prev; /// nie ma nastepnika czyli ostatni element

	delete _art; /// zwalniamy pamiec
}
