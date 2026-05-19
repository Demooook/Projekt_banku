#include "system.h"
#include <iostream>

void System::utworzKonto(std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
{
Klient nowy_klient(nastepne_id,temp_login,temp_haslo,temp_imie,temp_nazwisko,temp_pesel);

listaKlientow.push_back(nowy_klient);

nastepne_id++;
}

bool System::Logowanie(std::string wpisany_login, std::string wpisany_haslo)
{
    for (int i=0;i<=listaKlientow.size();i++)
    {
        std::string login_baza=listaKlientow[i].getLogin();
        std::string haslo_baza=listaKlientow[i].getHaslo();

        if(wpisany_login==login_baza && wpisany_haslo==haslo_baza)
        {
            std::cout<<"Wpisales dobrze niech ci bedzie masz dostep"<<"\n";
            return true;
        }
        else
        {
            std::cout<<"Nieprawidlowe dane"<<"\n";
            return false;
        }
    }
}