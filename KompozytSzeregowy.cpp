#include "KompozytSzeregowy.hpp"

double KompozytSzeregowy::symuluj(double u)
{
    for (auto x : obiektySISO) {
        u += x->symuluj(u);
    }
    return u;
}
