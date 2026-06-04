#pragma once

#include "uzytkownik.h"
#include "../Konta/konto.h"

#include <string>
#include <vector>
#include <memory>

class Klient : public Uzytkownik
{
    private:
        std::vector <std::unique_ptr<Konto>> lista_kont;
        std::string imie;
        std::string nazwisko;
        std::string pesel;
    public:
        void wyswietlHistorie();
        void zrobPrzelew(int nr_konta);
        Klient(int temp_id_uzytkownika, std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
        : Uzytkownik (temp_id_uzytkownika,temp_login, temp_haslo)
        {
            imie=temp_imie;
            nazwisko=temp_nazwisko;
            pesel=temp_pesel;
        };
        void dodajKonto(std::unique_ptr<Konto> nowe_konto);
        void usunKonto(int pom_indeks);
        void wyswietlInfoKont();
        bool wplacNaKonto(double kwota, std::string numer_konta);
        bool wyplacZKonta(double kwota, std::string numer_konta);
        int getIleKont(){return lista_kont.size();}
        std::string getNumerKonta(int pom_indeks);

};