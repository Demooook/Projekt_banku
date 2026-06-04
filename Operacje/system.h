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
        void usunCaleKonto();
        void wyswietlKonta();
        std::string getLogin() {return zalogowany_login; }
        int getIdLogowania() {return id_logowania;}
        void setIdLogowania(int wpisane_id);
        bool systemWplac(double kwota, std::string podany_numer_konta);
        bool systemWyplac(double kwota, std::string podany_numer_konta);
        void systemPrzelew(std::string podany_numer_wlasnego_konta, double kwota, std::string podany_numer_konta);
};