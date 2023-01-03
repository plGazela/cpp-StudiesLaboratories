#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Waluta {

	public:
		Waluta();
		Waluta(string temp_nazwa_waluty);
		~Waluta();

		void SetWaluta(string temp_nazwa_waluty);
		string GetWaluta() const;
		
		virtual void Drukuj() const;
		virtual void DrukujPlik(ofstream & temp_stream) const;
		virtual double Przelicznik_PLN_Waluta() const = 0;

	protected:
		string nazwa_waluty;
};

