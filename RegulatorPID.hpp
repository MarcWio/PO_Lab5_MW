#ifndef REGULATOR_PID_H_
#define REGULATOR_PID_H_

#include "ObiektSISO.hpp"

#include <iostream>

class RegulatorPID 
    : public ObiektSISO 
{
private:
    double proportionalGain;          
    double integralTimeConstant;        
    double derivativeTimeConstant;         
    double integralTermMemory;   
    double previousErrorMemory; 

    void setPositiveValue(double& filed, double value);
    double calculateP(double input);
    double calculateI(double input);
public:
    RegulatorPID(double _proportionalGain)
        : 
        integralTimeConstant{ 0.0 }, 
        derivativeTimeConstant{ 0.0 }, 
        integralTermMemory{ 0.0 }, 
        previousErrorMemory{ 0.0 } 
    {
        setProportionalGain(_proportionalGain);
    }

    RegulatorPID(double _proportionalGain, double _integralTimeConstant)
        :
        derivativeTimeConstant{ 0.0 },
        integralTermMemory{ 0.0 },
        previousErrorMemory{ 0.0 }
    {
        setProportionalGain(_proportionalGain);
        setIntegralTimeConstant(_integralTimeConstant);
    }

    RegulatorPID(double _proportionalGain, double _integralTimeConstant, double _derivativeTimeConstant)
        :
        integralTermMemory{ 0.0 },
        previousErrorMemory{ 0.0 }
    {
        setProportionalGain(_proportionalGain);
        setIntegralTimeConstant(_integralTimeConstant);
        setDerivativeTimeConstant(_derivativeTimeConstant);
    }

    ~RegulatorPID() {}
    
    void setProportionalGain(double _proportionalGain);

    void setIntegralTimeConstant(double _integralTimeConstant);

    void setDerivativeTimeConstant(double _derivativeTimeConstant);

    double symuluj(double input) override;

    void dodaj(ObiektSISO* obiektSISO) override;

    void usun(ObiektSISO* obiektSISO) override;
};

#endif