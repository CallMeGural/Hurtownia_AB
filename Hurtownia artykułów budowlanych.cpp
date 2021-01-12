#include <iostream>
#include <conio.h>
#include "Dzial.h"
#include "Magazynier.h"
#include "Kierownik.h"
#include "Artykul.h"
using namespace std;

int main()
{
    cout << "Podaj kim jestes:\n1. Kierownik\t\t[m/M]\n2. Magazynier\t\t[w/W]\n3. Klient\t\t[c/C]\n";
    int kim_jestes = _getch();
    int co_robie;
    bool petla = 0;
    if (kim_jestes == 'm' || kim_jestes == 'M') {
        Kierownik k;
        while (!petla) {
            cout << "Co chcesz zrobic?\n1. Dodaj artykul do magazynu.\n2. Dodaj dzial.\n3. Usun dzial.\n4. Wyjdz.\nPodaj numer: ";
            cin >> co_robie;
            switch (co_robie) {
            case 1: k.dodaj_artykul(); break;
            //case 2: k.dodaj_dzial();
            //case 3: k.usun_dzial();
            case 4: petla = 1; break;
            }
        }
    }
    else if (kim_jestes == 'w' || kim_jestes == 'W') {
        Magazynier m;
        while (!petla) {
            cout << "Co chcesz zrobic?\n1. Wyswietl informacje o artykule.\n2. Wyswietl reklamacje.\n3. Wyjdz.\nPodaj numer: ";
            cin >> co_robie;
            switch (co_robie) {
            case 1: m.wyswietl_info_artykul(); break;
            case 2: m.proces_reklamacyjny(); break;
            case 3: petla = 1; break;
            }
        }
    }
    else if (kim_jestes == 'c' || kim_jestes == 'C') {
        Klient k;
        while (!petla) {
            cout << "Co chcesz zrobic?\n1. Dokonaj zakupu.\n2. Wypozycz sprzet.\n3. Zglos reklamacje.\n4. Wyjdz.\nPodaj numer: ";
            cin >> co_robie;
            switch (co_robie) {
            case 1: k.kupuj(); break;
            //case 2: k.wypozycz(); break;
            case 3: k.zglos_reklamacje();
            case 4: petla = 1; break;
            }
        }
    }
    return 0;
}
