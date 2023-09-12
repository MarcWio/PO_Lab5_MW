#include "ModelARX.hpp"

ModelARX::ModelARX(const std::vector<double>& _denominatorPolynomialA, 
				   const std::vector<double>& _numeratorPolynomialB, 
				   int _delay = 1, 
				   double _standardDeviation = 0.0
) {
	setdenominatorPolynomialA(_denominatorPolynomialA);
	setnumeratorPolynomialB(_numeratorPolynomialB);
	setDelay(_delay);
	setStandardDeviation(_standardDeviation);
}

void ModelARX::setdenominatorPolynomialA(const std::vector<double>& _denominatorPolynomialA) {
	denominatorPolynomialA = _denominatorPolynomialA;
	inputBuffer.resize(_denominatorPolynomialA.size(), 0);
}

void ModelARX::setnumeratorPolynomialB(const std::vector<double>& _numeratorPolynomialB) {
	numeratorPolynomialB = _numeratorPolynomialB;
	outputBuffer.resize(_numeratorPolynomialB.size(), 0);
}

void ModelARX::setDelay(unsigned int _delay) {
	if (_delay <= 0) {
		std::cerr << ("Transport delay must be positive.");
	}
	delay = _delay;
	delayBuffer.resize(denominatorPolynomialA.size() + delay, 0);
}

void ModelARX::setStandardDeviation(double _standardDeviation) {
	if (_standardDeviation >= 0.0) {
		standardDeviation = _standardDeviation;
	}
	else {
		standardDeviation = 0.0;
	}
}

void ModelARX::dodaj(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}

void ModelARX::usun(ObiektSISO* obiektSISO)
{
	throw std::runtime_error("Invalid OBJ");
}

double ModelARX::symuluj(double u) {
	static int mDelayQueueInvoke = 0;
	if (delay >= mDelayQueue.size() || mDelayQueueInvoke <= delay) {
		mDelayQueueInvoke++;
		mDelayQueue.push_front(u);
		return 0.0;
	}
	delayBuffer.insert(delayBuffer.begin(), u);
	if (delayBuffer.size() > delay) {
		delayBuffer.pop_back();
	}
	double output = 0.0;
	for (int i = 0; i < numeratorPolynomialB.size(); i++) {
		if (i <= delay) {
			output += numeratorPolynomialB[i] * delayBuffer[i];
		}
	}
	for (int i = 0; i < denominatorPolynomialA.size(); i++) {
		if (i <= outputBuffer.size()) {
			output -= denominatorPolynomialA[i] * outputBuffer[i];
		}
	}
	outputBuffer.insert(outputBuffer.begin(), output);
	if (outputBuffer.size() > denominatorPolynomialA.size() - 1) {
		outputBuffer.pop_back();
	}
	double e = simulateNoise();
	return output + e;
}

double ModelARX::simulateNoise() {
	// W funkcji distribution odchylenie standardowe nie mo¿e wynosiæ 0.0, bo inaczej
	// rozk³ad normalny nie bêdzie dobrze okreœlony.
	if (standardDeviation == 0.0) {
		return 0.0;
	}
	std::default_random_engine generator;
	std::normal_distribution<double> distribution{ 0.0, standardDeviation };
	return distribution(generator);
}