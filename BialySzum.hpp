#ifndef BIALY_SZUM_H
#define BIALY_SZUM_H

#include <random>

#include "DekoratorSygnalu.hpp"

// Dekorator konkretny
class BialySzum
	:
	public DekoratorSignalu
{
private:
	const int s_LOW_RANGE;
	const int s_MAX_RANGE;
public:
	BialySzum(Sygnal* sygnal, const int LOW_RANGE, const int MAX_RANGE);
	double symuluj(int t) override;
};

#endif
