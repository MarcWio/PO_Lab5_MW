#include "RegulatorPID.hpp";

void RegulatorPID::setPositiveValue(double& field, double value)
{
	if (value >= 0) {
		field = value;
	}
}

double RegulatorPID::calculateP(double input)
{
	return proportionalGain * input;
}

double RegulatorPID::calculateI(double input)
{
	if (integralTimeConstant == 0 || integralTermMemory == 0) {
		integralTermMemory += 1;
		return 0;
	}
	double output = (1 / integralTimeConstant) + previousErrorMemory;
	previousErrorMemory = output;
	return output;
}

void RegulatorPID::setProportionalGain(double _proportionalGain)
{
	setPositiveValue(proportionalGain, _proportionalGain);
}

void RegulatorPID::setIntegralTimeConstant(double _integralTimeConstant)
{
	setPositiveValue(integralTimeConstant, _integralTimeConstant);
}

void RegulatorPID::setDerivativeTimeConstant(double _derivativeTimeConstant)
{
	setPositiveValue(derivativeTimeConstant, _derivativeTimeConstant);
}

double RegulatorPID::symuluj(double input)
{
	return calculateP(input) + calculateI(input);
}

void RegulatorPID::dodaj(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}

void RegulatorPID::usun(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}
