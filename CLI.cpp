#include "CLI.hpp"

extern nlohmann::json getExampleConfig();

void CLI::parseConfiguration()
{
    nlohmann::json data;
    try {
        std::ifstream file(directory + "/" + fileName);
        file >> data;
        file.close();
    }
    catch (...) {
        std::cerr << "Wystapil blad otwierania pliku!" << std::endl;
        exit(1);
    }

    // ARX
    nlohmann::json obiekt1AJson = data[1][1];
    if (obiekt1AJson.is_array()) {
        firstDenominatorPolynomialA = obiekt1AJson.get<std::vector<double>>();
    }
    nlohmann::json obiekt1BJson = data[1][3];
    if (obiekt1BJson.is_array()) {
        firstNumeratorPolynomialB = obiekt1BJson.get<std::vector<double>>();
    }
    arxK = data[1][5][0];
    arxOdchylenie = data[1][7][0];

    // Statyczny
    statycznyMin = data[3][1][0];
    statycznyMax = data[3][3][0];

    // PID
	pidK = data[5][1][0];
	pidTi = data[5][3][0];
	pidTd = data[5][5][0];

    // Staly
    stalyCzyOgraniczony = data[7][1][0];
    stalyStart = data[7][3][0];
    stalyKoniec = data[7][5][0];
    stalyWartosc = data[7][7][0];

    // Sinus
    sinusCzyAktywny = data[9][1][0];
    sinusAmplituda = data[9][3][0];
    sinusCzestotliwosc = data[9][5][0];


    // Prostokat
    prostokatCzyAktywny = data[11][1][0];
    prostokatAmplituda = data[11][3][0];
    prostokatCzestotliwosc = data[11][5][0];
    prostokatWypelnienie = data[11][7][0];

    // Trojkat
    trojkatCzyAktywny = data[13][1][0];
    trojkatCzestotliwosc = data[13][3][0];
    trojkatWypelnienie = data[13][5][0];

    // Szum
    szumCzyAktywny = data[15][1][0];

    // Czas symulacji
	simTime = data[17][1][0];
}

CLI::CLI()
{
    file = File();
}

void CLI::editARX() {
    int option;
    do {
        std::cout << "\n\nWsp A:" << std::endl;
        showVectorValues(firstDenominatorPolynomialA);
        std::cout << "Wsp B:" << std::endl;
        showVectorValues(firstNumeratorPolynomialB);
        std::cout << "k: " << arxK << std::endl;
        std::cout << "Odchylenie: " << arxOdchylenie << std::endl;
        std::cout << "ARX Menu:" << std::endl;
        std::cout << "1. Edytuj firstDenominatorPolynomialA" << std::endl;
        std::cout << "2. Edytuj firstNumeratorPolynomialB" << std::endl;
        std::cout << "3. Edytuj k" << std::endl;
        std::cout << "4. Edytuj odchylenie" << std::endl;
        std::cout << "0. Wyjdz" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> option;
        switch (option) {
        case 1: {
            std::cout << "Podaj wartosci zmiennoprzecinkowe oddzielone spacja firstDenominatorPolynomialA: ";
            std::string input;
            std::getline(std::cin.ignore(), input);
            std::istringstream iss(input);
            double value;
            firstDenominatorPolynomialA.clear();
            while (iss >> value) {
                firstDenominatorPolynomialA.push_back(value);
            }
            break;
        }
        case 2: {
            std::cout << "Podaj wartosci zmiennoprzecinkowe oddzielone spacja firstNumeratorPolynomialB: ";
            std::string input;
            std::getline(std::cin.ignore(), input);
            std::istringstream iss(input);
            double value;
            firstNumeratorPolynomialB.clear();
            while (iss >> value) {
                firstNumeratorPolynomialB.push_back(value);
            }
            break;
        }
        case 3: {
            std::cout << "Podaj nowa wartosc dla k: ";
            std::cin >> arxK;
            break;
        }
        case 4: {
            std::cout << "Podaj nowa wartosc dla odchylenia:" << std::endl;
            std::cin >> arxOdchylenie;
            break;
        }
        case 0:
            std::cout << "Wychodze." << std::endl;
            break;
        default:
            std::cout << "Zla opcja." << std::endl;
        }
        std::cout << std::endl;
    } while (option != 0);
}

