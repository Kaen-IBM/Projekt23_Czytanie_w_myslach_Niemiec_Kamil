#Projekt 23 — Czytanie w myślach

#Konsolowa gra dla jednego gracza w języku C. Komputer próbuje odczytać Twoje myśli — czy uda mu się przewidzieć Twój następny ruch?

---

#Opis projektu

Projekt 23 to gra zrealizowana w ramach przedmiotu **Programowanie komputerów** na Akademii Górniczo-Hutniczej im. Stanisława Staszica w Krakowie.

W każdej rundzie gracz wybiera kierunek — lewo lub prawo. Komputer na podstawie historii poprzednich wyborów stara się przewidzieć ruch gracza. Kto pierwszy zdobędzie 25 punktów, wygrywa całą grę. 
Elementem utrudniającym jest *imit czasu — każda tura ma odliczanie, a niewykorzystany czas przechodzi na następną rundę.

---

#Zasady gry

- W każdej turze wybierasz: lewo: `←` / `A` lub prawo: `→` / `D`
- Komputer próbuje odgadnąć Twój wybór zanim go wykonasz
- Jeśli komputer trafnie przewidzi → punkt dla komputera
- Jeśli komputer chybi → punkt dla Ciebie
- Pierwszy gracz z 25 punktami wygrywa
- Masz 3 sekundy na ruch (domyślnie) — brak ruchu = punkt dla komputera
- Niewykorzystany czas przenosi się do kolejnej rundy (maks. 10 sekund)

---

##Sterowanie

| Klawisz | Akcja |
|---------|-------|
| `←` lub `A` | Ruch w lewo |
| `→` lub `D` | Ruch w prawo |
| `1` – `4` | Nawigacja w menu |

---

## Poziomy trudności

| Poziom 		| Czas bazowy 			| Opis |
|--------		|------------			|------|
| Łatwy 		| 5 sekund		 	| Dużo czasu na decyzję |
| Średni *(domyślny)* 	| 3 sekundy 			| Zgodny ze specyfikacją projektu |
| Trudny 		| 1 sekunda 			| Bardzo szybkie decyzje wymagane |

---

#Struktura projektu

```
Projekt23/
├── main2025.c                           # Punkt wejścia — funkcja main()
├── Projekt_23_Niemiec_Kamil_434510.c    # Implementacja wszystkich funkcji
├── Projekt_23_Niemiec_Kamil_434510.h    # Plik nagłówkowy — deklaracje
└── README
    └── Dokumentacja_Projekt23_Niemiec_Kamil_434510.pdf
```


#
#Autor

| **Imię i nazwisko** 	| Kamil Niemiec 						|
| **Nr albumu** 	| 434510 							|
| **Uczelnia** 		| Akademia Górniczo-Hutnicza im. Stanisława Staszica w Krakowie |
| **Kierunek** 		| Informatyka i Ekonometria 					|
| **Rok / Semestr** 	| I rok, Semestr 2 						|
| **Przedmiot** 	| Programowanie komputerów 					|
| **Data** 		| 2026-03-15 							|

---

Projekt zrealizowany na zaliczenie przedmiotu Programowanie komputerów — AGH Kraków 2026
