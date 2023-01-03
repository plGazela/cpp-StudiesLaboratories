#include "Przedsiebiorstwo.h"

// Konstruktor i destruktor
Przedsiebiorstwo::Przedsiebiorstwo() {
	SetPrzedsiebiorstwo("");
}

Przedsiebiorstwo::Przedsiebiorstwo(string temp_nazwa_przedsiebiorstwa) {
	SetPrzedsiebiorstwo(temp_nazwa_przedsiebiorstwa);
}

Przedsiebiorstwo::~Przedsiebiorstwo() {

}

// Funkcje klasy
void Przedsiebiorstwo::SetPrzedsiebiorstwo(string temp_nazwa_przedsiebiorstwa) {
	nazwa_przedsiebiorstwa = temp_nazwa_przedsiebiorstwa;
}

string Przedsiebiorstwo::GetPrzedsiebiorstwo() {
	return nazwa_przedsiebiorstwa;
}

void Przedsiebiorstwo::Drukuj() const {
	cout << nazwa_przedsiebiorstwa << "\n";
}

void Przedsiebiorstwo::DrukujPlik(ofstream & temp_stream) const {
	temp_stream << "Nazwa przedsiêbiorstwa: " << nazwa_przedsiebiorstwa << "\n";
}