/* ======================================
Sekcja dokumentacji
Plik: main2025.c
Autor: Kamil Niemiec
Temat: Rozwi¹zanie zadañ æwiczenia nr 2.
======================================*/

/* ======================================
Sekcja dyrektyw preprocesora
======================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cw2.h"

int is_triangle(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 0;
	else if (a + b <= c)
		return 0;
	else if (a + c <= b)
		return 0;
	else if (c + b <= a)
		return 0;
	return 1;
}
int is_triangle_short(int a, int b, int c)
{
	if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	{
		return 1;
	}
	return 0;
}
int same_signs(int a, int b)

{
	if (a >= 0 && b >= 0)
		return 1;
	if (a < 0 && b < 0)
		return 1;
	return 0;

}
int same_signs_bitwise(int a, int b) 
{

	/*
	^ - XOR porównuje bity na tych samych pozycjach
	1- jeœli bity s¹ ró¿ne
	0 - jeœli bity s¹ takie same
	a = 5 => 1010
	b - 3 => 0011
	
	*/
	return (a ^ b) >= 0;
}
int test_same_signs()
{

	for (size_t i = 0; i < 10; i++)
	{
		int a = (rand() % 201) - 100;
		int b = (rand() % 201) - 100;
		// Stdlib - funcja losowania
		printf("%d %d: Taki sam zna: %d\n", a, b, same_signs(a, b));
	}
}
int div_3_or_5(int a)
{
	//Zadanie 4. Napisz funkcjê int div_3_or_5(int a), która sprawdza czy liczba a jest podzielna przez 3 lub 5.
	if (a % 3 == 0 || a % 5 == 0) { return 1; } // 1 jako True
	return 0; // 0 jako false
}
void test_div_3_or_5()
{
	int a;
	printf("Podaj liczbe aby sprawdzic czy jest podzielna przez 5\n");
	if (scanf_s("%d", &a) != 1) {
		printf("Blad odczytu liczby.\n");
		/* Wczytywanie nie powiod³o siê */
		return;
	}

	if (div_3_or_5(a)) 
	{
		printf("Liczba %d jest podzielna przez 3 lub 5\n", a);
	}
	else 
	{
		printf("Liczba %d nie jest podzielna przez 3 ani przez 5\n", a);
	}

	
}
void sum_avg_div_3_or_5()
{
	/*
	Zadanie 4a.
	Napisz funkcjê void sum_avg_div_3_or_5(), która czyta ze standardowego wejœcia n liczb (n podaje u¿ytkownik)
	i oblicza sumê oraz œredni¹ tych liczb, które s¹ podzielne przez 3 lub 5.
	W obliczeniach wykorzystaj funkcjê z zadania 4.
	*/
	unsigned int n;
	unsigned int a;
	unsigned sum = 0;
	float avg;
	int j = 0;
	printf("Ile liczb chcesz sprawdzic?: ");
	if (scanf_s("%d", &n) != 1) {
		printf("Blad odczytu liczby.\n");
		/* Wczytywanie nie powiod³o siê */
		return;
	}
;
	printf("Podaj %d liczb naturalnych:\n", n);
	for (int i = 0; i < n; i++)
	{
		if (scanf_s("%d", &a) != 1) {
			printf("Blad odczytu liczby.\n");
			return;
		}
		if (div_3_or_5(a))
		{
			sum += a;
			j++;
		}
	}
	if (j == 0) { avg = 0;}
	else { avg = (float)sum / j;}

	
	printf("Suma liczb podzielnych przez 3 lub 5 wynosi %d \n", sum);
	printf("Srednia liczb podzielnych przez 3 lub 5 wynosi %.4f \n", avg);
	



}
void zgadywanka()
{
	/*
	Zadanie 5. 
	Napisz funkcjê, która realizuje grê Zgadywanka.Gra polega na tym, 
	¿e komputer losuje liczbê, któr¹ u¿ytkownik próbuje odgadn¹æ.
	Komputer po ka¿dej próbie podaje informacjê "Za duza", 
	jeœli podana liczba jest wiêksza ni¿ ta wylosowana, 
	"Za malo" jeœli jest mniejsza, 
	"Zgadles" jeœli u¿ytkownik odgad³ wylosowan¹ liczbê.
	Dodatkowo funkcja powinna wypisywaæ liczbê prób u¿ytkownika.
	*/

	int a = (rand() % 100) + 1; // Losowanie liczby od 1 do 100
	int try = 0;
	int i = 1;
	printf("Sprobuj odgadnac liczbe z przedzialu od 1 do 100 ktora wylosowal komputer\n");

	while (a != try)
	{
		printf("Proba nr %d: ", i);
			scanf_s("%d", &try);
			if (try > a) { printf(" - Za duza\n"); }
			else if (try < a) { printf(" - Za mala\n"); }
			else { printf(" -  Zgadles\n"); }
			i++;
	}

}