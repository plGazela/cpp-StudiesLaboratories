// Zadanie2a.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Funkcja znajdująca najdorższy produkt
double ProduktNajdrozszy(double wie, double kol, double* tab[], int dane[]) {

	double najwiekszaCena = 0;
	int numerProduktu = 0;

	for (int i = 0; i < wie; i++) {
		for (int j = 0; j < kol; j++) {
			if (i == 0 && j == 0) {
				najwiekszaCena = tab[i][j];

				numerProduktu = i + 1;

				continue;
			}

			if (najwiekszaCena < tab[i][j]) {
				najwiekszaCena = tab[i][j];

				numerProduktu = i + 1;
			}
		}
	}

	dane[0] = numerProduktu;

	return najwiekszaCena;
}

// Funkcja sprawdzająca cenę zakupów
void CenaZakupow(int wie, int kol, double* tab[], double tabC[]) {

	double sumaZakupow = 0;
	for (int i = 0; i < kol; i++) {
		for (int j = 0; j < wie; j++) {
			sumaZakupow += tab[j][i];
		}

		tabC[i] = sumaZakupow;
		sumaZakupow = 0;
	}

}

// Funkcja wypisująca tablice z danymi
void wpiszDane(int wie, int kol, double* tab[]) {

	for (int i = 0; i < wie; i++) {
		if (i == 0) {
			cout.width(9);
			cout << " ";

			for (int k = 0; k < kol; k++) {
				cout.width(12);
				cout << right << "Drogeria-" << k + 1;
			}
			cout << "\n";
		}

		cout.width(8);
		cout << left << "Produkt-" << i + 1;

		for (int j = 0; j < kol; j++) {
			cout.width(13);
			cout << fixed;
			cout << setprecision(1);
			cout << right << tab[i][j];
		}

		cout << "\n";
	}

	cout << "\n";

}

void ZapiszWynikiDoPliku(ofstream& zapis, double wie, double kol, double* tab[], int dane[], double tabC[]) {
	zapis.open("wyniki.txt");

	zapis << "Studia laboratioria - Zadanie 2a\n";
	zapis << "Program do obsułgi Drogerii\n\n";

	for (int i = 0; i < kol; i++) {
		zapis << "Suma koszyka Drogeria-" << i + 1 << ": " << tabC[i] << "\n";
	}
	cout << "\n\n";

	zapis << "Najdroższy produkt kosztuje " << ProduktNajdrozszy(wie, kol, tab, dane) << " i jest to produkt " << dane[0] << ".\n";

	zapis.close();
}

// Głowna funkcja
int main() {

	// Wsparcie polskich znaków
	system("chcp 1250");
	system("cls");

	cout << "Studia laboratioria - Zadanie 2a\n";
	cout << "Program do obsułgi Drogerii\n\n";

	// Odczyt pliku
	string sciezkaPliku = "ceny_produktow.txt";
	ifstream odczytPliku;

	odczytPliku.open(sciezkaPliku, ios::in);

	if (!odczytPliku) {
		cout << "Podany plik nie został znaleziony. Pzerwanie działania programu...\n";
		return 0;
	}

	int wiersze = 0, kolumny = 0;
	string danePliku;

	// Sprawdzenie ilości wierszy
	while (true) {
		if (odczytPliku.eof()) {
			break;
		}
		else if (getline(odczytPliku, danePliku)) {
			wiersze++;
		}
	}

	//Sprawdzenie ilości kolumn
	odczytPliku.seekg(0);
	while (true) {
		if (odczytPliku.eof()) {
			break;
		}

		odczytPliku >> danePliku;
		kolumny++;
	}
	kolumny /= wiersze;

	// Zapis danych z pliku do dynamicznej tablicy
	double** D;
	D = new double* [wiersze];

	for (int i = 0; i <= wiersze; i++)
		D[i] = new double[kolumny];

	double liczbyPliku;

	odczytPliku.seekg(0);
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			while (true) {
				odczytPliku >> liczbyPliku;
				break;
			}

			D[i][j] = liczbyPliku;
		}
	}

	odczytPliku.close();

	// Wypisanie tablicy z danymi
	wpiszDane(wiersze, kolumny, D);


	// Wypisanie sumy cen produktów
	double* cena;
	cena = new double[kolumny];

	CenaZakupow(wiersze, kolumny, D, cena);

	for (int i = 0; i < kolumny; i++) {
		cout << "Suma koszyka Drogeria-" << i + 1 << ": " << cena[i] << "\n";
	}
	cout << "\n";

	// Wypisanie najdroższego produktu
	int* daneProduktu;
	daneProduktu = new int[1];

	daneProduktu[0] = 0;

	cout << "Najdroższy produkt kosztuje " << ProduktNajdrozszy(wiersze, kolumny, D, daneProduktu) << " i jest to produkt " << daneProduktu[0] << ".\n";

	// Zapis do pliku
	ofstream zapisPliku;
	ZapiszWynikiDoPliku(zapisPliku, wiersze, kolumny, D, daneProduktu, cena);

	// Oczyszczenie pamięci
	for (int i = 0; i < wiersze; i++) {
		delete[] D[i];
	}
	delete[] D;
	delete[] cena;
	delete[] daneProduktu;

	return 0;
}