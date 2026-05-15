
/*===================================
* Author: Kamil Niemiec
* Uczelnia: Akademia Górniczo-Hutnicza im. Stanis³awa Staszica w Krakowie
* Nr albumu: 434510
* Kierunek: Informatyka i Ekonmoetra
* Rok studiów: 1
* Semestr: 2
* Przedmiot: Programowanie komputerów
* Data wykonania: 2026-03-15
* Description: Program w jêzyku C na zaliczenie Przedmiotu Programowanie komputerów
========================== */


/* ======================================
Sekcja dyrektyw preprocesora
======================================*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


#include <stdio.h>
#include "Projekt_23_Niemiec_Kamil_434510.h"
#include <windows.h>

/* ======================================
Funkcja main
======================================*/
int main() 
{
	enable_ansi();

	srand((unsigned int)time(NULL));
	start_game();
	return 0;
	
}