#include "konto_kredytowe.h"
#include <iostream>

void KontoKredytowe::wyswietlInfo()
{
    std::cout<<"["<<getNumer()<<"]"<<"Konto Kredytowe | saldo: "<<getSaldo()<<"\n";
}

KontoKredytowe::KontoKredytowe(std::string pom_numer) : Konto(pom_numer)
{
    limit_debetu=1000.0;   
}

bool KontoKredytowe::wyplac(double kwota)
{

    if ((getSaldo() + limit_debetu) >= kwota)
    {
        zmienSaldo(-kwota);
        return true;
    }
    
    std::cout << "Blad: Przekroczono limit kredytowy (maksymalny debet to " << limit_debetu << " PLN)!\n";
    return false;
}