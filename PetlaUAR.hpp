#ifndef PETLA_UAR_H
#define PETLA_UAR_H

#include "ObiektSISO.hpp"
#include "RegulatorPID.hpp"
#include "ModelARX.hpp"

enum PETLA { ZAMKNIETA, OTWARTA };

class PetlaUAR
	:
	public ObiektSISO
{
private:
	RegulatorPID* regulatorPID;
	ObiektSISO* obiektSISO;
	enum PETLA jakaPetla;

	double zamknietaPetla(double u);
	double otwartaPetla(double u);
public: 
	PetlaUAR(RegulatorPID* regulatorPID, ObiektSISO* obiektSISO, PETLA jakaPetla = ZAMKNIETA)
		: regulatorPID(regulatorPID), obiektSISO(obiektSISO), jakaPetla(jakaPetla) {}

	double symuluj(double u) override;

	void dodaj(ObiektSISO* obiektSISO) override;
	void usun(ObiektSISO* obiektSISO) override;
};

#endif
