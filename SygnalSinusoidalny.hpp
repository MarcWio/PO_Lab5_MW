#ifndef SYGNAL_SINUSOIDALNY_H
#define SYGNAL_SINUSOIDALNY_H

#include "DekoratorSygnalu.hpp"

// Dekorator konkrentny
class SygnalSinusoidalny 
	: 
	public DekoratorSignalu 
{
private:
	double s_amp;
	int s_okres;
public:
	SygnalSinusoidalny(Sygnal* sygnal, double amp, int okres);
	double symuluj(int t) override;
};

#endif
