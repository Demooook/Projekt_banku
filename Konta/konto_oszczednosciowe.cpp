#include "konto_oszczednosciowe.h"
#include <iostream>


void naliczOdsetki(double saldo)
{
    
}

void KontoOszczednosciowe::wyswietlInfo()
{
    std::cout<<"["<<getNumer()<<"]"<<"Konto Oszczednosciowe | saldo: "<<getSaldo()<<"\n";
}

KontoOszczednosciowe::KontoOszczednosciowe(std::string pom_numer) : Konto(pom_numer)
{
    
}

bool KontoOszczednosciowe::wyplac(double kwota) 
{
    double oplata = 5.0;

    if(kwota > 0 && getSaldo() >= (kwota + oplata))
    {
        zmienSaldo(-(kwota + oplata));
        return true;
    }
    std::cout << "Blad: Brak srodkow na wyplate i prowizje (5 PLN)!\n";
    return false;
}

void KontoOszczednosciowe::naliczOdsetki()
{
    if (getSaldo() > 0)
    {
        double zarobek = getSaldo() * 0.05;
        zmienSaldo(zarobek);
        
        Transakcja t(zarobek, "05-2026", "Bank", "Naliczenie odsetek 5%");
        dodajTransakcje(t);
        
        std::cout << "Naliczono " << zarobek << " PLN odsetek!\n";
    }
}