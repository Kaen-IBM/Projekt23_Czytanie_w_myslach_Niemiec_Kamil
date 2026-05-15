#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#include "cw2.h"
#include "cwiczenia3.h"
#include "cwiczenia4.h"
/**
 * allocate_matrix
 * ----------------
 * Alokuje dynamicznie macierz typu `int` o wymiarach n x m.
 *
 * Parametry:
 *   n - liczba wierszy (liczba wskazników do alokowania)
 *   m - liczba kolumn w ka¿dym wierszu (liczba elementów typu int w ka¿dym wierszu)
 *
 * Zwraca:
 *   wskaŸnik typu `int**` wskazuj¹cy na tablicê wskaŸników do wierszy
 *   (ka¿dy wiersz jest oddzielnie zaalokowan¹ tablic¹ `int`),
 *   lub `NULL` gdy alokacja pamiêci siê nie powiod³a.
 *
 * W³aœciwoœci i uwagi:
 * - Funkcja alokuje najpierw tablicê `n` wskaŸników, a nastêpnie dla ka¿dego
 *   wiersza alokuje pamiêæ na `m` elementów typu `int`.
 * - W przypadku niepowodzenia alokacji dla któregoœ wiersza funkcja zwalnia
 *   ju¿ zaalokowane wiersze oraz tablicê wskaŸników i zwraca `NULL`.
 * - Zwrócona tablica i wiersze musz¹ byæ zwolnione przez wywo³anie
 *   `free_matrix(result, n)` (lub równowa¿nej funkcji), aby unikn¹æ wycieków pamiêci.
 * - Funkcja nie sprawdza wartoœci `n` i `m` (np. czy s¹ > 0). Zaleca siê, aby
 *   wywo³uj¹cy walidowa³ te parametry przed wywo³aniem.
 * - Rozmiar alokacji u¿ywa `sizeof(*a)` i `sizeof(**a)` co zapewnia poprawnoœæ
 *   nawet gdy typ zmieni siê w przysz³oœci.
 */
int** allocate_matrix(int n, int m) 
{
    int** a = malloc(n * sizeof(*a));
    if (a == NULL) { return NULL; }
    for (int i = 0; i < n; ++i) {
        a[i] = malloc(m * sizeof(**a));
        if (a[i] == NULL) {
            for (int j = 0; j < i; ++j) free(a[j]);
            free(a);
            return NULL;
        }
    }
    return a;
}
/**
 * free_matrix
 * -----------
 * Zwalnia pamiêæ zaalokowan¹ przez `allocate_matrix`.
 *
 * Parametry:
 *   a - wskaŸnik zwrócony przez `allocate_matrix`
 *   n - liczba wierszy przekazana przy alokacji
 *
 * Dzia³anie:
 * - Zwalnia ka¿dy wiersz (`a[i]`) a nastêpnie sam¹ tablicê wskaŸników `a`.
 *
 * Uwagi bezpieczeñstwa:
 * - Funkcja zak³ada, ¿e `a` wskazuje na poprawnie zaalokowan¹ tablicê wskaŸników
 *   o d³ugoœci `n`. Wywo³anie z `a == NULL` spowoduje niezdefiniowane zachowanie.
 */
void free_matrix(int** a, int n) 
{
    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
}
/**
 * fill_matrix
 * -----------
 * Wype³nia macierz losowymi liczbami ca³kowitymi z zakresu [start, end].
 *
 * Parametry:
 *   a     - wskaŸnik na macierz (tablica wskaŸników do wierszy)
 *   n     - liczba wierszy
 *   m     - liczba kolumn
 *   start - dolna granica (w³¹cznie)
 *   end   - górna granica (w³¹cznie)
 *
 * Dzia³anie:
 * - Dla ka¿dego elementu `a[i][j]` przypisuje wartoœæ obliczon¹ jako:
 *     rand() % (end - start + 1) + start
 *
 * Uwagi:
 * - Zak³ada, ¿e `end >= start`. Jeœli `end < start` wynik jest nieokreœlony.
 * - Funkcja u¿ywa `rand()` — zaleca siê wywo³anie `srand()` (np. `srand(time(NULL))`)
 *   raz przed pierwszym wywo³aniem, aby uzyskaæ ró¿ne ci¹gi losowe.
 * - Funkcja nie sprawdza `a == NULL`; wywo³anie z nieprawid³owym wskaŸnikiem
 *   spowoduje niezdefiniowane zachowanie.
 * - Z³o¿onoœæ czasowa: O(n * m).
 */
