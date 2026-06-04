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

    listaKlientow.push_back(std::move(nowy_klient));

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
    return 0;
}
bool System::stworzTypKonta(int wybrana_opcja)
{
    int ileKont = listaKlientow[id_logowania].getIleKont();
    std::string temp_numer_konta= "PL" + std::to_string(ileKont);

    if (wybrana_opcja == 1) // osobiste
    {
        auto nowe_konto = std::make_unique<KontoOsobiste>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));

        return true;
    }
    else if (wybrana_opcja == 2) // kredytowe
    {
        auto nowe_konto = std::make_unique<KontoKredytowe>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));
        
        return true;
    }
    else if (wybrana_opcja == 3) // oszczednosciowe
    {
        auto nowe_konto = std::make_unique<KontoOszczednosciowe>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));

        return true;
    }

    return false;
}

bool System::usunTypKonta(std::string wybrany_nr_konta)
{
    std::string porownanie_nr= "PL"+ wybrany_nr_konta;
    for (int i=0; i<listaKlientow[id_logowania].getIleKont();i++)
    {
        if(porownanie_nr==listaKlientow[id_logowania].getNumerKonta(i))
        {
            listaKlientow[id_logowania].usunKonto(i);

            return true;
        }

    }
    return false;
}
void System::usunCaleKonto()
{
    listaKlientow.erase(listaKlientow.begin()+id_logowania);
    id_logowania=-1;
}

void System::wyswietlKonta()
{
    listaKlientow[id_logowania].wyswietlInfoKont();
}

void System::setIdLogowania(int wpisane_id)
{
    id_logowania=wpisane_id;
}

bool System::systemWplac(double kwota, std::string podany_numer_konta)
{
    if(listaKlientow[id_logowania].wplacNaKonto(kwota,podany_numer_konta)==true)
        return true;
    else 
        return false;
}
bool System::systemWyplac(double kwota, std::string podany_numer_konta)
{
    if(listaKlientow[id_logowania].wyplacZKonta(kwota,podany_numer_konta)==true)
        return true;
    else
        return false;
}

void System::systemPrzelew(std::string podany_numer_wlasnego_konta,double kwota, std::string podany_numer_konta)
{
    for (int i=0; i<listaKlientow[id_logowania].getIleKont();i++)
    {
        if(listaKlientow[id_logowania].lista_kont[i]->getNumer()==podany_numer_wlasnego_konta)
    }
        
}