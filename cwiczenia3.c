#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
//#include <locale.h> // bibioteka dziêki której mo¿na u¿ywaæ Polskich znaków konsoli; nale¿y w funkcji main dodaæ setlocale(LC_ALL, "Polish"); // ustwianie jêzyka polskie 

#include "cw2.h"
#include "cwiczenia3.h"


int sumofdigits(unsigned int a)
{
	/*===============================================================================
	Napisz funkcje int sumofdigits(unsigned int a), która zwraca sumê cyfr liczby a.
	=================================================================================*/
	int sum = 0;
	while (a > 0) 
	{
		sum += a % 10; // = sum +a % 10; 
		a /= 10; //= a / 10;
	}
	return sum;

	//Pobierzemy ostatni¹ cyfrê - reszta z dzielenia przez 10
	//Dodamy j¹ do obecnej sumy
	//Usuniemy ostatni¹ cyfrê - dzielenie ca³kowite przez 10

	//Input 102
	// 102 -> 2
	// Suma = 2
	//102 - > 0

	// 10-> 0
	// Suma = suma + 0
	// 10 -> 1

	// 1 -> 1
	// Suma = suma + 1
	// 1 -> 0

}
void test_zadanie1()
{
	//Zadeklaruj tablice zawieraj¹ca liczby {78, 34, 123, 678, 34, 567, 1023, 5869, 5, 435, 546, 666, 999}, a nastêpnie wypisz elementy tablicy oraz ich sumê cyfr
	unsigned int arr[] = { 78, 34, 123, 678, 34, 567, 1023, 5869, 5, 435, 546, 666, 999 };
	int size = sizeof(arr) / sizeof(arr[0]); //Obliczamy rozmiar tablicy dziel¹c ca³kowity rozmiar przez rozmiar pojedynczego elementu
	printf("============Zadanie 1============\n");
	for (int i = 0; i < size; i++) 
	{
		printf("Liczba: %d | Suma cyfr: %d\n", arr[i], sumofdigits(arr[i]));
	}
	printf("=================================\n\n");
}
void numbersbin111()
{
	//Napisz funkcje void numbersbin111(), która wypisze wszystkie liczby, które w zapisie binarnym maj¹ same jedynki (wykorzystaj operacje bitowe). 
	//Liczby, które w zapisie binarnym maj¹ same jedynki to: 1 (1), 3 (11), 7 (111), 15 (1111), 31 (11111), 63 (111111), 127 (1111111), 255 (11111111) itd.
	printf("============Zadanie 2============\n");
	unsigned int num = 0; //Pierwsza liczba, która w zapisie binarnym ma same zera
	for (int i = 0; i < 32; i++) //Dla 32 bitów
	{
		// num = 0000 Start
		// num = 0000 Po <<
		// num = 0001 Po |

		num = (num << 1) | 1; //Przesuwamy num w lewo o 1 bit i ustawiamy ostatni bit na 1
		printf("%u \n", num); //Wypisujemy aktualn¹ liczbê
	}
	printf("=================================\n\n");
}
int sentence(char* s)
{
/*
Potrzba <ctype.h> do funkcji isupper() - sprawdza czy znak jest du¿¹ liter¹
Napisz funkcjê int sentence(char* s), która zwraca liczbê du¿ych liter w zdaniu s. 
Napisz funkcjê test_ sentence() i przetestuj w niej dzia³anie funkcji zdanie: wczytaj zdanie za pomoc¹ funkcji gets_s, wypisz wynik funkcji zdanie.
*/
//char* s - wskaŸnik do pierwszego znaku w stringu (zdaniu)
	int count = 0; //Zmienna do zliczania du¿ych liter
	int i = 0; //Indeks do iteracji po znakach w stringu
	while (s[i] != '\0') //Iterujemy a¿ do koñca stringa (znak null)
	{
		if (isupper((unsigned char)s[i])) //Sprawdzamy czy aktualny znak jest du¿¹ liter¹
		{
			count++; //Jeœli tak, zwiêkszamy licznik
		}
		i++; //Przechodzimy do nastêpnego znaku
	}
	return count; //Zwracamy liczbê du¿ych liter

}
void test_sentence() 
{
	printf("============Zadanie 3============\n");
	char buffer[256]; //Bufor do przechowywania wczytanego zdania
	if (gets_s(buffer, (unsigned int) sizeof(buffer)) != NULL) //Wczytujemy zdanie z wejœcia
	{
		//sentence(buffer); //Wywo³ujemy funkcjê sentence i przechowujemy wynik
		printf("Liczba du¿ych liter: %d\n", sentence(buffer)); //Wypisujemy wynik
	}
	printf("=================================\n");
}