void fill_matrix(int** a, int n, int m, int start, int end) 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rand() % (end - start + 1) + start;
        }
    }
}
/**
 * print_matrix
 * ------------
 * Wypisuje macierz na standardowe wyjœcie w formacie kolumnowym.
 *
 * Parametry:
 *   a - wskaŸnik na macierz (tablica wskaŸników do wierszy)
 *   n - liczba wierszy
 *   m - liczba kolumn
 *
 * Dzia³anie:
 * - Ka¿dy element wypisywany jest z szerokoœci¹ 4 znaków (u¿ycie "%4d").
 * - Po ka¿dym wierszu wypisywany jest znak nowej linii.
 *
 * Uwagi:
 * - Funkcja nie sprawdza `a == NULL`; wywo³anie z nieprawid³owym wskaŸnikiem
 *   spowoduje niezdefiniowane zachowanie.
 */
void print_matrix(int** a, int n, int m) 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
//mallolc - rezerwujej pamiêæ , karloc, calloc, realloc - relokuje pamiec, freee!!! przeczytaæ
// Na kolokwium trzba znaæ print i fill

void draw_chess_board()
{
    /* ---------------------------------------------------Zadanie 1--------------------------------------------------------------
         Napisz funkcjê draw_chess_board() który wype³nia tablicê 10x10 jedynkami i zerami jak w szachownicy. 
   ------------------------------------------------------------------------------------------------------------------------------*/
    int board[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
			board[i][j] = (i + j) % 2; // 0 dla bia³ych pól, 1 dla czarnych pól
            printf("%d ", board[i][j]);
        }
		printf("\n");
    }
}
int suma_przek¹tnych(int** a, int n) 
{
    /* ---------------------------------------------------Zadanie 4--------------------------------------------------------------
    Napisz funkcjê int suma_przekatnych(int** a, int n), która zwraca sumê elementów le¿¹cych na dwóch g³ównych przek¹tnych macierzy a.
    Napisz funkcjê test_sums() i przetestuj w niej dzia³anie funkcji suma_przekatnych(): 
    zaalokuj macierz za pomoc¹ funkcji allocate_matrix(), 
    wygeneruj dane w macierzy za pomoc¹ funkcji fill_matrix(), wypisz macierz za pomoc¹ funkcji print_matrix(), 
    wywo³aj funkcjê suma_przekatnych() i wypisz wynik, zwolnij pamiêæ za pomoc¹ funkcji free_matrix().
    ------------------------------------------------------------------------------------------------------------------------------*/
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
       sum += a[i][i]; // Suma przek¹tnej g³ównej
       sum += a[i][n - 1 - i]; // Suma przek¹tnej pobocznej
    }
    if (n % 2 == 1)
    {
        int mid = n / 2; // Indeks œrodkowego elementu
        sum -= a[mid][mid]; // Jeœli macierz ma nieparzysty rozmiar, odejmujemy œrodkowy element, który zosta³ dodany dwukrotnie
    }
    return sum;
}
void test_sums() // funkcja testuj¹ca do funkcji przek¹tnych(int** a, int n) 
{
    int n = 5; // Rozmiar macierzy
    int** matrix = allocate_matrix(n, n); // Alokujemy macierz
   
    fill_matrix(matrix, n, n, 1, 10); // Wype³niamy macierz losowymi liczbami z zakresu 1-10
    printf("Macierz:\n");
    print_matrix(matrix, n, n); // Wypisujemy macierz

    int sum = suma_przek¹tnych(matrix, n); // Obliczamy sumê przek¹tnych
    printf("Suma przek¹tnych: %d\n", sum); // Wypisujemy wynik
    free_matrix(matrix, n); // Zwolniamy pamiêæ

} //DOKONÆZYÆ
//ÆWIECZENIA 2,3 ITD. ALE BEZ NR 8

//ZADANIE 2
// a bêdzie "tablic¹"
// p

