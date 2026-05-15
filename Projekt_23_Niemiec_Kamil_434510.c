/*========================================================================
* Author: Kamil Niemiec
* Uczelnia: Akademia Górniczo-Hutnicza im. Stanisława Staszica w Krakowie
* Nr albumu: 434510
* Kierunek: Informatyka i Ekonometria
* Rok studiów: 1
* Semestr: 2
* Przedmiot: Programowanie komputerów
* Data wykonania: 2026-03-15
* Description: Program w języku C na zaliczenie Przedmiotu Programowanie komputerów
===================================================================
Temat Projkeu: Projekt 23. Czytanie w myślach (1 osoba). Zasady gry:
Założenia projketowe:
–        w każdej turze użytkownik wybiera ruch w lewo lub w prawo używając klawiatury
–        komputer próbuje przewidzieć wybór użytkownika,
–        jeśli komputer pomyślnie przewidzi wybór użytkownika, wygrywa rundę, w przeciwnym razie użytkownika wygrywa rundę,
–        pierwszy kto wygra 25 rund, wygrywa grę,
–        użytkownik ma 3 sekundy na każdą turę, a dodatkowy czas jest przenoszony do następnej rundy do 10 sekund. Jeśli nie wykonasz ruchu na czas, przegrywasz rundę.
===================================================================================================================================================================*/

#include <stdio.h>
#include <windows.h> // dla funkcji sleep() i nie tylko
#include <conio.h> // do pobierania znaków - funkcja getch
#include <string.h>// bibioteka do obsugłi funkcji string
#include <time.h>

#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void look_for_char() //Funkcja pomocnicza do wyświetlania wszyskich znaków z tabliczy ASCI
{
  
    for (int i = 0; i < 256; i++)
    {
        printf("Znak nr [%d] to: %c\n", i, i);
    }
    /* ------------ Do użytku---------------
        Znak nr [16] to: ►
        Znak nr [17] to: ◄

        Znak nr [26] to: →
        Znak nr [27] to: //nie ma - po sprawdzeniu znak 27 został zmieniony w którymś stantadzei ASCI na znak sterujący ESC (Escape)

  
        Znak nr[75] to: K  - strzałak w lewo z klawiatury
        Znak nr[77] to : M - strzałak w lewo z klawiatury
        Znak nr [97] to: a
        Znak nr [100] to: d
        Znak nr [65] to: A
        Znak nr [68] to: D
        --------------------------------*/

}
// Funkcja teraz przyjmuje wskaźnik do miejsca, gdzie ma zapisać imię
void ask_name(char* buffer, int size)
{
    int valid = 0;
    while (!valid)
    {
        printf("\rPodaj swoje imie lub Nick: ");

        // Wczytujemy bezpiecznie
        if (fgets(buffer, size, stdin) != NULL)
        {
            // Usuwamy znak nowej linii '\n', który dodaje fgets
            buffer[strcspn(buffer, "\n")] = 0;

            if (strlen(buffer) > 2)
            {
                valid = 1; // Imię jest poprawne
            }
            else
            {
                printf("\033[2J\033[H");// \033[2J czyści ekran, \033[H przesuwa kursor do lewego górnego rogu - specjany kod
                printf("Imie za krotkie! Sprobuj ponownie.\n");
            }
        }
    }
    printf("\033[2J\033[H");// 033[2J czyści ekran, \033[H przesuwa kursor do lewego górnego rogu - specjany kod
}

