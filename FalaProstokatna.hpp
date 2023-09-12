#ifndef FALA_PROSTOKATNA_H
#define FALA_PROSTOKATNA_H

#include "DekoratorSygnalu.hpp"

// Dekorator konkrentny
class FalaProstokatna
	: 
	public DekoratorSignalu
{
private:
	double s_amp;	
	int s_okres;
	double s_wypelnienie;
public:
	FalaProstokatna(Sygnal* sygnal, double amp, int okres, double wypelnienie);
	double symuluj(int t) override;
};

#endif