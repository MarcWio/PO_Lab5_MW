#ifndef OBIEKT_STATYCZNY_H_
#define OBIEKT_STATYCZNY_H_

#include <iostream>

#include "ObiektSISO.hpp"

class ObiektStatyczny
	:
	public ObiektSISO
{
private:
	double max;
	double min;
public:
	ObiektStatyczny(double max, double min)
		: max(max), min(min) {}

	void setMax(double max);
	void setMin(double min);
	
	double symuluj(double u) override;
	
	void dodaj(ObiektSISO* obiektSISO);
	void usun(ObiektSISO* obiektSISO);
};

#endif