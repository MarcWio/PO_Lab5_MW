#ifndef KOMPOZYT_H_
#define KOMPOZYT_H_

#include <vector>

#include "ObiektSISO.hpp"

class Kompozyt
	:
	public ObiektSISO
{
protected:
	std::vector<ObiektSISO*> obiektySISO;
public:
	void dodaj(ObiektSISO* obiektSISO) override;
	void usun(ObiektSISO* obiektSISO) override;
};


#endif