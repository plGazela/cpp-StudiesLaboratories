#include "Waluta.h"

// Konstruktor i destruktor
Waluta::Waluta() {
	SetWaluta("");
}
Waluta::Waluta(string temp_nazwa_waluty) {
	SetWaluta(temp_nazwa_waluty);
}
Waluta::~Waluta() {

}

// Funkcje klasy
void Waluta::SetWaluta(string temp_nazwa_waluty) {
	nazwa_waluty = temp_nazwa_waluty;
}

string Waluta::GetWaluta() const {
	return nazwa_waluty;
}

void Waluta::Drukuj() const {
	cout << "Nazwa waluty: " << nazwa_waluty << "\n";
}

void Waluta::DrukujPlik(ofstream & temp_stream) const {
	temp_stream << "Nazwa waluty: " << nazwa_waluty;
}