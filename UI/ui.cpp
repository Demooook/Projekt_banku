#include <iostream>

#include "ui.h"
#include "../Uzytkownicy/klient.h"


void Ui::start()
{
int opcja=0,temp_id_uzytkownika=0;


czyscEkran();
std::cout<<"Witamy w banku [Golden Fountain]\n";
while(wyjscie==false)
{
std::cout<<"Zaloguj się (1) | Utworz nowe konto (2) | Wyjscie (3)\n";
std::cin>>opcja;
    if(opcja==1) //opcja 1 zaloguj się
    {
        czyscEkran();
        menuLogowania();
        
    }
    else if(opcja==2) //opcja 2 rejestracja
    {
        menuRejestracji();
        
    }
    else if(opcja==3) //wyjscie
    {
        czyscEkran();
        std::cout<<"Do widzenia!\n";
        wyjscie=true;
    }
    else //zabezpieczenie inputu
    {
        czyscEkran();
        std::cout<<"Nieprawidłowa opcja\n";
    }
        
}
}

void Ui::menuLogowania()
{
        std::string wpisany_login,wpisany_haslo;

        std::cout<<"Proszę się zalogować:\n";
        std::cout<<"Login:"<<"\n";
        std::cin>>wpisany_login;
        std::cout<<"Haslo:"<<"\n";
        std::cin>>wpisany_haslo;

        if(silnikSystemu.Logowanie(wpisany_login, wpisany_haslo) == true)
        {
            wyjscie=true;
            czyscEkran();
            std::cout<<"Poprawnie zalogowano!\n";
            przerywnik();
            menuGlowne(silnikSystemu.getLogin());
            //wtedy wyswietlamy menu glowne
        }
        else
        {
            std::cout<<"Niepoprawne dane logowania.\n";
            przerywnik();
            //nie wyswietlamy
        }
            

        
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

void Ui::menuGlowne(std::string zalogowany_login)
{
    int opcja;

    while(wyjscie==false)
    {
        std::cout<<"PANEL KLIENTA ["<<zalogowany_login<<"]\n";
        std::cout<<"Aktualne konto :"<<"konto \n";
        std::cout<<"Zarzadzanie moimi kontami (1) | Sprawdz saldo (2) | Wplac/wyplac pieniadze (3) | Przelew (4) | Historia transakcji (5) | Wyloguj się (6) \n";
        std::cin>>opcja;

        switch (opcja)
        {
            default: std::cout<<"Nieprawidlowa opcja \n";
            case 1: //ogolny zarzad kontem - tworzenie usuwanie etc.

            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
        }
          
    }
    
}

void Ui::podmenuZarzadzanie()
{
    int opcja;
    while(wyjscie=false)
    {
        std::cout<<"ZARZADZANIE KONTEM \n";
        std::cout<<"Dodaj nowy typ konta (1) | Usun biezacy typ konta (2) | Zamknij konto (3) \n";
        std::cin>>opcja;
        if(opcja==1)
        {
            std::cout<<"Wybierz typ konta\n";
            std::cout<<"Osobiste (1) | Kredytowe (2) | Oszczednosciowe (3) \n";
            std::cin>>opcja;
            silnikSystemu.stworzTypKonta(opcja);
        }
        else if(opcja==2)
        {

        }
        else if(opcja==3)
        {

        }
    }

        
}

void Ui::czyscEkran()
{
    std::cout << "\033[2J\033[3J\033[1;1H";
}

void Ui::przerywnik()
{
    std::cout<<"------------------------------------\n";
}