void bubble_sort(int arr[], int size)
{
	/*--------------------------------------Zadanie 4-----------------------------------------------------------
	Napisz funkcjê bubble_sort(int arr[], int size), która sortuje b¹belkowo tablicê elementów.
	W funkcji testuj¹cej wygeneruj 20 elementów typu int z zakresu (-30, 30) do tablicy i posortuj dane w tablicy.
	-----------------------------------------------------------------------------------------------------------*/


	int temp; //Zmienna pomocnicza do przechowywania tymczasowej wartoœci podczas sortowania
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1] )//Porównujemy aktualny element z nastêpnym
			{
				// Jeœli aktualny element jest wiêkszy, zamieniamy je miejscami
				temp = arr[j]; //Przechowujemy aktualny element w temp
				arr[j] = arr[j + 1]; //Przypisujemy nastêpny element na miejsce aktualnego
				arr[j + 1] = temp; //Przypisujemy temp (poprzedni aktualny) na miejsce nastêpnego
			}

		}

	}
	


}
void test_bubble_sort()
{
	#define size_  20 //Rozmiar tablicy
	int arr[size_]; //Tablica do przechowywania 20 elementów
	srand((unsigned int)time(NULL)); //Inicjalizujemy generator liczb losowych
	for (int i = 0; i < size_; i++)
	{
		arr[i] = rand() % 61 - 30; //Generujemy liczby z zakresu (-30, 30)
	}
	bubble_sort(arr, size_); //Sortujemy tablicê za pomoc¹ funkcji bubble_sort
	printf("Posortowana tablica: \n");
	for (int i = 0; i < size_; i++)
	{
		printf("%d ", arr[i]); //Wypisujemy posortowan¹ tablicê
	}

}
int count_occurrences(int arr[], int size, int x)
{
/*----------------------------------------------------------Zadanie 5-----------------------------------------------------------
Napisz funkcje count_occurrences(int arr[], int size, int x), która zwraca liczbê wyst¹pieñ zadanej liczby w tablicy.
Dopisz funkcje testuj¹ca, w której ma byæ zdefiniowana tablica 30 elementowa o wartoœciach:
18, 3, 5, 29, 3, 18, 6, 9, 32, 3, 9, 9, 9, 23, 3, 18, 21, 6, 7, 7, 1, 2, 6, 5, 4, 8, 9, 9, 1, 9.
Szukana liczba ma byæ podawana przez u¿ytkownika. Przyk³adowe wejœcie i wyjœcie: WEJŒCIE: 9 WYJŒCIE: Liczba 9 wystêpuje 7 razy.
--------------------------------------------------------------------------------------------------------------------------------*/
unsigned int k = 0;

for (int i = 0; i < size; i++)
{
	if (arr[i] == x)
	{
		k ++;
	}
	
}
return k;
}
void test_count_occurrences() // funkcja testuj¹ca do funkcji count_occurrences() 
{
	int x; // deklaruje zmienn¹ x typu int
	int arr[] = { 18, 3, 5, 29, 3, 18, 6, 9, 32, 3, 9, 9, 9, 23, 3, 18, 21, 6, 7, 7, 1, 2, 6, 5, 4, 8, 9, 9, 1, 9 }; // deklruje rablicê
	int size = sizeof(arr) / sizeof(arr[0]); // obliczam rozmiar tablicy arr
	char raz[] = "razy"; // definiuje zmienn¹ typu string (za pomoc¹ char nazwa[]), która przechowa s³owa "razy"
	printf("============Zadanie 5============\n"); // wyœwietlam na ekranie informacjê którego zadania dotyczy ta funkcja
	printf("Podaj liczbê x której liczbê wyst¹pieñ chcesz sprawdziæ w zadeklarownej tablicy: ");
		if (scanf_s(" %d", &x) == 1) // wczytuje liczbê od u¿ykownika, zapoisuje j¹ do zmiennej x poprzez &; Sprawdzam czy zosta³a wczytana liczba, jeœli tak wykonujê poni¿szy warunek
		{
			int k = count_occurrences(arr, size, x); // zapisuje do zmiennej k wynik dzia³¹nia funkcji count_occurrences()
			if (k == 1) //sprawdzam czy k jest równe 1
			{ 
				raz[3] = '\0'; // jeœli tak to nadpisuje wartoœc zmiennej raz[]
			}
			printf("Liczba %d wystepuje w tablicy %d %s.\n", x, k , raz);// Wyœwietlam na ekranie informacjê ile (k) razy w zbiorze arr[] wystêje dana liczba x
		}	
		
		else // Jeœli u¿ytkownik nie poda³ liczby zostanie wywo³ana funkcja else
		{
			printf("Musisz podaæ liczbê calkowit¹!\n"); // Informacja dla u¿ytkownika ¿e musi podaæ liczbê ca³kowit¹
			
		}
	printf("=================================\n");
}
int factorial(unsigned int n)
{
/*----------------------------------------------------------Zadanie 6-----------------------------------------------------------
						Napisz funkcje int factorial(unsigned int a), która oblicza silniê z a.
--------------------------------------------------------------------------------------------------------------------------------*/
	long int result = 1; //Zmienna do przechowywania wyniku silni
	for (unsigned int i = 1; i <= n; i++) //Iterujemy od 1 do n
	{
		result *= i; //Mno¿ymy wynik przez aktualn¹ wartoœæ i
	}
	return result; //Zwracamy obliczon¹ silniê
}
void test_factorial() 
{
	unsigned int n;  // definiuje zmienn¹ n
	printf("============Zadanie 6============\n"); // wyœwietlam na ekranie informacjê którego zadania dotyczy ta funkcja
	printf("Podaj liczbe n do obliczenia silni: "); // Proszê u¿ytkowanika o podanie liczby
	
	if (scanf_s(" %d", &n) == 1) // wczytuje liczbê od u¿ykownika, zapisuje j¹ do zmiennej x poprzez &; Sprawdzam czy zosta³a wczytana liczba, jeœli tak wykonujê poni¿szy warunek
	{
		printf("Wynik: %d silnia równa siê %d\n", n, factorial(n));// Wyœwietlam na ekranie informacjê o wyniki n!
	}

	else // Jeœli u¿ytkownik nie poda³ liczby zostanie wywo³ana funkcja else
	{
		printf("Musisz podaæ liczbê calkowit¹!\n"); // Informacja dla u¿ytkownika ¿e musi podaæ liczbê ca³kowit¹

	}
	printf("=================================\n");
}

