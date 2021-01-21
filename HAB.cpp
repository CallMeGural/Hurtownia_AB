#include <iostream>
#include "Dzial.h"
#include "ListaArtykulowWDziale.h"
#include "Artykul.h"
#include "Menu.h"

using namespace std;

int main() {
	Dzial Nowy("Magazyn");
	Nowy.wczytaj_artykuly_z_pliku();
	main_menu(Nowy);
	Nowy.zapisz_artykuly_do_pliku();
	return 0;
}