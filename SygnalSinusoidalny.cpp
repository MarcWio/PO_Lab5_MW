#include <cmath>
#include "SygnalSinusoidalny.hpp"

SygnalSinusoidalny::SygnalSinusoidalny(Sygnal* sygnal, double amp, int okres)
	: DekoratorSignalu(sygnal), s_amp(amp), s_okres(okres) {}

double SygnalSinusoidalny::symuluj(int t) 
{
	if (czyAktywny(t))
		return s_amp * std::sin((static_cast<double> (t % s_okres) / s_okres) * 6.28);
	else
		return 0;
}
