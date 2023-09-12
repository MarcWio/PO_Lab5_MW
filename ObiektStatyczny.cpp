#include "ObiektStatyczny.hpp"

void ObiektStatyczny::setMax(double max)
{
    this->max = max;
}

void ObiektStatyczny::setMin(double min)
{
    this->min = min;
}

double ObiektStatyczny::symuluj(double u)
{
    if (max < min) {
        std::cerr << "MAX wieksze niz MIN" << std::endl;
    }
    if (u >= max) {
        u = max;
    }
    if (u <= min) {
        u = min;
    }
    return u;
}

void ObiektStatyczny::dodaj(ObiektSISO* obiektSISO)
{
    throw std::runtime_error("Invalid OBJ");
}

void ObiektStatyczny::usun(ObiektSISO* obiektSISO)
{
    throw std::runtime_error("Invalid OBJ");
}