void CLI::showVectorValues(const std::vector<double>& wektor)
{
    std::cout << "Aktualne wartosci: ";
    for (const auto& wartoœæ : wektor) {
        std::cout << wartoœæ << " ";
    }
    std::cout << std::endl;
}

void CLI::editPID() {
    int option;
    do {
        std::cout << "PID Menu:" << std::endl;
        std::cout << "1. Edytuj pidK" << std::endl;
        std::cout << "2. Edytuj pidTi" << std::endl;
        std::cout << "3. Edytuj pidTd" << std::endl;
        std::cout << "0. Wyjdz" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> option;
        switch (option) {
        case 1: {
            std::cout << "Podaj wartosc dla pidK: ";
            std::cin >> pidK;
            std::cout << "Nowa wartosc pidK: " << pidK << std::endl;
            break;
        }
        case 2: {
            std::cout << "Podaj wartosc dla pidTi: ";
            std::cin >> pidTi;
            std::cout << "Nowa wartosc pidTi: " << pidTi << std::endl;
            break;
        }
        case 3: {
            std::cout << "Podaj wartosc dla pidTd: ";
            std::cin >> pidTd;
            std::cout << "Nowa wartosc pidTd: " << pidTd << std::endl;
            break;
        }
        case 0:
            std::cout << "Wychodze" << std::endl;
            break;
        default:
            std::cout << "Nie ma takiego" << std::endl;
        }
        std::cout << std::endl;
    } while (option != 0);
}

void CLI::editSIMTIME() {
    int option;
    do {
        std::cout << "Menu SimTime:" << std::endl;
        std::cout << "1. Edytuj wartosc SimTime" << std::endl;
        std::cout << "0. Wyjdz" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> option;

        switch (option) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla SimTime: ";
            std::cin >> simTime;
            std::cout << "Zaktualizowana wartosc SimTime: " << simTime << std::endl;
            break;
        }
        case 0:
            std::cout << "Wyjscie z menu SimTime." << std::endl;
            break;
        default:
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
        }
        std::cout << std::endl;
    } while (option != 0);
}

void CLI::saveConfigToFile()
{
    nlohmann::json firstDenominatorJsonArray;
    for (const auto& value : firstDenominatorPolynomialA) {
        firstDenominatorJsonArray.push_back(value);
    }

    nlohmann::json firstNumeratorJsonArray;
    for (const auto& value : firstNumeratorPolynomialB) {
        firstNumeratorJsonArray.push_back(value);
    }
    nlohmann::json config =
    {
        "ARX",
            {
                "A",
                    firstDenominatorJsonArray,
                "B",
                    firstNumeratorJsonArray,
                "k",
                    {
                        arxK
                    },
                "odch_standard",
                    {
                        arxOdchylenie
                    }
            },
        "Statyczny",
            {
                "MIN",
                    {
                        statycznyMin
                    },
                "MAX",
                    {
                        statycznyMax
                    }
            },
        "PID",
            {
                "k",
                    {
                        pidK
                    },
                "Ti",
                    {
                        pidTi
                    },
                "Td",
                    {
                        pidTd
                    }
            },
        "Staly",
            {
                "Ograniczony",
                {
                    stalyCzyOgraniczony
                },
                "Start",
                {
                    stalyStart
                },
                "Koniec",
                {
                    stalyKoniec
                },
                "Wartosc",
                {
                    stalyWartosc
                }
            },
        "Sinus",
            {
                "Aktywny",
                {
                    sinusCzyAktywny
                },
                "Amplituda",
                {
                    sinusAmplituda
                },
                "Czestotliwosc",
                {
                    sinusCzestotliwosc
                }
            },
        "Prostokat",
            {
                "Aktywny",
                {
                    prostokatCzyAktywny
                },
                "Amplituda",
                {
                    prostokatAmplituda
                },
                "Czestotliwosc",
                {
                    prostokatCzestotliwosc
                },
                "Wypelnienie",
                {
                    prostokatWypelnienie
                }
            },
        "Trojkat",
            {
                "Aktywny",
                {
                    trojkatCzyAktywny
                },
                "Czestotliwosc",
                {
                    trojkatCzestotliwosc
                },
                "Wypelnienie",
                {
                    trojkatWypelnienie
                }
            },
        "Szum",
            {
                "Aktywny",
                {
                    szumCzyAktywny
                }
            },
        "System",
            {
                "Ilosc",
                {
                    simTime
                }
            }
    };
    std::string fileName;
    std::string folderName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::cout << "Podaj nazwe folderu: ";
    std::cin >> folderName;
    std::cout << "Podana nazwa pliku: " << fileName << std::endl;
    std::cout << "Podana nazwa folderu: " << folderName << std::endl;
    file.setFileNameDirectoryPath(fileName, folderName);
    file.createJsonFileConfig(config);
    loadedJsonFile = file.loadJsonFileConfig();
    std::cout << "\n=============================\n NOWA KONFIGURACJA WCZYTANA Z PLIKU! \n=============================\n";

}

