#ifndef KOMPOZYT_SZEREGOWY_H_
#define KOMPOZYT_SZEREGOWY_H_

#include "Kompozyt.hpp"

class KompozytSzeregowy
	:
	public Kompozyt
{
public:
	double symuluj(double u) override;
};

#endif