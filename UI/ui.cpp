#include <iostream>
#include "ui.h"
#include "../Uzytkownicy/klient.h"



void Ui::start()
{
silnikSystemu.wczytBazy();
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
        silnikSystemu.zapisBazy();
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

        if(wpisany_login=="admin" && wpisany_haslo=="admin")     
        {
            wyjscie=true;
            czyscEkran();
            std::cout<<"Poprawnie zalogowano na konto admina\n";
            przerywnik();
            menuAdmina();
        }
        else if(silnikSystemu.Logowanie(wpisany_login, wpisany_haslo) == true)
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
bool wyjscie=false,pesel_ok = false;;

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

    while (!pesel_ok)
    {
        std::cout << "Pesel (dokladnie 11 cyfr): ";
        std::cin >> temp_pesel;

        if (temp_pesel.length() != 11) 
        {
            std::cout << "Blad! PESEL musi miec dokladnie 11 znakow\n";
            continue;
        }

        bool same_cyfry = true;
        for (int i = 0; i < 11; i++) 
        {
            if (temp_pesel[i] < '0' || temp_pesel[i] > '9') 
            {
                same_cyfry = false;
                break;
            }
        }

        if (same_cyfry == true) 
        {
            pesel_ok = true;
        } 
        else 
        {
            std::cout << "Blad! PESEL nie moze zawierac liter ani znakow specjalnych\n";
        }
    }

    bool konto_utworzone = silnikSystemu.utworzKonto(wpisany_login, wpisany_haslo, temp_imie, temp_nazwisko, temp_pesel);

    if(konto_utworzone==false)
    {
        czyscEkran();
        std::cout<<"Tworzenie konta nie powiodlo sie, podane dane sa juz zajete\n";
    }
    else
    {
        czyscEkran();
        std::cout<<"Pomyslnie utworzono konto. Proszę sie zalogowac\n";
    }
     
    

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
        std::cout<<"Zarzadzanie moimi kontami (1) | Wplac/wyplac pieniadze (2) | Przelew (3) | Historia transakcji (4) | Uplyw miesiaca (odsetki) (5) | Wyloguj się (6) \n";
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
            case 2: //WPLATY / WYPLATY
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
                        czyscEkran();
                        silnikSystemu.wyswietlKonta();
                        std::cout<<"Podaj numer konta do wplaty\n";
                        std::cin>>podany_nr_konta;
                        std::cout<<"Podaj kwotę do wplacenia \n";
                        std::cin>>kwota;
                        if(std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::cout<<"Nieprawidlowa kwota\n";
                        }
                        if(silnikSystemu.systemWplac(kwota,podany_nr_konta)==true)
                        {
                            czyscEkran();
                            std::cout<<"Wplacono "<<kwota<<" na konto: "<<podany_nr_konta<<"\n";
                        }    
                        else
                        {
                            czyscEkran();
                            std::cout<<"Wplata nie powiodla sie\n";
                        }
                            
                    break;
                    case 2: //WYPLATA
                        czyscEkran();
                        silnikSystemu.wyswietlKonta();
                        std::cout<<"Podaj numer konta z ktorego chcesz wyplacic\n";
                        std::cin>>podany_nr_konta;
                        std::cout<<"Podaj kwotę do wyplaty \n";
                        std::cin>>kwota;
                        if(std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::cout<<"Nieprawidlowa kwota\n";
                        }
                        if(silnikSystemu.systemWyplac(kwota,podany_nr_konta)==true)
                        {
                            czyscEkran();
                            std::cout<<"Wyplacono "<<kwota<<" z konta: "<<podany_nr_konta<<"\n";
                        }  
                        else
                        {
                            czyscEkran();
                            std::cout<<"Wyplata nie powiodla sie\n";
                        }
                            
                    break;
                    case 3: //WYJSCIE
                        czyscEkran();
                        wyjscie=true;
                    break;
                    }
                }

            break;
            case 3: //PRZELEWY
                std::cout<<"W celu wykonania przelewu Podaj numer konta z ktorego chcesz przelac\n";
                silnikSystemu.wyswietlKonta();
                std::cout<<"Nr:\n";
                std::cin>>podany_nr_wlasnego_konta;
                std::cout<<"Nastepnie podaj kwotę\n";
                std::cin>>kwota;
                std::cout<<"Podaj nr konta odbiorcy\n";
                std::cin>>podany_nr_konta;
                if(silnikSystemu.systemPrzelew(podany_nr_wlasnego_konta,kwota,podany_nr_konta)==true)
                {
                    czyscEkran();
                    std::cout<<"Przelew powiodl sie\n";
                }
                    
                else
                {
                    czyscEkran();
                    std::cout<<"Przelew nie wykonal się!\n";
                }
                 


            break;
            case 4: //HISTORIA TRANSAKCJI
                czyscEkran();
                silnikSystemu.wyswietlKonta();
                std::cout<<"Podaj numer konta do wyswietlenia transakcj\n";
                std::cin>>podany_nr_konta;
                czyscEkran();
                std::cout<<"Oto historia transakcji:\n";
                silnikSystemu.systemWyswietlTransakcje(podany_nr_konta);
                przerywnik();
            break;
            case 5:
                czyscEkran();
                silnikSystemu.symulujOdsetki();
                przerywnik();
            break;
            case 6: 
                czyscEkran();
                std::cout<<"Wylogowano\n";
                przerywnik();
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
            czyscEkran();
            std::cout<<"Wybierz typ konta\n";
            std::cout<<"Osobiste (1) | Kredytowe (2) | Oszczednosciowe (3) | Wyjscie (4)\n";
            std::cin>>opcja;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                czyscEkran();
                std::cout<<"Blednie wybrana opcja\n";
                przerywnik();
            }
            else if (opcja==4)
            {
                wyjscie=true;
                czyscEkran();
                std::cout<<"Anulowano tworzenie konta\n";
            }
            else
            {
                if(silnikSystemu.stworzTypKonta(opcja)==true)
                {
                czyscEkran();
                std::cout<<"Pomyslnie utworzono konto\n";
                wyjscie=true;
                }
                else
                {
                czyscEkran();
                std::cout<<"Nie udalo sie utworzyc konta\n";
                wyjscie=true;
                }
            }
            
        break;
        case 2: //USUN TYP KONTA
            czyscEkran();
            silnikSystemu.wyswietlKonta();
            std::cout<<"Wybierz konto do usunięcia: \n";
            std::cin>>wpisany_nr_konta;
            if (silnikSystemu.usunTypKonta(wpisany_nr_konta) == true)
            {
                czyscEkran();
                std::cout<<"Poprawnie usunięto konto o numerze: "<<wpisany_nr_konta<<"\n";
            }
            else
            {
                czyscEkran();
                std::cout<<"Niepoprawny nr konta\n";
            }
                
        break;
        case 3: //WYSWIETL KONTA
            czyscEkran();
            silnikSystemu.wyswietlKonta();
        break;
        case 4: //USUN CALE KONTO
            czyscEkran();
            std::cout<<"Potwierdz akcje wpisujac 1234 lub cokolwiek innego by anulowac\n";
            std::cin>>opcja;
            if(opcja==1234)
            {
                silnikSystemu.usunCaleKonto();
                czyscEkran();
                std::cout<<"Usunieto cale konto \n";
                wyjscie=true;
            }
            else
            {   
                czyscEkran();
                std::cout<<"Anulowano usuwanie CALEGO konta\n";
                wyjscie=true;
            }
            
        break;
        case 5: 
            wyjscie=true; 
            czyscEkran();
        break;

        }
    }
}

void Ui::menuAdmina()
{
    int opcja=-1;
    bool wyjscie=false;
    while(wyjscie==false)
    {
        std::cout<<"PANEL ADMINISTRATORA\n";
        przerywnik();
        std::cout<<"Zarzadzanie kontami klientow (1) | Przeglad wszystkich operacji (2) | Stworz raport podsumowujacy (3) | Wyjscie (4)\n";
        std::cin>>opcja;
        switch(opcja)
        {
             default: 
                std::cout<<"Nieprawidlowa opcja\n"; 
            break;
            case 1: //WYPIS KLIENTOW
                czyscEkran();
                std::cout<<"Aktualni klienci w bazie:\n";
                silnikSystemu.ADMINWyswietlKonta();
                przerywnik();
            break;
            case 2: //HISTORIA WSZYSTKICH OPERACJI
                czyscEkran();
                std::cout<<"Historia wszystkich operacji w systemie:\n";
                silnikSystemu.ADMINWyswietlHistorie();
                przerywnik();
            break;
            case 3: //RAPORT
                czyscEkran();
                silnikSystemu.ADMINRaport();
                przerywnik();
            break;
            case 4:
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