void CLI::saveExampleConfig()
{
    fileName = "konfiguracja.json";
    directory = "123";
    file.setFileNameDirectoryPath(fileName, directory);
    file.createJsonFileConfig(getExampleConfig());
    loadedJsonFile = file.loadJsonFileConfig();
    parseConfiguration();
}

void CLI::loadCustomConfig() 
{
    std::cout << "Wczytaj swoj wlasny plik z konfiguracja\n";
    std::string filename;
    std::string directory;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> filename;
    std::cout << "Podaj nazwe folderu: ";
    std::cin >> directory;
    file.setFileNameDirectoryPath(filename, directory);
    loadedJsonFile = file.loadJsonFileConfig();
    std::cout << "\n\n" << loadedJsonFile.dump() << "\n\n";
    parseConfiguration();
}

void CLI::startSimulation()
{
    RegulatorPID* regulatorPID = new RegulatorPID(pidK, pidTi, pidTd);
    ObiektSISO* arx = new ModelARX(firstDenominatorPolynomialA, firstNumeratorPolynomialB, arxK, arxOdchylenie);
    ObiektSISO* statycznySISO = new ObiektStatyczny(statycznyMax, statycznyMin);
    ObiektSISO* kompozyt = new KompozytSzeregowy();
    kompozyt->dodaj(statycznySISO);
    kompozyt->dodaj(arx);

    // Mozna zmienic ZAMKNIETA/OTWARTA
    ObiektSISO* petla = new PetlaUAR(regulatorPID, kompozyt, ZAMKNIETA);

    Sygnal* sygnal = new ProstySygnal(stalyStart, stalyKoniec);
    if (sinusCzyAktywny > 0) {
        sygnal = new SygnalSinusoidalny(sygnal, sinusAmplituda, sinusCzestotliwosc);
    }
    if (prostokatCzyAktywny > 0) {
        sygnal = new FalaProstokatna(sygnal, prostokatAmplituda, prostokatCzestotliwosc, prostokatWypelnienie);
    }
    if (trojkatCzyAktywny > 0) {
        sygnal = new SygnalTrojkatny(sygnal, trojkatCzestotliwosc, trojkatWypelnienie);
    }
    if (szumCzyAktywny > 0) {
        sygnal = new BialySzum(sygnal, 0, 1);
    }

    std::vector<double> output;
    for (int i = 0; i < simTime; i++) {
        output.push_back(petla->symuluj(sygnal->symuluj(i)));
    }
    std::cout << "\n\n Symulacja: \n";
    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i] << ", ";
    }
    std::cout << "\n\n";
}

