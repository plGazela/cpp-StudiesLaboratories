// Zadanie6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//int znajdzMinWartosc(int rozmiarTablicy, int tablica[]) {
//    // Przykład wyglądu funkcji zwracającej minimalną wartość typu int
//    int minWartosc = 0;
//
//    for (int i = 0; i < rozmiarTablicy; i++) {
//        if (i == 0) {
//            minWartosc = tablica[i];
//            continue;
//        }
//
//        if (minWartosc >= tablica[i]) {
//            minWartosc = tablica[i];
//        }
//    }
//
//    return minWartosc;
//}

template <typename typDanych> typDanych* rozlokujPamiecTablicy(int rozmiarTablicy) {
    // Funkcja przydzielająca pamięć dla tablicy
    typDanych* nowaTablica = new typDanych[rozmiarTablicy];
    return nowaTablica;
}

template <typename typDanych> typDanych najmniejsza_wartosc(int rozmiarTablicy, typDanych tablica[], int& numerIndeksu) {
    // Funkcja do znajdowania najmniejszej pensji
    typDanych minWartosc = 0;

    for (int i = 0; i < rozmiarTablicy; i++) {
        if (i == 0) {
            minWartosc = tablica[i];
            numerIndeksu = i + 1;
            continue;
        }

        if (minWartosc >= tablica[i]) {
            minWartosc = tablica[i];
            numerIndeksu = i + 1;
        }
    }

    return minWartosc;
}

int main() {
    // Zadanie 6
    system("chcp 1250");
    system("cls");

    cout << "Zadanie 6 - pracownicy i zawodnicy\n\n";

    // Deklaracja tablic
    const int rozmiarPracownik = 12;
    const int rozmiarZawodnik = 6;
    //int pracownik[12];
    //float zawodnik[6];

    int* pracownik = rozlokujPamiecTablicy<int>(rozmiarPracownik);
    float* zawodnik = rozlokujPamiecTablicy<float>(rozmiarZawodnik);

    // Losowanie danych do tablic oraz ich wypisanie wyników
    srand(static_cast <unsigned int> (time(0)));

    cout << "Pracownik:\n[ ";
    for (int i = 0; i < rozmiarPracownik; i++) {
        pracownik[i] = rand() % 1201 + 3000;

        if (i == rozmiarPracownik - 1) {
            cout << pracownik[i];
        }
        else {
            cout << pracownik[i] << ", ";
        }
    }
    cout << " ]\n";

    cout << "Zawodnik:\n[ ";
    for (int i = 0; i < rozmiarZawodnik; i++) {
        zawodnik[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2)) + 11;
        zawodnik[i] = round(zawodnik[i] * 10) / 10;

        cout << setprecision(4);

        if (i == rozmiarZawodnik - 1) {
            cout << zawodnik[i];
        }
        else {
            cout << zawodnik[i] << ", ";
        }
    }
    cout << " ]\n\n";

    int numerProby = 0;
    cout << "Najmniejsza pensja: " << najmniejsza_wartosc(rozmiarPracownik, pracownik, numerProby) << "\n";
    cout << "Najkrótszy czas: " << najmniejsza_wartosc(rozmiarZawodnik, zawodnik, numerProby) << "s w próbie " << numerProby << "\n";

    // Zwolnienie pamięci
    delete[] pracownik;
    delete[] zawodnik;

    return 0;
}