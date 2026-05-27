#include "klient.h"
#include "uzytkownik.h"

void Klient::dodajKonto(std::unique_ptr<Konto> nowe_konto) 
{
    lista_kont.push_back(std::move(nowe_konto));
}