#include "klient.h"
#include "uzytkownik.h"
#include "../Operacje/system.h"
#include "../Konta/konto.h"

#include <iostream>

void Klient::dodajKonto(std::unique_ptr<Konto> nowe_konto) 
{
    lista_kont.push_back(std::move(nowe_konto));
}

void Klient::wyswietlInfoKont()
{
    std::cout<<"Posiadane konta: \n";
    for (int i=0; i<lista_kont.size();i++)
    {
        lista_kont[i]->wyswietlInfo();
    }
}

void Klient::usunKonto(int pom_indeks)
{
    lista_kont.erase(lista_kont.begin()+pom_indeks);
}

std::string Klient::getNumerKonta(int pom_indeks)
{
   return lista_kont[pom_indeks]->getNumer();
}