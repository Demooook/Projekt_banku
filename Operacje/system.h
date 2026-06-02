#pragma once

#include "../Uzytkownicy/klient.h"
#include <string>
#include <vector>

class System
{
    private:
        std::vector<Klient> listaKlientow;
        int nastepne_id=0;
        int id_logowania;
        std::string zalogowany_login;
    public:
        void utworzKonto(std::string temp_login,std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel);
        bool Logowanie(std::string wpisany_login, std::string wpisany_haslo);
        bool stworzTypKonta(int wybrana_opcja);
        bool usunTypKonta(std::string wybrany_nr_konta);
        void wyswietlKonta();
        std::string getLogin() {return zalogowany_login; }

};