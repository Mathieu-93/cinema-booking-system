// cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Film.h"
#include "Miejsce.h"
#include "Kino.h"


using namespace std;

void wyswietl_menu_glowne() // funkcja bez argumentów
{
	cout << "System rezerwacji miejsc - Singlekino.pl" << endl << endl; // tworzymy menu
	cout << "Wybierz opcje:" << endl << endl;
	cout << "1 - Dodaj rezerwacje" << endl;
	cout << "2 - Usun rezerwacje" << endl;
	cout << "3 - Sprawdz miejsce" << endl;
	cout << "4 - Wyswietl wszystkie rezerwacje" << endl;
	cout << "5 - Wyswietl wolne miejsca" << endl;
	cout << "6 - Wyswietl zarezerwowane miejsca" << endl;
	cout << "7 - Zamknij system" << endl;
	cout << "8 - wyswietl miejsca 2" << endl;
}

void wyswietl_menu()
{
	cout << "System rezerwacji miejsc - KINOKOSMOS" << endl << endl;
	cout << "1 - Zarezerwuj seans" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "2 - Anuluj rezerwacje" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "3 - Sprawdz seans" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "4 - Panel Admina" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "5 - Wyjdz z systemu" << endl;
}

void wyswietl_menu_admin() {
	cout << "Panel admina - KINOKOSMOS" << endl << endl;
	cout << "1 - Dodaj film" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "2 - Sprawdz rezerwacje" << endl;
	cout << endl;
	cout << "_______________________" << endl;
	cout << endl;
	cout << "3 - Wyjdz z panelu admina" << endl;
}
void czekaj_na_klawisz()
{
	cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
	getchar();
}


int main()
{

	Kino kino;
	Film film;
	char znak, znak2;
	string nazwa_filmu;
	char decyzja;

	wyswietl_menu();

	cin >> znak; // program pobiera znak

	while (znak != '5')
	{
		switch (znak)
		{
		case '1':
			kino.dodaj_rezerwacje();
			czekaj_na_klawisz();
			break;
		case '2':
			kino.anuluj_rezerwacje();
			czekaj_na_klawisz();
			break;
		case '3':
			kino.sprawdz_miejsce();
			czekaj_na_klawisz();
			break;
		case '4':
		{
			wyswietl_menu_admin();
			cin >> znak2;
			while (znak2 != '3')
			{
				switch (znak2)
				{
				case '1':

						cout << "Podaj tytuł filmu: ";
						cin >> nazwa_filmu;
						kino.dodaj_film(nazwa_filmu);
						cout << endl;
						while(1)
						{
						cout << "Czy chcesz dodac kolejny film?" << endl;
						cout << "1 - tak" << endl;
						cout << "2 - nie" << endl;
						cin >> decyzja;
						if (decyzja == '2')
							break;
						else if (decyzja != '1')
						{
							cout << "Podano zly znak!" << endl;
						}
					}
					break;
				case '2':

					break;
				}
				wyswietl_menu_admin();
				cin >> znak2;
			}
		}
		case '5':

			break;
		}
		wyswietl_menu();
		cin >> znak;// jeszcze raz dokonujemy wyboru

	}

		return 0;
	}