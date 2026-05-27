#include "klient.h"
#include "uzytkownik.h"
#include "../Operacje/system.h"
#include "../Konta/konto.h"

#include <iostream>

void Klient::dodajKonto(std::unique_ptr<Konto> nowe_konto) 
{
    lista_kont.push_back(std::move(nowe_konto));
}

void Klient::wyswietlInfo()
{
    std::cout<<"Posiadane konta: \n";
    for (int i=0; i<lista_kont.size();i++)
    {
        std::cout<<lista_kont[i]<<"| saldo:"<<lista_kont[i]->getSaldo();
    }
}