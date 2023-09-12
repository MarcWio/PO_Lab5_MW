#include "File.hpp"
void File::createJsonFileConfig(const nlohmann::json& _konfiguruj)
{
    StworzPlikJesliNieMa();
    std::ofstream file(sciezka);
    if (file.is_open()) {
        file << _konfiguruj.dump(4);
        file.close();
        std::cout << "\nPlik zapisany" << std::endl;
    }
    else {
        std::cerr << "\nBlad przy zapisie" << std::endl;
    }
}
nlohmann::json File::loadJsonFileConfig()
{
	return this->loadFromFile(this->NazwaPliku, this->lokalizacja);
}
nlohmann::json File::loadJsonFileConfig(const File& file)
{
	return this->loadFromFile(file.NazwaPliku, file.lokalizacja);
}
bool File::PlikJuzStworzony()
{
    std::ifstream file(sciezka);
    return file.good();
}
bool File::LokalizacjaJuzStworzona()
{
    struct stat info;
    if (stat(lokalizacja.c_str(), &info) != 0) {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
}
bool File::StworzLokalizacjeJesliNieMa()
{
    int result = _mkdir(lokalizacja.c_str());
    return result == 0;
}
void File::StworzPlikJesliNieMa()
{
    if (!LokalizacjaJuzStworzona()) {
        std::cout << "\nFolder o nazwie ->'" << lokalizacja << "' nie istnieje. Stworzyc go teraz? (T-TAK/N-NIE): ";
        char choice;
        std::cin >> choice;

        if (choice == 'T' || choice == 't') {
            if (!StworzLokalizacjeJesliNieMa()) {
                std::cerr << "\nTworzenie folder nie powiodlo sie!"<< std::endl;
            }
            std::cout << "\nUtworzono folder: " << sciezka << std::endl;
        }
        else {
            exit(0);
        }
    }

    if (PlikJuzStworzony()) {
        JesliJjNadpisz();
    }
    else {
        std::ofstream file(sciezka);
        if (file.is_open()) {
            file.close();
            std::cout << "\nUtworzono plik: " << NazwaPliku << std::endl;
        }
        else {
            std::cerr << "\nTworzenie pliku nie powidlo sie!" << sciezka << std::endl;
            exit(0);
        }
    }
}
void File::JesliJjNadpisz()
{
    std::cout << "File '" << sciezka << "' juz istnieje. Czy chcesz go nadpisac? (T/N): ";
    char choice;
    std::cin >> choice;
    if (choice == 'T' || choice == 't') {
        std::ofstream file(sciezka);
        if (file.is_open()) {
            file.close();
            std::cout << "\nPlik zostal nadpisany: " << NazwaPliku << std::endl;
        }
        else {
            std::cerr << "\nWystapil blad podczas tworzenia pliku!" << sciezka << std::endl;
        }
    }
    else {
        exit(0);
    }
}
File::File(const std::string& _NazwaPliku, const std::string& _lokalizacja)
{
    setFileNameDirectoryPath(_NazwaPliku, _lokalizacja);
}
void File::setFileNameDirectoryPath(const std::string& _NazwaPliku, const std::string& _lokalizacja) 
{
    NazwaPliku = _NazwaPliku;
    lokalizacja = _lokalizacja;
    sciezka = _lokalizacja + "/" + _NazwaPliku;
}
nlohmann::json File::loadFromFile(std::string _NazwaPliku, std::string _lokalizacja)
{
    std::string sciezka = _lokalizacja + "/" + _NazwaPliku;
    std::cout << "\nSciezka: " << sciezka << "\n";
    std::ifstream file(sciezka);
    try {
        if (file.is_open()) {
            nlohmann::json data;
            file >> data;
            file.close();
            return data;
        }
        else {
            std::cerr << "\nOtwarcie pliku nie powiodlo sie!" << std::endl;
        }
    }
    catch (...) {
        std::cerr << "\nOtwarcie pliku nie powiodlo sie!" << std::endl;
        exit(1);
    }
}
