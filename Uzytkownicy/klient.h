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
        void utworzKonto();
        void wyswietlHistorie(std::vector <std::string> lista_kont);
        void zrobPrzelew(int nr_konta);
    
};