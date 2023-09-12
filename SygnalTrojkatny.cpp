#include "SygnalTrojkatny.hpp"

SygnalTrojkatny::SygnalTrojkatny(Sygnal* sygnal, double freq, double wyp)
    : DekoratorSignalu(sygnal), s_freq(freq), s_wyp(wyp) {}

double SygnalTrojkatny::symuluj(int t)
{
    double okres = 1.0 / s_freq;
    double faza = fmod(t, okres) / okres;
    if (czyAktywny(t)) {
        if (faza < s_wyp)
            return (2.0 * faza / s_wyp) - 1.0;
        else
            return (-2.0 * (faza - s_wyp) / (1.0 - s_wyp)) + 1.0;
    }
    return 0.0;
}
