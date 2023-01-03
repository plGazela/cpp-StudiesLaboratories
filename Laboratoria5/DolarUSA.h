#pragma once

#include "Waluta.h"

class DolarUSA : public Waluta {
	
	public:
		DolarUSA();
		DolarUSA(double temp_kurs_dolar_pln);
		~DolarUSA();

		void SetDolarUSA(double temp_kurs_dolar_pln);
		double GetDolarUSA() const;

		virtual void Drukuj() const;
		virtual void DrukujPlik(ofstream& temp_stream) const;
		virtual double Przelicznik_PLN_Waluta() const;

	protected:
		double kurs_dolar_pln;
};