// Funkcja zwraca: -1 (lewo), 2 (prawo), 0 (koniec czasu)
int get_choice_with_timer(float time_limit, float* time_left_out, char info[]) //Funkcja która czeka na iput od użytkownika, ale jednocześnie nie zatrzumuje oblicznia czasu dzięki wykorzytsaniu _kbhit()
{
    clock_t start_time = clock();// Czas początkowy uruchomienia kodu
    float t_licznik = 0; // licznik upływającego czasu

    while (t_licznik < time_limit) // pętla uruchomiona dopóki nie przekroczymy dostępnego limitu
    {
        // 1. Obliczanie czasu
        t_licznik = (float)(clock() - start_time)/1000; //Aktualny czas minus zapisany czas rozpoczęcia podzielony przez 1000(żeby z mili sekund zrobić sekundy)
        float t_left= time_limit - t_licznik; // czas który pozostał

        // 2. Aktualizacja licznika w tej samej linii (\r) oraz przesuniecie kursora 
        printf("\033[H\033[K %s %.1f s \n", info, t_left); // \033[H – przesuń kursor do lewgo górnego rogu; \033[1B przesunkurso o jedną linię w dół
     

        // 3. Sprawdzenie czy naciśnięto klawisz (klucz do sukcesu!)
        if (_kbhit()) {
            int ch = _getch();

            // Obsługa klawiszy specjalnych (strzałek)
            if (ch == 224 || ch == 0) {
                ch = _getch();
                if (ch == 75) { *time_left_out = t_left; return -1; } // Lewo
                if (ch == 77) { *time_left_out = t_left; return 1; } // Prawo
            }
            // Obsługa zwykłych klawiszy
            else {
                if (ch == 'a' || ch == 'A') { *time_left_out = t_left; return -1; }
                if (ch == 'd' || ch == 'D') { *time_left_out = t_left; return 1; }
            }
        }

        Sleep(50); // Mała przerwa, żeby kod nie wykonywał się czały czas tylko co 0,05 sekundy
    }

    return 0; // Kod oznaczający przegraną przez czas który wykona się kiedy t_licznik spadnie poniżej time_limit
}

int comp_guess(int count) // funkcja która na podstawie licznikia count przewiduje nastepnych ruch użytkownika
{
    if (count <= 2 && count >= -2)
    {
        count = (rand()%2)*2-1;
    }
   
        if (count > 0) return 1;
        else return -1;
       // count >= 0 ? 1 : -1; // Funkcja z wykładu
}

void game(char user_name[], int liczba_rund, int poziom)
{
    
    int lr = liczba_rund;
    float time_limit = 3.0f; // Startowy czas
    float time_left = 0; //inicjalizacja zmiennych
    int user_score = 0, comp_score = 0, runda = 0;
    char info[256];
    int choice = 0, count = 0;
    
    while (user_score < lr && comp_score < lr) //Pętla wykonywana dopóki użytkownik lub komputer nie uzyska 25 punktów
    {
        
        snprintf(info, sizeof(info), "Runda: %d\t Punkty %s: %d\t Punkty Computer: %d\t Czas: ", runda, user_name, user_score, comp_score); //funkcja snprintf zapisuje Nagłowke do zmiennej in fo dzięki tyemu kmogę go przekazać do funkcji get_choice_with_timer i uzupełnić go o pozostały do czas 
        
        printf("\033[H\033[3B\rWybierz kierunek: lewo[A, <-] lub prawo [D,  ->]: \n"); // \033[H przesuwam się do prawwego górnego rogu a następnie przechodzę o 1 wiersz w dół, dzięki temu ten tekst zawsze pojawi się w linijce nr 2

        if (count * choice < 0)//Jeżeli użytkownik zmieni kierunek licznik zostanmie zresetowanny
        {
            count = 0;
        }
        //printf("Wybor: %d \n", count);
       count += choice;//naliczaneni licznia wyboru kireunku - im wyższa wartość (na moduł) tym częściej został wybrany dany kireunk pod rząd
       runda++;
        // Wywołujemy naszą nową funkcję

       int comp_choice = comp_guess(count);
       //printf("Wybor Comp: %d \n", comp_choice ); // Do sprawdzenia jak są generowane wybory

       choice = get_choice_with_timer(time_limit, &time_left, info);// Funkcja do oblicznia pozostago czasu w czasie rzeczywisym zanim użytkownik wybierze kierunek

        if (choice == 0) // brak wyboru z wyznaczonym czasie -> punkt dla komputera
        {
            printf("\n\033[KCZAS MINAL! Punkt dla komputera.");
            comp_score++;
            time_limit = poziom; // Reset czasu po przegranej
        }
        else //sprawdzenie czy komputer prawidłowo przewidział ruch
            
        {
            if (choice == comp_choice) // koputer trafił, punkt dla niego
            {
                printf("\n\033[KKomputer przewidzial Twoj ruch! Punkt dla niego.");
                comp_score++;
            }
            else 
            {
                printf("\n\033[KWygrales runde!");
                user_score++; // koputer nie przwidział poprawnie kierunku -> punkt dla użytkownika
            }

            // Logika przenoszenia czasu:
            time_limit = poziom + time_left;// Zwiększam limi czasu o 3 sekundy do nasepnej rundy
            if (time_limit > 10.0f) time_limit = 10.0f; // Jeśli limi przekracza 10 sekund ustawim czas równy 10s

            //printf("\n\033[KCzas na nastepna runde: %.1f s", time_limit);
        }
        
    }
    printf("\033[2J\033[H"); //Polecnie do wyczyszcenia ekranu
    if (user_score == lr) 
    {
        printf("Gratulacje! Udalo Ci sie wygrac z przewaga %d punktow.\n ", user_score - comp_score);
    }
    else
    {
        printf("Niestety przegrales...\n ");
    }
    _getch();
}

