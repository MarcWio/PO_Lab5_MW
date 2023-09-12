#include "KompozytRownolegly.hpp"

double KompozytRownolegly::symuluj(double u)
{
    double y = 0.0;
    for (auto x : obiektySISO) {
        y += x->symuluj(u);
    }
    return y;
}
