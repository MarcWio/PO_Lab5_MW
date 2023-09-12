#ifndef SYGNAL_TROJKATNY_H
#define SYGNAL_TROJKATNY_H

#include <cmath>

#include "DekoratorSygnalu.hpp"

// Dekorator konkrentny
class SygnalTrojkatny
	:
	public DekoratorSignalu
{
private:
	double s_freq;
	double s_wyp;
public:
	SygnalTrojkatny(Sygnal* sygnal, double freq, double wyp);
	double symuluj(int t) override;
};

#endif
