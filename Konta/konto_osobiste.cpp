#include "konto_osobiste.h"
#include <iostream>

void KontoOsobiste::wyswietlInfo()
{
   std::cout<<"["<<getNumer()<<"]"<<"Konto Osobiste| saldo: "<<getSaldo()<<"\n";
}

KontoOsobiste::KontoOsobiste(std::string pom_numer) : Konto(pom_numer)
{
    
}

bool KontoOsobiste::wyplac(double kwota)
{
    // Sprawdzamy czy kwota sensowna i czy mamy na to pokrycie w saldzie
    if (kwota > 0 && getSaldo() >= kwota)
    {
        zmienSaldo(-kwota);
        return true;
    }
    
    std::cout << "Blad: Brak wystarczajacych srodkow na koncie osobistym!\n";
    return false;
}