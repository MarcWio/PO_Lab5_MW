#include "FalaProstokatna.hpp"

FalaProstokatna::FalaProstokatna(Sygnal* sygnal, double amp, int okres, double wypelnienie)
	: DekoratorSignalu(sygnal), s_amp(amp), s_okres(okres), s_wypelnienie(wypelnienie) {}

double FalaProstokatna::symuluj(int t)
{
	if (czyAktywny(t)) {
		return((t % s_okres) < (s_wypelnienie * s_okres)) ? s_amp : 0;
	}
	else
		return 0;
}
