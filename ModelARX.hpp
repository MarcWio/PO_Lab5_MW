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
    std::vector<double> denominatorPolynomialA;     // Wsp�czynniki dla wielomianu mianownika A
    std::vector<double> numeratorPolynomialB;       // Wsp�czynniki dla wielomianu licznika B

    std::vector<double> inputBuffer;                // Bufor wej�cia
    std::vector<double> outputBuffer;               // Bufor wyj�cia
    std::vector<double> delayBuffer;                // Bufor op�nienia

    int delay;                                      // Rz�d op�nienia transportowego
    double standardDeviation;                       // Odchylenie standardowe

    std::queue<double> mInputQueue;                 // Kolejka sygna��w wej�cia
    std::queue<double> mOutputQueue;                // Kolejka sygna��w wyj�cia
    std::deque<int> mDelayQueue;                    // Kolejka op�nienia

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
