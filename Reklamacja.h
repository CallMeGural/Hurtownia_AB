#include <iostream>
#include "Artykul.h"

using namespace std;

class Reklamacja {
protected:
	friend class Klient;
	Artykul art;
public:
	Reklamacja(Artykul a) {
		art = a;
	}
	void zwrot_pieniedzy() {
		cout << "\nWybrano opcje zwrotu pieniedzy";
		cout << "\nZwrocono pieniedze!!!\n";
	}
	void wymiana() {
		cout << "\nDokonuje sie wymiana!";
		art.~Artykul();
		cout << "\nWymiana dokonana!\n";
	}
	void odrzucenie() {
		cout << "\nOdrzucono wniosek o reklamacje!\n";
	}
};