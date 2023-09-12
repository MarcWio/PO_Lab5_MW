#include "PetlaUAR.hpp"

double PetlaUAR::zamknietaPetla(double u)
{
	static double y = 0;
	double sub = u - y;
	double simVal = regulatorPID->symuluj(sub);
	y = obiektSISO->symuluj(simVal);
	return y;
}

double PetlaUAR::otwartaPetla(double u)
{
	double simVal = regulatorPID->symuluj(u);
	return obiektSISO->symuluj(simVal);
}

double PetlaUAR::symuluj(double u)
{
	if (jakaPetla == ZAMKNIETA) {
		return zamknietaPetla(u);
	}
	else if (jakaPetla == OTWARTA) {
		return otwartaPetla(u);
	}
	return 0.0;
}

void PetlaUAR::dodaj(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}

void PetlaUAR::usun(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}
