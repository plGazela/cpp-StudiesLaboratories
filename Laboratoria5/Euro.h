#pragma once

#include "Waluta.h"

class Euro : public Waluta {

public:
	Euro();
	Euro(double temp_kurs_euro_pln);
	~Euro();

	void SetEuro(double temp_kurs_euro_pln);
	double GetEuro() const;

	virtual void Drukuj() const;
	virtual void DrukujPlik(ofstream& temp_stream) const;
	virtual double Przelicznik_PLN_Waluta() const;

protected:
	double kurs_euro_pln;
};