void CLI::showMenu(std::string fileName , std::string directory)
{
    if (fileName.size() == 0 || directory.size() == 0) {
        std::cout << "Domyslna konfiguracja:\n";
        std::cout << "Jesli masz juz plik domyslny nadpisz go.\n";
        saveExampleConfig();
    }
    else {
        this->fileName = fileName;
        this->directory = directory;
        file.setFileNameDirectoryPath(fileName, directory);
        loadedJsonFile = file.loadJsonFileConfig();
        std::cout << "\n\n" << loadedJsonFile.dump() << "\n\n";
        parseConfiguration();
    }

    int opcja;
    do {
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj ARX" << std::endl;
        std::cout << "2. Edytuj Obiekt Statyczny" << std::endl;
        std::cout << "3. Edytuj PID" << std::endl;
        std::cout << "4. Edytuj Staly" << std::endl;
        std::cout << "5. Edytuj Sinus" << std::endl;
        std::cout << "6. Edytuj Prostokat" << std::endl;
        std::cout << "7. Edytuj Trojkat" << std::endl;
        std::cout << "8. Edytuj Szum" << std::endl;
        std::cout << "9. Edytuj Czas Symulacji" << std::endl;
        std::cout << "10. Zapisz konfiguracje do pliku" << std::endl;
        std::cout << "11. Uruchom symulacje" << std::endl;
        std::cout << "12. Wczytaj swoja konfiguracje" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;
        switch (opcja) {
        case 1:
            editARX();
            break;
        case 2:
            editStatic();
            break;
        case 3:
            editPID();
            break;
        case 4:
            editStaly();
            break;
        case 5:
            editSinus();
            break;
        case 6:
            editProstokat();
            break;
        case 7:
            editTrojkat();
            break;
        case 8:
            editSzum();
            break;
        case 9:
            editSimTime();
            break;
        case 10:
            saveConfigToFile();
            break;
        case 11:
            startSimulation();
            break;
        case 12:
            loadCustomConfig();
            break;
        case 0:
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        default:
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
        }
        std::cout << std::endl;
    } while (opcja != 0);
}

void CLI::editStatic()
{
    int choice;
    do {
        std::cout << "\n\nAktualne wartosci:" << std::endl;
        std::cout << "statycznyMin = " << statycznyMin << std::endl;
        std::cout << "statycznyMax = " << statycznyMax << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj statycznyMin" << std::endl;
        std::cout << "2. Edytuj statycznyMax" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla statycznyMin: ";
            std::cin >> statycznyMin;
            break;
        }
        case 2: {
            std::cout << "Podaj nowa wartosc dla statycznyMax: ";
            std::cin >> statycznyMax;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;

    } while (choice != 0);
}

void CLI::editStaly()
{
    int choice;

    do {
        std::cout << "\n\nAktualne wartosci:" << std::endl;
        std::cout << "stalyCzyOgraniczony = " << stalyCzyOgraniczony << std::endl;
        std::cout << "stalyStart = " << stalyStart << std::endl;
        std::cout << "stalyKoniec = " << stalyKoniec << std::endl;
        std::cout << "stalyWartosc = " << stalyWartosc << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj stalyCzyOgraniczony" << std::endl;
        std::cout << "2. Edytuj stalyStart" << std::endl;
        std::cout << "3. Edytuj stalyKoniec" << std::endl;
        std::cout << "4. Edytuj stalyWartosc" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj now¹ wartosc dla stalyCzyOgraniczony (0 lub 1): ";
            std::cin >> stalyCzyOgraniczony;
            break;
        }
        case 2: {
            std::cout << "Podaj nowa wartosc dla stalyStart: ";
            std::cin >> stalyStart;
            break;
        }
        case 3: {
            std::cout << "Podaj nowa wartosc dla stalyKoniec: ";
            std::cin >> stalyKoniec;
            break;
        }
        case 4: {
            std::cout << "Podaj nowa wartosc dla stalyWartosc: ";
            std::cin >> stalyWartosc;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    } while (choice != 0);
}

