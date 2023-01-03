#include "Kantor.h"

// Konstruktor i destruktor
Kantor::Kantor() : Przedsiebiorstwo("") {
	SetKantor(0.1, 0.1, "");
}

Kantor::Kantor(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, string temp_lokalizacja, string temp_nazwa_przedsiebiorstwa) : Przedsiebiorstwo(temp_nazwa_przedsiebiorstwa) {
	SetKantor(temp_kurs_dolar_pln, temp_kurs_euro_pln, temp_lokalizacja);
}

Kantor::~Kantor() {

}

// Funkcje klasy
void Kantor::SetKantor(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, string temp_lokalizacja) {
	dolar.SetDolarUSA(temp_kurs_dolar_pln);
	euro.SetEuro(temp_kurs_euro_pln);
	lokalizacja = temp_lokalizacja;
}

string Kantor::GetKantor() const {
	return lokalizacja;
}

void Kantor::Drukuj() const {
	cout << "Lokalizacja: " << lokalizacja << "\n";
}

void Kantor::DrukujPlik(ofstream& temp_stream) const {
	temp_stream << "Lokalizacja: " << lokalizacja << "\n";
}

void Kantor::Drukuj_Wszystkie_Kursy_Walut() const {
	dolar.Drukuj();
	euro.Drukuj();
}