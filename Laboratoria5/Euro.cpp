#include "Euro.h"

// Konstriktor i destruktor
Euro::Euro() {
	SetEuro(0.1);
}

Euro::Euro(double temp_kurs_euro_pln) : Waluta("Euro") {
	SetEuro(temp_kurs_euro_pln);
}

Euro::~Euro() {

}

// Funkcje klasy
void Euro::SetEuro(double temp_kurs_euro_pln) {
	kurs_euro_pln = temp_kurs_euro_pln;
}

double Euro::GetEuro() const {
	return kurs_euro_pln;
}

void Euro::Drukuj() const {
	Waluta::Drukuj();
	cout << "Kurs Euro / PLN: " << kurs_euro_pln << "\n";
	cout << "Kurs PLN / Euro: " << Przelicznik_PLN_Waluta() << "\n\n";
}

void Euro::DrukujPlik(ofstream& temp_stream) const {
	Waluta::Drukuj();
	temp_stream << "Kurs Euro / PLN: " << kurs_euro_pln << "\n";
	temp_stream << "Kurs PLN / Euro: " << Przelicznik_PLN_Waluta() << "\n\n";
}

double Euro::Przelicznik_PLN_Waluta() const {
	return 1.0 / kurs_euro_pln;
}
