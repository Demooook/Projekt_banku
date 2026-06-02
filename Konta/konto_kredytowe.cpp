#include "konto_kredytowe.h"
#include <iostream>

void KontoKredytowe::wyswietlInfo()
{
    std::cout<<"["<<getNumer()<<"]"<<"Konto Kredytowe | saldo: "<<getSaldo()<<"\n";
}

KontoKredytowe::KontoKredytowe(std::string pom_numer) : Konto(pom_numer)
{
    
}