#include "konto_kredytowe.h"
#include <iostream>

void KontoKredytowe::wyswietlInfo()
{
    std::cout<<"["<<getNumer()<<"]"<<"Konto Kredytowe | saldo: "<<getSaldo()<<"\n";
}

KontoKredytowe::KontoKredytowe(std::string pom_numer) : Konto(pom_numer)
{
    
}

bool KontoKredytowe::wyplac(double kwota)
{
    if(kwota >0 && (getSaldo() + limit_debetu)>=0)
    {
        double temp_saldo=getSaldo();
        temp_saldo-=kwota;
        zmienSaldo(temp_saldo);
        return true;
    }
    return false;
}