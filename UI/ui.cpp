#include <iostream>

#include "ui.h"
#include "../Uzytkownicy/klient.h"


void Ui::start()
{
int opcja=0,temp_id_uzytkownika=0;


czyscEkran();
std::cout<<"Witamy w banku [Golden Fountain]"<<"\n";
while(wyjscie==false)
{
std::cout<<"Zaloguj się (1) | Utworz nowe konto (2) | Wyjscie (3)"<<"\n";
std::cin>>opcja;
    if(opcja==1) //opcja 1 zaloguj się
    {
        menuLogowania();
        wyjscie=true;
    }
    else if(opcja==2) //opcja 2 rejestracja
    {
        menuRejestracji();
        
    }
    else if(opcja==3) //wyjscie
    {
        czyscEkran();
        std::cout<<"Do widzenia!"<<"\n";
        wyjscie=true;
    }
    else //zabezpieczenie inputu
    {
        czyscEkran();
        std::cout<<"Nieprawidłowa opcja"<<"\n";
    }
        
}
}

void Ui::menuLogowania()
{
    std::string wpisany_login,wpisany_haslo,
    czyscEkran();

        std::cout<<"Proszę się zalogować:"<<"\n";
        std::cout<<"Login:"<<"\n";
        std::cin>>wpisany_login;
        std::cout<<"Haslo:"<<"\n";
        std::cin>>wpisany_haslo;

        if(silnikSystemu.Logowanie(wpisany_login, wpisany_haslo) == true)
        {
            wyjscie=true;
            //wtedy wyswietlamy menu glowne
        }
        else
            std::cout<<"Placeholder";
            //nie wyswietlamy

        
}

void Ui::menuRejestracji()
{
    std::string wpisany_login,wpisany_haslo, temp_imie,temp_nazwisko,temp_pesel;
    czyscEkran();
        std::cout<<"Aby utworzyc twoje konto potrzebujemy ponizszych informacji:"<<"\n";
        std::cout<<"Login:";
        std::cin>>wpisany_login;
        std::cout<<"Haslo:";
        std::cin>>wpisany_haslo;
        std::cout<<"Imie: ";
        std::cin>>temp_imie;
        std::cout<<"Nazwisko: ";
        std::cin>>temp_nazwisko;
        std::cout<<"Pesel: ";
        std::cin>>temp_pesel;

        silnikSystemu.utworzKonto(wpisany_login, wpisany_haslo, temp_imie, temp_nazwisko, temp_pesel);

    czyscEkran();
    std::cout<<"Pomyślnie utworzono konto. Proszę się zalogować."<<"\n";

}

void Ui::czyscEkran()
{
    std::cout << "\033[2J\033[3J\033[1;1H";
}