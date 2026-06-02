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