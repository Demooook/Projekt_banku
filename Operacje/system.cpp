#include "system.h"
#include "../Uzytkownicy/klient.h"
#include "../Konta/konto_osobiste.h"
#include "../Konta/konto_kredytowe.h"
#include "../Konta/konto_oszczednosciowe.h"
#include "../Operacje/transakcje.h"
#include <memory>
#include <iostream>

void System::utworzKonto(std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
{
    Klient nowy_klient(nastepne_id, temp_login, temp_haslo, temp_imie, temp_nazwisko, temp_pesel);

    Klient* nowa_lista = new Klient[liczba_klientow + 1];
    
    for (int i = 0; i < liczba_klientow; i++) 
    {
        nowa_lista[i] = std::move(listaKlientow[i]); 
    }
    
    nowa_lista[liczba_klientow] = std::move(nowy_klient);
    
    delete[] listaKlientow;
    listaKlientow = nowa_lista;
    liczba_klientow++;

    nastepne_id++;
}

bool System::Logowanie(std::string wpisany_login, std::string wpisany_haslo)
{
    for (int i = 0; i < liczba_klientow; i++)
    {
        std::string login_baza = listaKlientow[i].getLogin();
        std::string haslo_baza = listaKlientow[i].getHaslo();

        if (wpisany_login == login_baza && wpisany_haslo == haslo_baza)
        {
            zalogowany_login = wpisany_login;
            id_logowania = i;
            return true;
        }
    }
    return false;
}
bool System::stworzTypKonta(int wybrana_opcja)
{
    int ileKont = 0;
    for (int i=0;i<liczba_klientow;i++)
    {
        ileKont+=listaKlientow[i].getIleKont();
    }
    std::string temp_numer_konta= "PL" + std::to_string(ileKont);

    if (wybrana_opcja == 1) // osobiste
    {
        auto nowe_konto = std::make_unique<KontoOsobiste>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));

        return true;
    }
    else if (wybrana_opcja == 2) // kredytowe
    {
        auto nowe_konto = std::make_unique<KontoKredytowe>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));
        
        return true;
    }
    else if (wybrana_opcja == 3) // oszczednosciowe
    {
        auto nowe_konto = std::make_unique<KontoOszczednosciowe>(temp_numer_konta);

        listaKlientow[id_logowania].dodajKonto(std::move(nowe_konto));

        return true;
    }

    return false;
}

bool System::usunTypKonta(std::string wybrany_nr_konta)
{
    std::string porownanie_nr= "PL"+ wybrany_nr_konta;
    for (int i=0; i<listaKlientow[id_logowania].getIleKont();i++)
    {
        if(porownanie_nr==listaKlientow[id_logowania].getNumerKonta(i))
        {
            listaKlientow[id_logowania].usunKonto(i);

            return true;
        }

    }
    return false;
}
void System::usunCaleKonto()
{
    if (liczba_klientow <= 0 || id_logowania < 0) return;

   
    Klient* nowa_lista = new Klient[liczba_klientow - 1];
    int index_nowej = 0;

   
    for (int i = 0; i < liczba_klientow; i++) 
    {
        if (i != id_logowania) 
        {
            nowa_lista[index_nowej] = std::move(listaKlientow[i]);
            index_nowej++;
        }
    }

    delete[] listaKlientow;
    listaKlientow = nowa_lista;
    liczba_klientow--; 

    id_logowania = -1;
}

void System::wyswietlKonta()
{
    listaKlientow[id_logowania].wyswietlInfoKont();
}

void System::setIdLogowania(int wpisane_id)
{
    id_logowania=wpisane_id;
}

bool System::systemWplac(double kwota, std::string podany_numer_konta)
{
    if(listaKlientow[id_logowania].wplacNaKonto(kwota,podany_numer_konta)==true)
        return true;
    else 
        return false;
}
bool System::systemWyplac(double kwota, std::string podany_numer_konta)
{
    if(listaKlientow[id_logowania].wyplacZKonta(kwota,podany_numer_konta)==true)
        return true;
    else
        return false;
}

bool System::systemPrzelew(std::string podany_numer_wlasnego_konta,double kwota, std::string podany_numer_konta)
{
    bool znaleziono_nadawce;
    int id_odbiorcy=-1;
    if (kwota<=0)
        return false;

    for (int i=0; i<listaKlientow[id_logowania].getIleKont();i++) //sprawdzanie wlasnych kont 
    {
        if(listaKlientow[id_logowania].getNumerKonta(i)==podany_numer_wlasnego_konta) // sprawdzenie czy zgadza sie nasze podane konto
        {
            znaleziono_nadawce=true;
           break;
        }
    }
    
    if(znaleziono_nadawce==false) 
        return false;

    for (int i=0;i<liczba_klientow;i++) //przeszukanie kazdego klienta
    {
        for(int j=0;j<listaKlientow[i].getIleKont();j++) //przeszukanie kazdego konta
        {
            if(listaKlientow[i].getNumerKonta(j)==podany_numer_konta)
            {
                id_odbiorcy=i;
                break;
            }
        }
        if(id_odbiorcy!=-1) break;
    }

    if(listaKlientow[id_logowania].wyplacZKonta(kwota,podany_numer_wlasnego_konta)==true)
    {
        listaKlientow[id_odbiorcy].wplacNaKonto(kwota,podany_numer_konta);
        Transakcja tOdbiorca(kwota, "05-2026", podany_numer_konta, "Przelew wychodzacy");
        listaKlientow[id_odbiorcy].przekazTransakcje(podany_numer_wlasnego_konta,tOdbiorca);
        Transakcja tNadawca(-kwota, "05-2026", podany_numer_wlasnego_konta, "Przelew przychodzacy");
        listaKlientow[id_odbiorcy].przekazTransakcje(podany_numer_wlasnego_konta,tNadawca);
        return true;
    }
    return false;

}
void System::systemWyswietlTransakcje(std::string podany_numer_konta)
{
    listaKlientow[id_logowania].wyswietlHistorieKlient(podany_numer_konta);
}

void System::ADMINWyswietlKonta(){
    std::cout<<"Aktualna ilosc kont: ["<<liczba_klientow<<"]\n";
    for(int i=0;i<liczba_klientow;i++)
    {
        listaKlientow[i].wyswietlInfoKont();
    }
}

void System::ADMINWyswietlHistorie(){
    int liczba_kont=0;
    std::string temp_nr_konta;
        for(int i=0;i<liczba_klientow;i++)
        {
            liczba_kont+=listaKlientow[i].getIleKont();
        }
        for(int i=0;i<liczba_kont;i++)
        {
            temp_nr_konta="PL"+std::to_string(i);
            for(int j=0;j<liczba_klientow;j++)
            {
                listaKlientow[j].wyswietlHistorieKlient(temp_nr_konta);
            }
        }
        
}

void System::ADMINRaport(){
    double kapital=0.0;
    int liczba_kont=0;

    for(int i=0;i<liczba_klientow;i++)
    {
        liczba_kont+=listaKlientow[i].getIleKont();
        kapital+=listaKlientow[i].getKapitalKlient();
    }

    std::cout<<"RAPORT PODSUMOWUJACY: \n";
    std::cout<<"Aktualna liczba klientow: "<<liczba_klientow<<"\n";
    std::cout<<"Aktualna liczba aktywnych kont: "<<liczba_kont<<"\n";
    std::cout<<"Laczny kapital w banku: "<<kapital<<"\n";
}

void System::zapisBazy()
{

}
void System::wczytBazy()
{
    
}