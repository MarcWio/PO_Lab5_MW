#include "Kompozyt.hpp"

void Kompozyt::dodaj(ObiektSISO* obiektSISO)
{
	obiektySISO.push_back(obiektSISO);
}

void Kompozyt::usun(ObiektSISO* obiektSISO)
{
	std::vector<ObiektSISO*>::iterator index = std::find(obiektySISO.begin(), obiektySISO.end(), obiektSISO);
	if (index != obiektySISO.end()) {
		obiektySISO.erase(index);
	}
}
