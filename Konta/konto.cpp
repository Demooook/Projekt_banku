#include <iostream>
#include <vector>
#include <string>

#include "konto.h"

Konto::Konto(std::string pom_numer_konta) {numer_konta=pom_numer_konta; saldo=0.0;}
Konto::Konto(std::string pom_numer_konta, double pom_saldo, std::vector<int> pom_historia)
{
    numer_konta=pom_numer_konta;
    saldo=pom_saldo;
    historia=pom_historia;
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
    if(kwota>0)
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