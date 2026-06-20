#include <iostream>
#include <vector>
#include <string>

#include "konto.h"

Konto::Konto(std::string pom_numer_konta) {numer_konta=pom_numer_konta; saldo=0.0; historia=nullptr; liczba_transakcji=0;}
Konto::Konto(std::string pom_numer_konta, double pom_saldo, Transakcja *pom_historia, int pom_liczba_transakcji)
{
    numer_konta=pom_numer_konta;
    saldo=pom_saldo;
    liczba_transakcji=pom_liczba_transakcji;
    if (liczba_transakcji > 0 && pom_historia != nullptr) 
    {
        historia = new Transakcja[liczba_transakcji]; 
        for (int i = 0; i < liczba_transakcji; i++) 
        {
            historia[i] = pom_historia[i];
        }
    } 
    else 
    {
        historia = nullptr; 
    }
}

bool Konto::wplac(double kwota)
{
    if(kwota>0)
    {
        saldo+=kwota;
        return true;
    }

    return false;
        
}
bool Konto::wyplac(double kwota)
{
    if(kwota>0 && getSaldo()>0)
    {
        saldo-=kwota;
        return true;
    }
    return false;
        
}
void Konto::wyswietlInfo() 
{
    std::cout<<"["<<numer_konta<<"]"<<"Konto standardowe | saldo: "<<saldo<<"\n";
}

void Konto::dodajTransakcje(Transakcja t)
{
    Transakcja* nowa_historia = new Transakcja[liczba_transakcji + 1];
        for (int i = 0; i < liczba_transakcji; i++)
        {
            nowa_historia[i] = historia[i];
        }
    nowa_historia[liczba_transakcji] = t;

    delete[] historia;
    historia = nowa_historia;
    liczba_transakcji++;
}
void Konto::wyswietlHistorieKonto()
{
    if(liczba_transakcji==0)
    {
        std::cout<<"Brak historii\n";
    }
    for(int i=0;i<liczba_transakcji;i++)
    {
        std::cout<<historia[i]<<"\n";
    }
}