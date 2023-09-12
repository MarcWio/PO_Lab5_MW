#ifndef SYGNAL_H
#define SYGNAL_H

// Komponent
class Sygnal 
{
private:
	int s_start;
	int s_koniec;
protected:
	bool czyAktywny(int t);
public:
	Sygnal(Sygnal* sygnal);
	Sygnal(int start, int koniec);
	virtual ~Sygnal() = default;
	virtual double symuluj(int t) = 0;
};

#endif