int nwd_bez_rekurencji(int a, int b)
{
/*----------------------------------------------------------Zadanie 7-----------------------------------------------------------
		Napisz funkcjê rekurencyjn¹ int nwd(int a, int b), która oblicza najwiêkszy wspólny dzielnik liczb a i b.
--------------------------------------------------------------------------------------------------------------------------------*/
int temp; // zmienna tymczasowa do przechowywania wartoœci
if ((a == 0) || (b == 0))
{
	printf("B³¹d: Nie mo¿na dzieliæ przez zero!\nMusisz podaæ 2 liczby naturalne wiêksze od zera!\n");
	return 0;
}
while (a % b)
{
	
	temp = a % b;
	a = b;
	b = temp;
}
return abs(b); // zrwacamy wartoœæ bezwlgêdn¹ wspólnego dzielnika

}
int nwd(int a, int b) // rekurencja
{
	a = abs(a); // zamieniam a na dodatnie za paomoc¹ abs - modu³ z a
	b = abs(b);// zamieniam b na dodatnie za paomoc¹ abs - modu³ z b
	if (b == 0) // jeœli b jest równe zero to NWD to a
		return a;// zwracam a
	return nwd(b, a % b); // Jeœli b jest ró¿ne od zera to ponownie wywo³uje funkcjê  nwd
}
void test_nwd() 
{
	unsigned int a, b;  // definiuje zmienne a i b
	printf("============Zadanie 7============\n"); // wyœwietlam na ekranie informacjê którego zadania dotyczy ta funkcja
	printf("Podaj liczby naturalne a i b do obliczenia NWD: "); // Proszê u¿ytkowanika o podanie liczby

	if (scanf_s(" %d %d", &a, &b) == 2) // wczytuje liczbê od u¿ykownika, zapoisuje j¹ do zmiennej x poprzez &; Sprawdzam czy zosta³a wczytana liczba, jeœli tak wykonujê poni¿szy warunek
	{
		
		printf("Najwiêkszy wspólny dzielnik liczb: %d i %d to %d\n", a, b, nwd(a, b));// Wyœwietlam na ekranie informacjê o NWD a i b
	
	}

	else // Jeœli u¿ytkownik nie poda³ liczby zostanie wywo³ana funkcja else
	{
		printf("Musisz podaæ 2 liczby naturalne oddzielone spacj¹! \n"); // Informacja dla u¿ytkownika ¿e musi podaæ liczbê ca³kowit¹

	}
	printf("=================================\n");
}
void nwd_test()
{
/*----------------------------------------------------------Zadanie 8-----------------------------------------------------------
		Napisz funkcjê void nwd_test(), która najpierw losuje liczbê a z przedzia³u[-50, 50],
	a nastêpnie w pêtli losuje n(n podaje u¿ytkownik) liczb(zmienna b), równie¿ z przedzia³u[-50, 50] 
						i wypisuje najwiêkszy wspólny dzielnik par liczb(a, b).
--------------------------------------------------------------------------------------------------------------------------------*/
	unsigned int n; //rozmiar tablicy podany przez u¿ytkownika
	srand((unsigned int)time(NULL)); //Inicjalizujemy generator liczb losowych
	int a = rand() % 101 - 50; //Generuje liczbe a z zakresu [-50, 50]

	printf("============Zadanie 8============\n"); // wyœwietlam na ekranie informacjê którego zadania dotyczy ta funkcja
	printf("Podaj ile razy wywo³aæ pêtle losuj¹c¹ liczby z zakresu [-50;50] do obliczenia NWD: "); // Proszê u¿ytkowanika o podanie liczby
	if (scanf_s(" %d", &n) == 1) // wczytuje liczbê od u¿ykownika, zapoisuje j¹ do zmiennej x poprzez &; Sprawdzam czy zosta³a wczytana liczba, jeœli tak wykonujê poni¿szy warunek
	{
		for (int i = 0; i < n; i++)
		{
			int b = rand() % 101 - 50; //Generuje liczbe b z zakresu [-50, 50]

			if (nwd(a, b) != NULL)

			{
				printf("Najwiêkszy wspólny dzielnik liczb: %d i %d to %d\n", a, b, nwd(a, b));// Wyœwietlam na ekranie informacjê o NWD a i b
			}
		}
	}

	else // Jeœli u¿ytkownik nie poda³ liczby zostanie wywo³ana funkcja else
	{
		printf("Musisz podaæ liczbe naturaln¹!\n"); // Informacja dla u¿ytkownika ¿e musi podaæ liczbê ca³kowit¹

	}
	printf("=================================\n");
	
}

