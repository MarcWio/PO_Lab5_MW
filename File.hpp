#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

#include <string>

#include <sys/stat.h>

#include "json.hpp"
#include "direct.h"

class File {
private:
    std::string NazwaPliku;
    std::string lokalizacja;
    std::string sciezka;

    bool PlikJuzStworzony();

    bool LokalizacjaJuzStworzona();

    bool StworzLokalizacjeJesliNieMa();

    void StworzPlikJesliNieMa();

    void JesliJjNadpisz();

    nlohmann::json loadFromFile(std::string NazwaPliku, std::string lokalizacja);
public:   
    File() {};

    File(const std::string& _NazwaPliku, const std::string& _lokalizacja);

    void setFileNameDirectoryPath(const std::string& _NazwaPliku, const std::string& _lokalizacja);

    void createJsonFileConfig(const nlohmann::json& _konfiguruj);

    nlohmann::json loadJsonFileConfig();

    nlohmann::json loadJsonFileConfig(const File& file);
};

#endif
