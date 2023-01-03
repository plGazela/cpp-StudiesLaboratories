#pragma once

#include "Przedsiebiorstwo.h"
#include "Euro.h"
#include "DolarUSA.h"

class Bank : public Przedsiebiorstwo {

	public:
		Bank();
		Bank(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, double temp_oprocentowanie_lokaty, string temp_nazwa_banku);
		~Bank();

		void SetBank(double temp_kurs_dolar_pln, double temp_kurs_euro_pln, double temp_oprocentowanie_lokaty);
		double GetBank() const;

		virtual void Drukuj() const;
		virtual void DrukujPlik(ofstream & temp_stream) const;
		virtual void Drukuj_Wszystkie_Kursy_Walut() const;

	protected:
		DolarUSA dolar;
		Euro euro;
		double oprocentowanie_lokaty;
};