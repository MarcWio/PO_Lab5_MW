#include "BialySzum.hpp"

BialySzum::BialySzum(Sygnal* sygnal, const int LOW_RANGE, const int MAX_RANGE)
    : DekoratorSignalu(sygnal), s_LOW_RANGE(LOW_RANGE), s_MAX_RANGE(MAX_RANGE) {}

double BialySzum::symuluj(int t)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> distribution(s_LOW_RANGE, s_MAX_RANGE);
    return distribution(gen);
}
