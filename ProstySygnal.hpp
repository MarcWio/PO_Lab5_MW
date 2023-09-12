#ifndef SIMPLE_SIGNAL_H
#define SIMPLE_SIGNAL_H

#include "Sygnal.hpp"

// Komponent konkretny
class ProstySygnal
	:
	public Sygnal 
{
public:
	ProstySygnal(int start, int koniec)
		: Sygnal(start, koniec) {}

	double symuluj(int t) override {
		return 0.0;
	};
};

#endif