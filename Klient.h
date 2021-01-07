#include <iostream>
#include "Artykul.h"
#include "Uzytkownik.h"
#include "Reklamacja.h"
#include "Zakup.h"
#include "Wypozyczenie.h"

using namespace std;

class Klient : public Uzytkownik {
private:
	char[] nr_konta;

protected:
	unsigned short int id_klienta;

public:
	Koszyk_klienta koszyk_klienta;
	Reklamacja reklamacja;
	Wypozyczenie wypozycz;

	virtual void wyswietl_dane_klienta() {
		cout << "\nImie i nazwisko klienta:\n" << Uzytkownik::imie << " " << Uzytkownik::nazwisko << "\nNumer ID klienta:\n" << id_klienta << endl;
	}
	void zglos_reklamacje() {
		cout << "Dla jakiego artykulu chcesz zlozyc formularz by dokonac reklamacji?\n";
		Artykul art;
		reklamacja.art = art;
	}
	void kupuj() {
		Zakup kupno(koszyk_klienta);
		kupno.dodaj_art_do_koszyka();
	}
	void wypozycz() {
		wypozycz.dodaj_do_koszyka();
		wypozycz.data_wypozyczenia = time;
		wypozycz.data_zdania = wypozycz.data_wypozyczenia + wypozycz.liczba_dni;
		wypozycz.koszt_wypozyczenia = wypozycz.art.cena * 0.1;
	}
};