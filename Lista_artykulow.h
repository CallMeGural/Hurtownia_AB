#pragma once
#include <iostream>
#include "Artykul.h"

using namespace std;

class Lista_artykulow {
	friend class Koszyk_klienta;
	Artykul art;
	Lista_artykulow* next;

	void wypisz(Lista_artykulow* head) {
		Lista_artykulow* supp = new Lista_artykulow;
		supp = head;
		while (supp != NULL) {
			cout << "Produkt " << art.nazwa << " znajdujacy sie w " << art.dzial << " w ilosci " << art.ilosc << endl;
			supp = supp->next;
		}
	}

	void usun(Artykul art, Lista_artykulow* head) {
		Lista_artykulow* supp = head;
		while (true) {
			if (head != NULL) {
				while (supp->next != NULL) {
					if (supp->art.nazwa == art.nazwa) {
						Lista_artykulow* deleted = supp->next;
						supp->next = deleted->next;
						free(deleted);
					}
					else {
						supp = supp->next;
					}
				}
				break;
			}
		}
	}

	void dodaj_artykul(Artykul art, Lista_artykulow*& head, int position) {
		Lista_artykulow* supp = new Lista_artykulow;
		supp = head;
		Lista_artykulow* newNode = new Lista_artykulow;
		newNode->art = art;

		int i = 0;
		if (head == NULL) {
			head = newNode;
		}
		else {
			while (true) {
				if (position == 0) {
					newNode->next = head;
					head = newNode;
					head->next = NULL;
					break;
				}
				else {
					while (supp->next != NULL && i != position) {
						supp = supp->next;
						i++;
					}
					newNode->next = supp->next;
					supp->next = newNode;
					break;
				}
			}
		}
	}
};
