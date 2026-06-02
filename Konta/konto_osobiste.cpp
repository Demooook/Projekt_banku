#include "konto_osobiste.h"
#include <iostream>

void KontoOsobiste::wyswietlInfo()
{
   std::cout<<"["<<getNumer()<<"]"<<"Konto Osobiste| saldo: "<<getSaldo()<<"\n";
}

KontoOsobiste::KontoOsobiste(std::string pom_numer) : Konto(pom_numer)
{
    
}