int min_max_row(int* a, int n, int* p_min, int* p_max )
{
    /*---------------------------------------------------Zadanie 2--------------------------------------------------------------
   Napisz funkcjê int min_max_row(int* a, int n, ???), która zwraca najmniejszy i najwiêkszy element w tablicy jednowymiarowej a.
   W miejsce pytajników wstaw odpowiednie parametry.
   -------------------------------------------------------------------------------------------------------------------------------*/
    *p_max = a[0];
    *p_min = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > *p_max) { *p_max = a[i]; }
            if (a[i] < *p_min) { *p_min = a[i]; }
        }
        return 0;
   // Print("Najwiekza liczba w tablicy to: %d\n", max)
    //Print("Najmniejsza liczba w tablicy to: %d\n", max)
   
}
//Zadanie 3
void min_max_tab_2D(int** a, int n, int m)
{
    /*---------------------------------------------------Zadanie 3--------------------------------------------------------------
    Napisz funkcjê void min_max_tab_2D(int** a, int n, int m),
    która wypisuje najwiêkszy element w ka¿dym wierszu macierzy a. Wykorzystaj funkcjê z poprzedniego zadania.
    ------------------------------------------------------------------------------------------------------------------------------- */
    int min_val, max_val;
        for (int i = 0; i < n; i++)
        {
            min_max_row(a[i], m, &min_val, &max_val);
            printf("Wiersz %d Max: %2d (Min: %2d)\n", i, max_val, min_val);
        }

}
void test_min_max_tab_2D()
{
    /* ---------------------------------------------------Zadanie 3 ci¹g dalszy--------------------------------------------------
    Napisz funkcjê test_min_max_tab_2D() i przetestuj w niej dzia³anie funkcji maxrows(): zaalokuj macierz za pomoc¹ funkcji allocate_matrix(), 
    wygeneruj dane w macierzy za pomoc¹ funkcji fill_matrix(),
    wypisz macierz za pomoc¹ funkcji print_matrix(), wywo³aj funkcjê maxrows(), zwolnij pamiêæ za pomoc¹ funkcji free_matrix().
    -------------------------------------------------------------------------------------------------------------------------------*/
    int n = 5; // Rozmiar macierzy
    int** matrix = allocate_matrix(n, n); // Alokujemy macierz

    fill_matrix(matrix, n, n, 1, 10); // Wype³niamy macierz losowymi liczbami z zakresu 1-10
    printf("Macierz:\n");
    print_matrix(matrix, n, n); // Wypisujemy macierz

    min_max_tab_2D(matrix, n, n);
  

    free_matrix(matrix, n); // Zwolniamy pamiêæ
}

void max_nwd(int** a, int n, int m)
{
    /*---------------------------------------------------Zadanie 5--------------------------------------------------------------
    Napisz funkcje max_nwd(int **a, int n, int m), która znajduje w tablicy dwuwymiarowej elementy,
    które maj¹ najwiêkszy najwiêkszy wspólny podzielnik. Przetestuj na wygenerowanej tablicy dwuwymiarowej.
    ------------------------------------------------------------------------------------------------------------------------------- */
    int val1 = a[0][0];
    int val2 = a[n-1][m-1];
    int NWD = nwd(val1, val2);//funkcja  z æwiczenia nr 3 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if ((i != k) || (j != l))
                    {
                        int temp = nwd(a[i][j], a[k][l]);
                        if (temp > NWD)
                        {
                            NWD = temp;
                            val1 = a[i][j];
                            val2 = a[k][l];
                        }
                    }
                }
            }
        }
    }
    printf("Elementy %d, %d maj¹ NWD równy %d\n", val1, val2, nwd(val1, val2));
   // return { val1, val2, nwd(val1, val2) };
}

void test_max_nwd()
{
    int n = 10; // Rozmiar macierzy
    int** matrix = allocate_matrix(n, n); // Alokujemy macierz

    fill_matrix(matrix, n, n, 1, 150); // Wype³niamy macierz losowymi liczbami z zakresu 1 - 150
    printf("Macierz:\n");
    print_matrix(matrix, n, n); // Wypisujemy macierz

    //int wynik = max_nwd(matrix, n, n);
    //printf("Elementy %d, %d maj¹ NWD równy %d", wynik[0], wynik[1], wynik[2]);
    max_nwd(matrix, n, n);
    free_matrix(matrix, n); // Zwolniamy pamiêæ

}

/*--------------------------------------------------- Zadanie 6 --------------------------------------------------------------
   Napisz funkcjê int compare(const void* a, const void* b), która porównuje dwie wartoœci typu int. 
   Nastêpnie napisz funkcjê void sort_quick(), która sortuje tablicê jednowymiarow¹ metod¹ quicksort. 
   Nastêpnie napisz funkcjê sort_rows(), która posortuje wszystkie wiersze macierzy.
   Przetestuj na wygenerowanej tablicy dwuwymiarowej
 ------------------------------------------------------------------------------------------------------------------------------- */
int compare(const void* a, const void* b) // const void* Jest to wskaŸnik, który przechowuje adres dowolnego typu danych, ale nie pozwala na modyfikowanie danych, które siê pod tym adresem znajduj¹. 
{
        // 1. Zamieniamy void* na int*
        // 2. Pobieramy wartoœci gwiazdk¹ *
        int aa = *(const int*)a;
        int bb = *( const int*)b;
        return aa > bb ? 1 : aa < bb ? -1 : 0; // Funkcja z wyk³adu
}

