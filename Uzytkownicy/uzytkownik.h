#pragma once

#include <string>

class Uzytkownik
{
    private:
        int id_uzytkownika;
        std::string login;
        std::string haslo;
    public:
        Uzytkownik();
        Uzytkownik(int id_uzytkownika, std::string login, std::string haslo);
        void Logowanie(std::string login, std::string haslo);
};