#ifndef MODEL_ARX_H
#define MODEL_ARX_H

#include <iostream>
#include <queue>
#include <random>
#include "ObiektSISO.hpp"

class ModelARX 
    : public ObiektSISO 
{
private:
    std::vector<double> denominatorPolynomialA;     // Wspó³czynniki dla wielomianu mianownika A
    std::vector<double> numeratorPolynomialB;       // Wspó³czynniki dla wielomianu licznika B

    std::vector<double> inputBuffer;                // Bufor wejœcia
    std::vector<double> outputBuffer;               // Bufor wyjœcia
    std::vector<double> delayBuffer;                // Bufor opóŸnienia

    int delay;                                      // Rz¹d opóŸnienia transportowego
    double standardDeviation;                       // Odchylenie standardowe

    std::queue<double> mInputQueue;                 // Kolejka sygna³ów wejœcia
    std::queue<double> mOutputQueue;                // Kolejka sygna³ów wyjœcia
    std::deque<int> mDelayQueue;                    // Kolejka opóŸnienia

    double simulateNoise();
public:
    ModelARX(const std::vector<double>& _denominatorPolynomialA, 
             const std::vector<double>& _numeratorPolynomialB, 
             int _delay, 
             double _standardDeviation
    );
    double symuluj(double u) override;

    void setdenominatorPolynomialA(const std::vector<double>& _denominatorPolynomialA);
    void setnumeratorPolynomialB(const std::vector<double>& _numeratorPolynomialB);
    void setDelay(unsigned int _delay);
    void setStandardDeviation(double _standardDeviation);

    void dodaj(ObiektSISO* obiektSISO) override;
    void usun(ObiektSISO* obiektSISO) override;
};

#endif
