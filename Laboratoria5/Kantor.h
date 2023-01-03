#pragma once

#include "Przedsiebiorstwo.h"
#include "DolarUSA.h"
#include "Euro.h"

class Kantor : public Przedsiebiorstwo {

	public:
		Kantor();
		Kantor(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, string temp_lokalizacja, string temp_nazwa_przedsiebiorstwa);
		~Kantor();

		void SetKantor(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, string temp_lokalizacja);
		string GetKantor() const;

		virtual void Drukuj() const;
		virtual void DrukujPlik(ofstream& temp_stream) const;
		virtual void Drukuj_Wszystkie_Kursy_Walut() const;

	protected:
		DolarUSA dolar;
		Euro euro;
		string lokalizacja;
};