#include "system.h"


void System::utworzKonto(std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
{
Klient nowy_klient(nastepne_id,temp_login,temp_haslo,temp_imie,temp_nazwisko,temp_pesel);

listaKlientow.push_back(nowy_klient);

nastepne_id++;
}

void System::Logowanie(std::string login, std::string haslo)
{
    for (int i=0;i<=listaKlientow.size();i++)
    {
    }
}