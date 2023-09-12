#ifndef OBIEKT_SISO_H
#define OBIEKT_SISO_H

class ObiektSISO {
public:
    virtual double symuluj(double u) = 0;
    virtual ~ObiektSISO() {}

    virtual void dodaj(ObiektSISO* obiekt) = 0;
    virtual void usun(ObiektSISO* obiekt) = 0;
};

#endif
