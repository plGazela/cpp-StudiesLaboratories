// Zadanie7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

template <typename typ> typ* rozlokuj_pamiec(int tRozmiar) {
    
    // Rozlokowywanie pamięci dla tablicy dynamicznej
    typ* nowaTablica = new typ[tRozmiar];
    return nowaTablica;

}

template <typename ekran> void wypisz_wektor_ekran(ekran* tablica_wektor, int nelem) {

    // Wypisywanie wartości tablic na ekranie
    cout << "[ ";
    for (int i = 0; i < nelem; i++) {
        if (i == nelem - 1) {
            cout << tablica_wektor[i];
        }
        else {
            cout << tablica_wektor[i] << ", ";
        }
    }
    cout << " ]\n";
}

template <typename typ> void wypisz_wektor_plik(int nelem, typ* tablica, ofstream& zapis) {
    
    // Zapisywanie wyników do jednego pliku
    zapis.open("wektory.txt", ios::app);

    zapis << "[ ";
    for (int i = 0; i < nelem; i++) 
    {
        if (i == nelem - 1) 
        {
            zapis << tablica[i];
        } 
        else 
        {
            zapis << tablica[i] << ", ";
        }
    }
    zapis << " ]\n";

    zapis.close();
}

template <typename typ> double srednia_arytmetyczna(typ* tablica, int nelem) {

    // Obliczanie średniej arytmetycznej
    double srednia = 0;
    for (int i = 0; i < nelem; i++) {
        srednia = srednia + tablica[i];
    }
    srednia /= nelem;

    return srednia;
}

template <typename typ> typ mediana(typ* tablica, int nelem) {

    // Obliczenie mediany
    typ mediana;
    double wartosc1;
    double wartosc2;

    if ((nelem % 2) == 0) {
        wartosc1 = tablica[(nelem / 2)];
        wartosc2 = tablica[(nelem / 2)-1];

        mediana = (wartosc1 + wartosc2) / 2.0;
    } else {
        mediana = tablica[(nelem / 2)];
    }

    return mediana;
}

double zaokraglenie(double wartosc, int dokladnosc) {

    // Zaokrąglanie liczb
    if (dokladnosc < 1 || dokladnosc > 15) {
        return 0;
    }

    int wynikZaokraglenia;
    // Przesunięcie przecinka w liczbie
    wynikZaokraglenia = wartosc * pow(10, dokladnosc + 1);

    // Zaokrąglenie liczby w górę, w przypadku, gdy cyfra jedności jest większa bądź równa 5
    if (wynikZaokraglenia % 10 >= 5) {
        wynikZaokraglenia += 10;
    }

    // Zwrócenie zaokrąglonej liczby
    return (wynikZaokraglenia / 10) / pow(10, dokladnosc);
}

int main() {
    // Wyświetlanie polskich znaków
    system("chcp 1250");
    system("cls");

    cout << "Zadanie 7 - zarobki pracowników i oceny książki\n\n";

    // Podanie liczby pracowników i przygotowanie odpowiedniej tablicy z naszymi wartościami
    int n;
    cout << "Podaj liczbę pracowników: ";
    cin >> n;

    cout << "\n";

    int* zarobki = rozlokuj_pamiec<int>(n);

    int pensja;
    for (int i = 0; i < n; i++) {
        cout << "Wpisz zarobki pracownika: " << i + 1 << ": ";
        cin >> pensja;
        zarobki[i] = pensja;
    }
    cout << "\n";

    // Podanie ilości ocen i przygotowanie odpowiedniej tablicy z naszymi wartościami
    int m;
    cout << "Podaj ilość ocen: ";
    cin >> m;

    cout << "\n";

    float* oceny = rozlokuj_pamiec<float>(n);

    // Sprawdzanie poprawnosci wprowadzonych ocen przez uzytkownika  
    float ocena;
    for (int i = 0; i < m; i++) {
        cout << "Wpisz ocenę " << i+1 << ": ";
        cin >> ocena;

        oceny[i] = zaokraglenie(ocena, 1);
    }

    cout << "\n";

    // Sortowanie wartości w tablicach od najmniejszej do największej
    sort(zarobki, zarobki + n);
    sort(oceny, oceny + m);
   
    // Wypisanie wyników na ekran i zapisanie ich do pliku
	wypisz_wektor_ekran(oceny, m);
	wypisz_wektor_ekran(zarobki, n);
   
    ofstream zapisPliku;
    wypisz_wektor_plik(n, zarobki, zapisPliku);
    wypisz_wektor_plik(m, oceny, zapisPliku);

    // Wyznaczanie średnich arytmetycznych i median
    srednia_arytmetyczna(oceny, m);
    srednia_arytmetyczna(zarobki, n);

    mediana(zarobki, n);
    mediana(oceny, m);

    // Wypisanie wyników
    double sredniaZarobki = srednia_arytmetyczna(zarobki, n);
    double sredniaOceny = srednia_arytmetyczna(oceny, m);

    cout << "\nŚrednia zarobki = " << sredniaZarobki << "\n";
    cout << "Średnia oceny = " << sredniaOceny << "\n\n";

    int medianaZarobki = mediana(zarobki, n);
    float medianaOceny = mediana(oceny, m);

    cout << "Mediana zarobki = " << medianaZarobki << "\n";
    cout << "Mediana oceny = " << medianaOceny << "\n";

    // Zwolnienie pamięci
    delete[] zarobki;
    delete[] oceny;

    return 0;
}