void CLI::editSinus()
{
    int choice;
    do {
        std::cout << "\n\nAktualne wartosci:" << std::endl;
        std::cout << "sinusCzyAktywny = " << sinusCzyAktywny << std::endl;
        std::cout << "sinusAmplituda = " << sinusAmplituda << std::endl;
        std::cout << "sinusCzestotliwosc = " << sinusCzestotliwosc << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj sinusCzyAktywny" << std::endl;
        std::cout << "2. Edytuj sinusAmplituda" << std::endl;
        std::cout << "3. Edytuj sinusCzestotliwosc" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla sinusCzyAktywny (0 lub 1): ";
            std::cin >> sinusCzyAktywny;
            break;
        }
        case 2: {
            std::cout << "Podaj nowa wartosc dla sinusAmplituda: ";
            std::cin >> sinusAmplituda;
            break;
        }
        case 3: {
            std::cout << "Podaj nowa wartosc dla sinusCzestotliwosc: ";
            std::cin >> sinusCzestotliwosc;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;

    } while (choice != 0);
}

void CLI::editProstokat()
{
    int choice;
    do {
        std::cout << "\n\nAktualne wartosci:" << std::endl;
        std::cout << "prostokatCzyAktywny = " << prostokatCzyAktywny << std::endl;
        std::cout << "prostokatAmplituda = " << prostokatAmplituda << std::endl;
        std::cout << "prostokatCzestotliwosc = " << prostokatCzestotliwosc << std::endl;
        std::cout << "prostokatWypelnienie = " << prostokatWypelnienie << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj prostokatCzyAktywny" << std::endl;
        std::cout << "2. Edytuj prostokatAmplituda" << std::endl;
        std::cout << "3. Edytuj prostokatCzestotliwosc" << std::endl;
        std::cout << "4. Edytuj prostokatWypelnienie" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla prostokatCzyAktywny (0 lub 1): ";
            std::cin >> prostokatCzyAktywny;
            break;
        }
        case 2: {
            std::cout << "Podaj nowa wartosc dla prostokatAmplituda: ";
            std::cin >> prostokatAmplituda;
            break;
        }
        case 3: {
            std::cout << "Podaj nowa wartosc dla prostokatCzestotliwosc: ";
            std::cin >> prostokatCzestotliwosc;
            break;
        }
        case 4: {
            std::cout << "Podaj nowa wartosc dla prostokatWypelnienie: ";
            std::cin >> prostokatWypelnienie;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    } while (choice != 0);
}

void CLI::editTrojkat()
{
    int choice;
    do {
        std::cout << "\n\nAktualne wartosci:" << std::endl;
        std::cout << "trojkatCzyAktywny = " << trojkatCzyAktywny << std::endl;
        std::cout << "trojkatCzestotliwosc = " << trojkatCzestotliwosc << std::endl;
        std::cout << "trojkatWypelnienie = " << trojkatWypelnienie << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj trojkatCzyAktywny" << std::endl;
        std::cout << "2. Edytuj trojkatCzestotliwosc" << std::endl;
        std::cout << "3. Edytuj trojkatWypelnienie" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla trojkatCzyAktywny (0 lub 1): ";
            std::cin >> trojkatCzyAktywny;
            break;
        }
        case 2: {
            std::cout << "Podaj nowa wartosc dla trojkatCzestotliwosc: ";
            std::cin >> trojkatCzestotliwosc;
            break;
        }
        case 3: {
            std::cout << "Podaj nowa wartosc dla trojkatWypelnienie: ";
            std::cin >> trojkatWypelnienie;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    } while (choice != 0);
}

void CLI::editSzum()
{
    int choice;
    do {
        std::cout << "\n\nAktualna wartosc: szumCzyAktywny = " << szumCzyAktywny << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj szumCzyAktywny" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj now¹ wartosc dla szumCzyAktywny (0 lub 1): ";
            std::cin >> szumCzyAktywny;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    } while (choice != 0);
}

void CLI::editSimTime()
{
    int choice;
    do {
        std::cout << "\n\nAktualna wartosc: simTime = " << simTime << std::endl;
        std::cout << "\n\nMenu:" << std::endl;
        std::cout << "1. Edytuj simTime" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Podaj nowa wartosc dla simTime: ";
            std::cin >> simTime;
            break;
        }
        case 0: {
            std::cout << "Wyjscie z programu." << std::endl;
            break;
        }
        default: {
            std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    } while (choice != 0);
}
