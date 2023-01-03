#include "Bank.h"

// Konstruktor i destruktor
Bank::Bank() : Przedsiebiorstwo("") {
	SetBank(0.1, 0.1, 0.0);
}

Bank::Bank(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, double temp_oprocentowanie_lokaty, string temp_nazwa_banku) : Przedsiebiorstwo(temp_nazwa_banku) {
	SetBank(temp_kurs_dolar_pln, temp_kurs_euro_pln, temp_oprocentowanie_lokaty);
}

Bank::~Bank() {

}

// Funkcje klasy
void Bank::SetBank(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, double temp_oprocentowanie_lokaty) {
	dolar.SetDolarUSA(temp_kurs_dolar_pln);
	euro.SetEuro(temp_kurs_euro_pln);
	oprocentowanie_lokaty = temp_oprocentowanie_lokaty;
}

double Bank::GetBank() const {
	return oprocentowanie_lokaty;
}

void Bank::Drukuj() const {
	cout << "Oprocentowanie lokaty: " << oprocentowanie_lokaty << "\n";
}

void Bank::DrukujPlik(ofstream & temp_stream) const {
	temp_stream << "Oprocentowanie lokaty: " << oprocentowanie_lokaty << "\n";
}

void Bank::Drukuj_Wszystkie_Kursy_Walut() const {
	dolar.Drukuj();
	euro.Drukuj();
}