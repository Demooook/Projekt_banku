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
    double oplata=5.0;
    if(kwota>0 && (getSaldo()+oplata)>0)
    {
        double temp_saldo=getSaldo();
        temp_saldo-=kwota+oplata;
        zmienSaldo(-temp_saldo);
        return true;
    }
    return false;
}