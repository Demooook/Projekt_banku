#include "klient.h"
#include "uzytkownik.h"
#include "../Operacje/system.h"
#include "../Konta/konto.h"
#include "../Operacje/transakcje.h"

#include <iostream>

Klient::Klient()
{
    imie = "";
    nazwisko = "";
    pesel = "";
}

void Klient::dodajKonto(std::unique_ptr<Konto> nowe_konto) 
{
    lista_kont.push_back(std::move(nowe_konto));
}

void Klient::wyswietlInfoKont()
{
    std::cout<<"Posiadane konta uzytkownika: "<< imie<<" "<<nazwisko<<"\n";
    if (lista_kont.size()==0)
    {
        std::cout<<"Brak kont\n";
    }
    for (int i=0; i<lista_kont.size();i++)
    {
        lista_kont[i]->wyswietlInfo();
    }
}

void Klient::usunKonto(int pom_indeks)
{
    lista_kont.erase(lista_kont.begin()+pom_indeks);
}

std::string Klient::getNumerKonta(int pom_indeks)
{
   return lista_kont[pom_indeks]->getNumer();
}

bool Klient::wplacNaKonto(double kwota, std::string numer_konta, std::string zrodlo, std::string opis)
{
    for (int i=0; i<lista_kont.size(); i++)
    {
        if(*lista_kont[i] == numer_konta)
        {
            lista_kont[i]->wplac(kwota);
            Transakcja t(kwota, "05-2026", zrodlo, opis); 
            lista_kont[i]->dodajTransakcje(t);
            return true;
        }  
    }
    return false;
}

bool Klient::wyplacZKonta(double kwota, std::string numer_konta, std::string cel, std::string opis)
{
    for (int i=0; i<lista_kont.size(); i++)
    {
        if(*lista_kont[i] == numer_konta)
        {
            if (lista_kont[i]->wyplac(kwota) == true) 
            {
                Transakcja t(kwota, "05-2026", cel, opis); 
                lista_kont[i]->dodajTransakcje(t);
                return true; 
            }
            else 
            {
                return false; 
            }
        }
    }
    return false;
}

void Klient::przekazTransakcje(std::string podany_numer_konta, Transakcja t)
{
    for(int i=0;i<getIleKont();i++)
    {
        if(*lista_kont[i] == podany_numer_konta)
        {
            lista_kont[i]->dodajTransakcje(t);
        }
    }
    
}
void Klient::wyswietlHistorieKlient(std::string podany_numer_konta)
{
    bool znaleziono_konto = false;

    for(int i = 0; i < lista_kont.size(); i++)
    {
        if(*lista_kont[i] == podany_numer_konta)
        {
            lista_kont[i]->wyswietlHistorieKonto();
            znaleziono_konto = true;
            break; 
        }
    }
    if(znaleziono_konto == false)
    {
        std::cout << "Nieprawidlowy numer konta.\n";
    }  
}
double Klient::getKapitalKlient()
{
    double suma=0.0;
    for (int i=0;i<lista_kont.size();i++)
    {
        suma+=lista_kont[i]->getSaldo();
    }
    return suma;
}

void Klient::symulujMiesiac()
{
    for (int i = 0; i < lista_kont.size(); i++)
    {
        lista_kont[i]->naliczOdsetki();
    }
}