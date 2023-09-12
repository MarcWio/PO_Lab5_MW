#ifndef CLI_H_
#define CLI_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "json.hpp"
#include "File.hpp"
#include "ModelARX.hpp"
#include "RegulatorPID.hpp"
#include "ObiektStatyczny.hpp"
#include "KompozytSzeregowy.hpp"
#include "PetlaUAR.hpp"
#include "Sygnal.hpp"
#include "ProstySygnal.hpp"
#include "SygnalSinusoidalny.hpp"
#include "SygnalTrojkatny.hpp"
#include "FalaProstokatna.hpp"
#include "BialySzum.hpp"

class CLI
{
private:
	std::string fileName;
	std::string directory;
	File file;
	nlohmann::json loadedJsonFile;

	// ARX
	std::vector<double> firstDenominatorPolynomialA;
	std::vector<double> firstNumeratorPolynomialB;
	double arxK;
	double arxOdchylenie;

	// Statyczny
	int statycznyMin;
	int statycznyMax;

	// PID
	double pidK;
	double pidTi;
	double pidTd;

	// Staly
	int stalyCzyOgraniczony;
	int stalyStart;
	int stalyKoniec;
	double stalyWartosc;

	// Sinus
	int sinusCzyAktywny;
	double sinusAmplituda;
	double sinusCzestotliwosc;

	// Prostokat
	int prostokatCzyAktywny;
	double prostokatAmplituda;
	double prostokatCzestotliwosc;
	double prostokatWypelnienie;

	// Trojkat
	int trojkatCzyAktywny;
	double trojkatCzestotliwosc;
	double trojkatWypelnienie;

	// Szum
	int szumCzyAktywny;

	// Czas symulacji
	int simTime;

	void parseConfiguration();
	void editARX();
	void editPID();
	void editSIMTIME();
	void saveConfigToFile();
	void saveExampleConfig();
	void loadCustomConfig();
	void startSimulation();
	void editStatic();
	void editStaly();
	void editSinus();
	void editProstokat();
	void editTrojkat();
	void editSzum();
	void editSimTime();
	void showVectorValues(const std::vector<double>& wektor);
public:
	CLI();
	void showMenu(std::string fileName = "", std::string directory = "");
};

#endif
