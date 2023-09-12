#include "Sygnal.hpp"

Sygnal::Sygnal(Sygnal* sygnal)
	: s_start(sygnal->s_start), s_koniec(sygnal->s_koniec) {}

Sygnal::Sygnal(int start, int koniec)
	: s_start(start), s_koniec(koniec) {}

bool Sygnal::czyAktywny(int t) {
	return (t >= s_start && t <= s_koniec) ? true : false;
}
