#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#define DEBUG

#include "json.hpp"
#include "RegulatorPID.hpp"
#include "File.hpp"
#include "CLI.hpp"


extern nlohmann::json getExampleConfig();

using namespace std;

int main(int argc, char* argv[])
{
	CLI cli = CLI();
    std::string fileName;
    std::string directory;
    if (argc != 5) {
        std::cout << "Nieprawidlowe uruchomienie programu." << std::endl;
        std::cout << "Poprawne uzycie: app.exe -f nazwa_pliku.json -d folder" << std::endl;
        std::cout << "Uruchamiam z domyslna konfiguracja." << std::endl;
        cli.showMenu();
    }
    else {
        for (int i = 1; i < argc; i += 2) {
            std::string option = argv[i];

            if (option == "-f") {
                fileName = argv[i + 1];
            }
            else if (option == "-d") {
                directory = argv[i + 1];
            }
            else {
                std::cout << "Nieprawidlowy parametr: " << option << std::endl;
                return 1;
            }
        }
        std::cout << "Nazwa pliku: " << fileName << " Folder: " << directory << std::endl;
        cli.showMenu(fileName, directory);
    }
	return 0;
}

#ifdef MAIN

using namespace std;

int main()
{

}
#endif

