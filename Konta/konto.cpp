#include <iostream>
#include <vector>
#include <string>

#include "konto.h"

Konto::Konto() {numer_konta=0; saldo=0.0;}
Konto::Konto(int pom_numer_konta, double pom_saldo, std::vector<int> pom_historia)
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
    std::cout<<"Konto standardowe | saldo: "<<saldo<<"\n";
}