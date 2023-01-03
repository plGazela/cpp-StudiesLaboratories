#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Przedsiebiorstwo {

	public:
		Przedsiebiorstwo();
		Przedsiebiorstwo(string temp_nazwa_przedsiebiorstwa);
		~Przedsiebiorstwo();

		void SetPrzedsiebiorstwo(string temp_nazwa_przedsiebiorstwa);
		string GetPrzedsiebiorstwo();

		virtual void Drukuj() const;
		virtual void DrukujPlik(ofstream & temp_stream) const;
		virtual void Drukuj_Wszystkie_Kursy_Walut() const = 0;


	protected:
		string nazwa_przedsiebiorstwa;
};