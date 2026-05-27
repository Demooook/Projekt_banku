#include "system.h"
#include "../Uzytkownicy/klient.h"
#include "../Konta/konto_osobiste.h"
#include "../Konta/konto_kredytowe.h"
#include "../Konta/konto_oszczednosciowe.h"
#include <memory>
#include <iostream>

void System::utworzKonto(std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
{
    Klient nowy_klient(nastepne_id, temp_login, temp_haslo, temp_imie, temp_nazwisko, temp_pesel);

    listaKlientow.push_back(nowy_klient);

    nastepne_id++;
}

bool System::Logowanie(std::string wpisany_login, std::string wpisany_haslo)
{
    for (int i = 0; i < listaKlientow.size(); i++)
    {
        std::string login_baza = listaKlientow[i].getLogin();
        std::string haslo_baza = listaKlientow[i].getHaslo();

        if (wpisany_login == login_baza && wpisany_haslo == haslo_baza)
        {
            zalogowany_login = wpisany_login;
            id_logowania = i;
            return true;
        }
        else
            return false;
    }
}
void System::stworzTypKonta(int wybrana_opcja)
{
    if (wybrana_opcja == 1) // osobiste
    {
        auto nowe_konto = std::make_unique<KontoOsobiste>();

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));
    }
    else if (wybrana_opcja == 2) // kredytowe
    {
        auto nowe_konto = std::make_unique<KontoKredytowe>();

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));
    }
    else if (wybrana_opcja == 3) // oszczednosciowe
    {
        auto nowe_konto = std::make_unique<KontoOszczednosciowe>();

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));
    }
}