/* Funkcja rekurencyjna Quicksort podana na wyk³adzie*/
void sort_quick(int* arr, int low, int high)
{
    if (low < high)
    {
        // pi to indeks podzia³u, arr[pi] jest ju¿ na swoim docelowym miejscu po przepuszeczeniu przez funkcjê partiion
           int pivot = arr[high]; // Wybieramy ostatni element jako punkt odniesienia (osiowy)
            int i = (low - 1);    // Indeks mniejszego elementu

            for (int j = low; j <= high - 1; j++)
            {
                // Jeœli aktualny element jest mniejszy lub równy piwotowi
                if (compare(&arr[j], &pivot) <= 0)
                {
                    i++; // Przesuwamy granicê "mniejszych liczb" w prawo
                    //swap(&arr[i], &arr[j]); // Zamieniamy miejscami
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            //swap(&arr[i + 1], &arr[high]);
            int temp = arr[i+1];
            arr[i+1] = arr[high];
            arr[high] = temp;

            int pi = i + 1;
        // Sortujemy osobno lew¹ i praw¹ stronê od piwota
        sort_quick(arr, low, pi - 1);
        sort_quick(arr, pi + 1, high);
    }
}

void sort_rows(int** arr, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        sort_quick(arr[i], 0, n-1);

    }
}
void test_sort_row()
{
    int n = 10; // Rozmiar macierzy
    int** matrix = allocate_matrix(n, n); // Alokujemy macierz

    fill_matrix(matrix, n, n, 1, 150); // Wype³niamy macierz losowymi liczbami z zakresu 1 - 150
    printf("Macierz wygenerowana:\n");
    print_matrix(matrix, n, n); // Wypisujemy macierz

    //int wynik = max_nwd(matrix, n, n);
    //printf("Elementy %d, %d maj¹ NWD równy %d", wynik[0], wynik[1], wynik[2]);
    sort_rows(matrix, n, n);
    printf("Macierz posortowna:\n");
    print_matrix(matrix, n, n);
    free_matrix(matrix, n); // Zwolniamy pamiêæ
}
/*--------------------------------------------------- Zadanie 7 --------------------------------------------------------------
  Napisz funkcjê rotate90degree(int **a, int n, int m), która obraca macierz m x n o 90 stopni w kierunku przeciwnym do ruchu wskazówek zegara. 
  Nale¿y pamiêtaæ, ¿e wymiary macierzy wynikowej wynosz¹ n x m dla macierzy wejœciowej m x n. 
 ------------------------------------------------------------------------------------------------------------------------------- */
//Macierze A wymiaru n na m o wspo³czynikach a[i][j] to po obrobie maciecz B wymiaru m na a o wspó³czynikach b[k][l] = a[l][m+1-k]
void rotate90degree(int** a, int n, int m)

{
    int** matrix = allocate_matrix(m, n);
    for (int k = 0; k < m; k++)
    {
        for (int l = 0; l < n; l++)
        {
            matrix[k][l] = a[l][m - 1-k];
        }
    }
    //free_matrix(a, n);
    //*a = matrix;
    printf("Macierz obrócona o 90°:\n");
    print_matrix(matrix, m, n);
   

}
void test_rotate90degree()
{
    int n = 10;
    int m = n + n + 6;// Rozmiar macierzy
    int** matrix = allocate_matrix(n, m); // Alokujemy macierz

    fill_matrix(matrix, n, m, 1, 150); // Wype³niamy macierz losowymi liczbami z zakresu 1 - 150
    printf("Macierz wygenerowana:\n");
    print_matrix(matrix, n, m); // Wypisujemy macierz

   
    rotate90degree(matrix, n, m);
   // printf("Macierz obrócona o 90°:\n");
    //print_matrix(matrix, n, n);
    free_matrix(matrix, n); // Zwolniamy pamiêæ
}

void open_cw4() // Dodatkowowa funkcja która pozwala przestestowac wszystkie zadania poprzez podanie ich numeru
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
            draw_chess_board();
            break;
        case 2:
            printf("To samo rozwi¹zannie co w æwiczeniu nr 3\n");
        case 3:
            test_min_max_tab_2D();
            break;
        case 4:
            test_sums();
            break;
        case 5:
            test_max_nwd();
            break;
        case 6:
            test_sort_row();
            break;
        case 7:
            test_rotate90degree();
            break;
        case 8:
            printf("Comming soon!\n");
            break;
        default:
            printf("Nieprawidlowy numer cwiczenia!\n");
            break;
        }

        printf("Czy chcesz kontynuowaæ? T/N\n");
        scanf_s(" %c", &TN, (unsigned int)sizeof(TN));
    }
}