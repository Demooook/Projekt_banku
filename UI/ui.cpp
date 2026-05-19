#include <iostream>

#include "ui.h"
#include "../Uzytkownicy/klient.h"


void Ui::start()
{
int opcja=0,temp_id_uzytkownika=0;
bool wyjscie=true;
std::string temp_login,temp_haslo,temp_imie,temp_nazwisko,temp_pesel;

czyscEkran();
std::cout<<"Witamy w banku [Golden Fountain]"<<"\n";
while(wyjscie==true)
{
std::cout<<"Zaloguj się (1) | Utworz nowe konto (2)"<<"\n";
std::cin>>opcja;
    if(opcja==1)
    {
        wyjscie=false;
        czyscEkran();
        std::cout<<"Proszę się zalogować:"<<"\n";
        std::cout<<"Login:"<<"\n";
        std::cin>>temp_login;
        std::cout<<"Haslo:"<<"\n";
        std::cin>>temp_haslo;
        //Logowanie();

    }
    else if(opcja==2)
    {
        czyscEkran();
        std::cout<<"Aby utworzyc twoje konto potrzebujemy ponizszych informacji:"<<"\n";
        std::cout<<"Login:";
        std::cin>>temp_login;
        std::cout<<"Haslo:";
        std::cin>>temp_haslo;
        std::cout<<"Imie: ";
        std::cin>>temp_imie;
        std::cout<<"Nazwisko: ";
        std::cin>>temp_nazwisko;
        std::cout<<"Pesel: ";
        std::cin>>temp_pesel;

        silnikSystemu.utworzKonto(temp_login, temp_haslo, temp_imie, temp_nazwisko, temp_pesel);

        czyscEkran();
        std::cout<<"Pomyślnie utworzono konto. Proszę się zalogować."<<"\n";

    }
    else
    {
        czyscEkran();
        std::cout<<"Nieprawidłowa opcja"<<"\n";
    }
        
}


    switch(opcja)
    {
        default : 
        case 1:
        case 2:
        case 3:
        case 4:
    }

}

void Ui::czyscEkran()
{
    std::cout << "\033[2J\033[3J\033[1;1H";
}