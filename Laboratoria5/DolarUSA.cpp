#include "DolarUSA.h"

// Konstriktor i destruktor
DolarUSA::DolarUSA() {
	SetDolarUSA(0.1);
}

DolarUSA::DolarUSA(double temp_kurs_dolar_pln) : Waluta("DolarUSA") {
	SetDolarUSA(temp_kurs_dolar_pln);
}

DolarUSA::~DolarUSA() {

}

// Funkcje klasy
void DolarUSA::SetDolarUSA(double temp_kurs_dolar_pln) {
	kurs_dolar_pln = temp_kurs_dolar_pln;
}

double DolarUSA::GetDolarUSA() const {
	return kurs_dolar_pln;
}

void DolarUSA::Drukuj() const {
	Waluta::Drukuj();
	cout << "Kurs DolarUSA / PLN: " << kurs_dolar_pln << "\n";
	cout << "Kurs PLN / DolarUSA: " << Przelicznik_PLN_Waluta() << "\n\n";
}

void DolarUSA::DrukujPlik(ofstream & temp_stream) const {
	Waluta::DrukujPlik(temp_stream);
	temp_stream << "Kurs DolarUSA / PLN: " << kurs_dolar_pln << "\n";
	temp_stream << "Kurs PLN / DolarUSA: " << Przelicznik_PLN_Waluta() << "\n\n";
}

double DolarUSA::Przelicznik_PLN_Waluta() const {
	return 1.0 / kurs_dolar_pln;
}