double mc_pi(unsigned int n) 
{
/*----------------------------------------------------------Zadanie 9-----------------------------------------------------------
		Napisz funkcjê double mc_pi(unsigned int n), która oblicza liczbê pi metod¹ Monte Carlo.
				Nale¿y wylosowaæ n punktów (x,y) o wspó³rzêdnych z przedzia³u [0;1].
		Liczba pi = 4m/n, gdzie m to liczba punktów, które mieszcz¹ siê w kole o promieniu 1.


 METODA MONTE CARLO – OBLICZANIE LICZBY PI
1. KONCEPCJA:
	- Losujemy punkty (x, y) w kwadracie o boku 1.
	- Sprawdzamy, ile z nich wpada do æwiartki ko³a o promieniu 1.
	- Wzór: PI oko³o 4 * (liczba_punktów_w_kole / ca³kowita_liczba_punktów)

2. ALGORYTM (KROK PO KROKU):
	a. Ustal liczbê prób (np. N = 100 000).
	b. Wygeneruj dwie losowe liczby z zakresu [0, 1] dla x i y.
	c. Oblicz odleg³oœæ od œrodka (0,0): d = x^2 + y^2.
	d. Jeœli d <= 1, punkt jest w kole – dodaj 1 do licznika "trafienia".
	e. Po zakoñczeniu pêtli pomnó¿ (trafienia / N) przez 4.

--------------------------------------------------------------------------------------------------------------------------------*/
	//unsigned int n; //liczba puntktów które bêd¹ losowane podane przez u¿ytkownika
	srand((unsigned int)time(NULL)); //Inicjalizujemy generator liczb losowych

	unsigned int m = 0; // inicjuje zmienn¹ m do zlicania iloœci punktów które znajduj¹ siê w æwiatrce ko³a o promieniu 1
	for (int i = 0; i < n; i++) // pêtla for po n punktach
	{
		//double x = (rand() % 1001) / 1000.0; // losuje punkt x zakrseu [0;1] - sposób w³asny
		///double y = (rand() % 1001) / 1000.0;// losuje punkt y zakrseu [0;1] - sposób w³asny
		double x = (double)rand() / RAND_MAX; // losuje punkt y zakrseu [0;1] - sposób z wyk³adu
		double y = (double)rand() / RAND_MAX; // losuje punkt y zakrseu [0;1] - sposób z wyk³adu
		double d = x*x + y*y; // obliczam odleg³oœæ d o œrodka uk³adu wspó³rzêdnych (0,0)
		
			if (d <= 1)// jeœli punkt (x,y) znajduje siê w odleg³oœci d nie dalszej ni¿ 1 to zwiêkszam licznik m
			{
				m++; // zwiêkszam licznik trafieñ w æwiartkê ko³a o promieniu 1
			}
			//printf("x = %.8f, y = %.8f, d = %.8f, m = %d, m/n = %.8f\n", x, y, d, m, m/n); // funkcja pomocnicza do sprawdzenia kolejnych liczb obliczancyh w pêtlo for
	}
	double pi =4.0 * m / n; // obliczam pi jako liczb¹ trafieñ w æwiartkê ko³o przez liczbê wrzystkich wykonanych prób i ca³oœc mno¿ê razy 4(pe³ne ko³o)
	return pi;// zwracam wartroœæ pi


}

