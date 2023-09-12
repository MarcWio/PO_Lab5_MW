#ifndef SYGNAL_DECORATOR_H
#define SYGNAL_DECORATOR_H

#include "Sygnal.hpp"

// Dekorator
class DekoratorSignalu 
    : 
    public Sygnal 
{
protected:
    Sygnal* sygnal;
public:
    DekoratorSignalu(Sygnal* sygnal)
        : Sygnal(sygnal), sygnal(sygnal) {};

    double symuluj(int t) override {
        return sygnal->symuluj(t);
    };
};

#endif