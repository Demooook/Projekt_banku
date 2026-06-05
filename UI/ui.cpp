#include <iostream>

#include "ui.h"
#include "../Uzytkownicy/klient.h"


void Ui::start()
{
int opcja=0,temp_id_uzytkownika=0;
bool wyjscie=false;

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
bool wyjscie=false;
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
bool wyjscie=false;
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
    int opcja=-1, kwota=0;
    bool wyjscie=false;
    std::string podany_nr_konta="",podany_nr_wlasnego_konta="",tytul_przelewu="";
    while(silnikSystemu.getIdLogowania()!=-1)
    {
        wyjscie=false;
        std::cout<<"PANEL KLIENTA ["<<zalogowany_login<<"]\n";
        std::cout<<"Aktualne konto :"<<"Tu bedzie pokazane aktualne konto \n";
        przerywnik();
        std::cout<<"Zarzadzanie moimi kontami (1) | Sprawdz saldo (2) | Wplac/wyplac pieniadze (3) | Przelew (4) | Historia transakcji (5) | Wyloguj się (6) \n";
        std::cin>>opcja;
        switch (opcja)
        {
            default: 
                std::cout<<"Nieprawidlowa opcja \n"; 
            break;
            case 1: //ogolny zarzad kontem - tworzenie usuwanie etc.
                czyscEkran();
                podmenuZarzadzanie(); 
            break; 
            case 2: break;
            case 3: //WPLATY / WYPLATY
                czyscEkran();
                while(wyjscie==false)
                {
                    std::cout<<"Wplata (1) | Wyplata (2) | Wyjscie (3)\n";
                    std::cin>>opcja;
                    switch (opcja)
                    {
                    default:
                        std::cout<<"Nieprawidlowa opcja" ;
                    break;
                    case 1: //WPLATA 
                        std::cout<<"Podaj numer konta do wplaty\n";
                        std::cin>>podany_nr_konta;
                        std::cout<<"Podaj kwotę do wplacenia \n";
                        std::cin>>kwota;
                        if(silnikSystemu.systemWplac(kwota,podany_nr_konta)==true)
                            std::cout<<"Wplacono "<<kwota<<" na konto: "<<podany_nr_konta<<"\n";
                        else
                            std::cout<<"Wplata nie powiodla sie";
                    break;
                    case 2: //WYPLATA
                        std::cout<<"Podaj numer konta z ktorego chcesz wyplacic\n";
                        std::cin>>podany_nr_konta;
                        std::cout<<"Podaj kwotę do wyplaty \n";
                        std::cin>>kwota;
                        if(silnikSystemu.systemWyplac(kwota,podany_nr_konta)==true)
                            std::cout<<"Wyplacono "<<kwota<<"z konta: "<<podany_nr_konta<<"\n";
                        else
                            std::cout<<"Wyplata nie powiodla sie\n";
                    break;
                    case 3: //WYJSCIE
                        wyjscie=true;
                    break;
                    }
                }

            break;
            case 4: //PRZELEWY
                std::cout<<"W celu wykonania przelewu Podaj numer konta z ktorego chcesz przelac\n";
                std::cin>>podany_nr_wlasnego_konta;
                std::cout<<"Nastepnie podaj kwotę\n";
                std::cin>>kwota;
                std::cout<<"Podaj nr konta odbiorcy\n";
                std::cin>>podany_nr_konta;
                if(silnikSystemu.systemPrzelew(podany_nr_wlasnego_konta,kwota,podany_nr_konta)==true)
                    std::cout<<"Przelew powiodl sie\n";
                else
                    std::cout<<"Przelew nie wykonal się!\n";


            break;
            case 5: //HISTORIA TRANSAKCJI
                czyscEkran();
                std::cout<<"Podaj numer konta do wyswietlenia transakcj\n";
                std::cin>>podany_nr_konta;
                std::cout<<"Oto historia transakcji:\n";
                silnikSystemu.systemWyswietlTransakcje(podany_nr_konta);
            break;
            case 6: 
                czyscEkran();
                std::cout<<"Wylogowano\n";
                silnikSystemu.setIdLogowania(-1);
            break; 
        }
}
    
    
}

void Ui::podmenuZarzadzanie() //MENU ZARZADZANIA KONTEM 
{
    bool wyjscie=false;
    int opcja;
    std::string wpisany_nr_konta;
    while(wyjscie==false)
    {
        std::cout<<"ZARZADZANIE KONTEM \n";
        std::cout<<"Dodaj nowy typ konta (1) | Usun biezacy typ konta (2) | Wyswietl posiadane konta (3) | Zamknij konto (4) | Wyjscie (5) \n";
        std::cin>>opcja;
        switch(opcja){
        default: 
            std::cout<<"Nieprawidlowa opcja\n";
        break;
        case 1: //DODAJ NOWY TYP KONTA
            std::cout<<"Wybierz typ konta\n";
            std::cout<<"Osobiste (1) | Kredytowe (2) | Oszczednosciowe (3) \n";
            std::cin>>opcja;
            if(silnikSystemu.stworzTypKonta(opcja)==true)
            {
                czyscEkran();
                std::cout<<"Pomyslnie utworzono konto\n";
                wyjscie=true;
            }
        break;
        case 2: //USUN TYP KONTA
            czyscEkran();
            silnikSystemu.wyswietlKonta();
            std::cout<<"Wybierz konto do usunięcia: \n";
            std::cin>>wpisany_nr_konta;
            if (silnikSystemu.usunTypKonta(wpisany_nr_konta) == true)
                std::cout<<"Poprawnie usunięto konto o numerze: PL"<<wpisany_nr_konta<<"\n";
            else
                std::cout<<"Niepoprawny nr konta\n";
        break;
        case 3: //WYSWIETL KONTA
            czyscEkran();
            silnikSystemu.wyswietlKonta();
        break;
        case 4: //USUN CALE KONTO
            czyscEkran();
            silnikSystemu.usunCaleKonto();
            std::cout<<"Usunieto cale konto \n";
            wyjscie=true;
        break;
        case 5: 
            wyjscie=true; 
        break;

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