void test_mc_pi()// funkcja testuj¹ca do funkcji mc_pi()
{
	unsigned int n;
	printf("\t============Zadanie 9============\n"); // wyœwietlam na ekranie informacjê którego zadania dotyczy ta funkcja
	printf("Podaj dla ilu losowych (x,y) wykonac obiczenia: "); // Proszê u¿ytkowanika o podanie liczby
	if ((scanf_s(" %d", &n) == 1) && (n >= 0) ) // wczytuje liczbê od u¿ykownika, zapoisuje j¹ do zmiennej x poprzez &; Sprawdzam czy zosta³a wczytana liczba, jeœli tak wykonujê poni¿szy warunek
	{
		printf("Liczba pi obliczona Metod¹ Monte Carlo dla %d punktów wynosi %f\n", n, mc_pi(n));
	}

	else // Jeœli u¿ytkownik nie poda³ liczby zostanie wywo³ana funkcja else
	{
		printf("Musisz podaæ liczbe naturaln¹!\n"); // Informacja dla u¿ytkownika ¿e musi podaæ liczbê ca³kowit¹

	}
	printf("\t=================================\n");// zamykam klamr¹ wyœwietlanie na ekranie informacjê którego zadania dotyczy ta funkcja

}

void open_cw3() // Dodatkowowa funkcja która pozwala przestestowac wszystkie zadania poprzez podanie ich numeru
{
	
	int numer_cw;
	char TN = 'T';


	while (TN == 'T' || TN == 't')
	{
		printf("Podaj numer cwiczenia : ");
		scanf_s("%d", &numer_cw);
		switch (numer_cw)
		{
		case 1:
			test_zadanie1();
			break;
		case 2:
			numbersbin111();
			break;
		case 3:
			test_sentence();
			break;
		case 4:
			test_bubble_sort();
			break;
		case 5:
			test_count_occurrences();
			break;
		case 6:
			test_factorial();
			break;
		case 7:
			test_nwd();
			break;
		case 8:
			nwd_test();
			break;
		case 9:
			test_mc_pi();
			break;
		default:
			printf("Nieprawidlowy numer cwiczenia!\n");
			break;
		}

		printf("Czy chcesz kontynuowaæ? T/N\n");
		scanf_s(" %c", &TN, (unsigned int)sizeof(TN));
	}
}