int start_game()
{

    
    char user_name[64] ="User";
    int liczba_rund = 25;
   char wyb_menu;
   int poziom_nr = 3;
   const char* poziom[] = { "Sredni", "Trudny",  "Latwy"};
    while (1)
    {
        printf("\033[2J\033[H"); //Polecnie do wyczyszcenia ekranu
        printf("Witaj w grze w: Czytanie w myslach!\n\n");
        printf("Wybierz jedna z ponizszych opcji:\n");
        printf("\t1. Rozpocznij gre\n");
        printf("\t2. Ustawienia\n");
        printf("\t3. Jak grac?\n");
        printf("\t4. Zakoncz\n");

        wyb_menu = _getch();
        printf("\033[2J\033[H"); //Polecnie do wyczyszcenia ekranu
        switch (wyb_menu)
        {
          
            case '1':
                game(user_name, liczba_rund, poziom_nr);
                break;
            case '2':
                printf("Aktualne ustawienia: \tLiczba rund: %d \tImie: %s \tPoziom: %s\n\n", liczba_rund, user_name, poziom[poziom_nr%3]);
               // printf("Wybierz jedna z ponizszych opcji:\n");
                printf("\t1. Zmien ilosc rund \n");
                printf("\t2. Zmien imie\n");
                printf("\t3. Zmien poziom\n");
                printf("\t4. Wroc");
                wyb_menu = _getch();
                printf("\033[2J\033[H"); //Polecnie do wyczyszcenia ekranu
                switch (wyb_menu)
                {
                    //printf("\033[2J\033[H"); //Polecnie do wyczyszcenia ekranu
                case '1':
                    printf("Wpisz liczbe rund(aktualnie %d):", liczba_rund);
                    //liczba_rund = _getch();
                    scanf_s("%d", &liczba_rund);
                    break;
                case '2':
                    ask_name(user_name, sizeof(user_name));
                    break;
                case '3':
                    printf("\tWybierz pzoiom\n");
                    printf("\t1. Latwy - 5 sekund na wybor \n");
                    printf("\t2. Sredni - 3 sekundy na wybor \n"); 
                    printf("\t3. Trudny - 1 sekunda na wybor \n");
                    wyb_menu = _getch();
                    switch (wyb_menu)
                    {
                    case '1':
                        poziom_nr = 5;
                       
                        break;
                    case '3':
                        poziom_nr = 1;
                        break;
                    default:
                        poziom_nr = 3;
                        break;
                    }
                    break;
                default:
                    break;
                }
               break;
            case '3':
                printf("Czytanie w myslach.Zasady gry :\n");
                printf("- w kazdej turze uzytkownik wybiera ruch w lewo [A, <-] lub w prawo[D, ->] uzywajac klawiatury\n");
                printf("- komputer probuje przewidziec wybor uzytkownika,\n");
                printf("- jesli komputer pomyslnie przewidzi wybor uzytkownika, wygrywa runde, w przeciwnym razie uzytkownik wygrywa runde,\n");
                printf("- pierwszy kto wygra 25 rund (wartosc domyslna), wygrywa gre,\n");
                printf("- uzytkownik ma 3 sekundy na kazda ture, a dodatkowy czas jest przenoszony do nastepnej rundy do 10 sekund.\n-Jesli nie wykonasz ruchu na czas, przegrywasz runde\n");
                _getch();
                break;
            case '4':
               return 0;
            default:
                break;
        }
 
    }
return 0;
} 
/*==========================================================================
              ----------- Uwaga: -------------
Nie jestem autroem poniższego kodu
Jest on potrzebny tylko przy uruhamianiu programu z pliku .exe bez tego program nie działa prawidłowo
- Funkcje które powinny nadpisywac generowany stale tekst rozlewją się po ekranie
            ----------- Opis: -------------
Kod który sprawia że znaki typu:
    \033[2J -  czysci cały ekran
    \033[K - czyści całą linie
    \033[H - przesuwam się do lewego górnego rogu
    \033[*A - przesuwa się o * lini w górę
    \033[*B - przesuwa się o * lini w doł
iterpretretowane jako komendy sterujące 
==========================================================================*/
void enable_ansi() 
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}