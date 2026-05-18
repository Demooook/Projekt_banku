#pragma once

#include "uzytkownik.h"

#include <string>
#include <vector>

class Klient : public Uzytkownik
{
    private:
        std::vector <std::string> lista_kont;
        std::string imie;
        std::string nazwisko;
        int pesel;
    public:
        void utworzKonto(int temp_id_uzytkownika,std::string temp_login,std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, int temp_pesel);
        void wyswietlHistorie(std::vector <std::string> lista_kont);
        void zrobPrzelew(int nr_konta);
        Klient(int temp_id_uzytkownika, std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, int temp_pesel)
        : Uzytkownik (temp_id_uzytkownika,temp_login, temp_haslo)
        {
            imie=temp_imie;
            nazwisko=temp_nazwisko;
            pesel=temp_pesel;
        }
};