#include "Film.h"
#include<iostream>
#include<string>

using namespace std;

Film::Film() {
	
	strcpy(tytul, ""); // uzupe³niamy konstruktor domyœlny o tytu³
	wybrane_miejsce = 0; // reszta bez zmian
	int i = 0;

	for (i = i; i < ilosc_miejsc; i++)
	{
		wszystkie_miejsca[i] = Miejsce("", "", i + 1, false);
	}
}