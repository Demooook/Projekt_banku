#include "system.h"
#include "../Uzytkownicy/klient.h"
#include "../Konta/konto_osobiste.h"
#include "../Konta/konto_kredytowe.h"
#include "../Konta/konto_oszczednosciowe.h"
#include "../Operacje/transakcje.h"
#include <memory>
#include <iostream>

bool System::utworzKonto(std::string temp_login, std::string temp_haslo, std::string temp_imie, std::string temp_nazwisko, std::string temp_pesel)
{
    for (int i = 0; i < liczba_klientow; i++)
    {
        if (listaKlientow[i].getLogin() == temp_login)
        {
            std::cout << "Blad: Podany login jest juz zajety!\n";
            return false;
        }
        if (listaKlientow[i].getPesel() == temp_pesel)
        {
            std::cout << "Blad: Klient o podanym numerze PESEL juz istnieje w bazie!\n";
            return false;
        }
    }

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

    return true;
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
    int ileKont = listaKlientow[id_logowania].getIleKont();

    for (int i = 0; i < listaKlientow[id_logowania].getIleKont(); i++)
    {
        Konto* sprawdzane_konto = listaKlientow[id_logowania].getKontoWskaznik(i);

        if (wybrana_opcja == 1 && dynamic_cast<KontoOsobiste*>(sprawdzane_konto))
        {
            std::cout << "Blad: Posiadasz juz Konto Osobiste!\n";
            return false; 
        }
        else if (wybrana_opcja == 2 && dynamic_cast<KontoKredytowe*>(sprawdzane_konto))
        {
            std::cout << "Blad: Posiadasz juz Konto Kredytowe!\n";
            return false;
        }
        else if (wybrana_opcja == 3 && dynamic_cast<KontoOszczednosciowe*>(sprawdzane_konto))
        {
            std::cout << "Blad: Posiadasz juz Konto Oszczednosciowe!\n";
            return false;
        }
    }

    int najwyzszy_numer = 0;

    for (int i = 0; i < liczba_klientow; i++)
    {
        for (int j = 0; j < listaKlientow[i].getIleKont(); j++)
        {
            std::string stary_numer = listaKlientow[i].getNumerKonta(j);
            if (stary_numer.length() > 2)
            {
                try 
                {
                    std::string same_cyfry = stary_numer.substr(2); 
                    int wartosc_konta = std::stoi(same_cyfry);

                    if (wartosc_konta > najwyzszy_numer)
                    {
                        najwyzszy_numer = wartosc_konta;
                    }
                }
                catch (const std::exception& e) 
                {
                }
            }
        }
    }

    int nowy_numer = najwyzszy_numer + 1;
    std::string temp_numer_konta = "PL" + std::to_string(nowy_numer);

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
    for (int i=0; i<listaKlientow[id_logowania].getIleKont();i++)
    {
        if(wybrany_nr_konta==listaKlientow[id_logowania].getNumerKonta(i))
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
    bool znaleziono_nadawce = false;
    int id_odbiorcy = -1;

    if (kwota <= 0) return false;

    for (int i = 0; i < listaKlientow[id_logowania].getIleKont(); i++) 
    {
        if (listaKlientow[id_logowania].getNumerKonta(i) == podany_numer_wlasnego_konta) 
        {
            znaleziono_nadawce = true;
            break;
        }
    }
    
    if (znaleziono_nadawce == false) 
        return false;

    for (int i = 0; i < liczba_klientow; i++) 
    {
        for (int j = 0; j < listaKlientow[i].getIleKont(); j++) 
        {
            if (listaKlientow[i].getNumerKonta(j) == podany_numer_konta)
            {
                id_odbiorcy = i;
                break;
            }
        }
        if (id_odbiorcy != -1) break;
    }

    if (id_odbiorcy == -1) 
    {
        std::cout << "Blad: Nie znaleziono konta odbiorcy w systemie!\n";
        return false;
    }

    if (listaKlientow[id_logowania].wyplacZKonta(kwota, podany_numer_wlasnego_konta, podany_numer_konta, "Przelew wychodzacy"))
    {
        listaKlientow[id_odbiorcy].wplacNaKonto(kwota, podany_numer_konta, podany_numer_wlasnego_konta, "Przelew przychodzacy");   
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
std::ofstream plik("baza_banku.txt");
    if (!plik.is_open()) 
    {
        std::cout << "Blad: Nie mozna otworzyc pliku do zapisu!\n";
        return;
    }
    plik << liczba_klientow << "\n";

    for (int i = 0; i < liczba_klientow; i++)
    {
        plik << listaKlientow[i].getLogin() << " "
             << listaKlientow[i].getHaslo() << " "
             << listaKlientow[i].getImie() << " "
             << listaKlientow[i].getNazwisko() << " "
             << listaKlientow[i].getPesel() << " "
             << listaKlientow[i].getIleKont() << "\n";

        for (int j = 0; j < listaKlientow[i].getIleKont(); j++)
        {
            Konto* aktualne_konto = listaKlientow[i].getKontoWskaznik(j);
            if (dynamic_cast<KontoOsobiste*>(aktualne_konto)) 
            {
                plik << "O " << aktualne_konto->getNumer() << " " << aktualne_konto->getSaldo() << "\n";
            }
            else if (dynamic_cast<KontoKredytowe*>(aktualne_konto)) 
            {
                plik << "K " << aktualne_konto->getNumer() << " " << aktualne_konto->getSaldo() << "\n";
            }
            else if (dynamic_cast<KontoOszczednosciowe*>(aktualne_konto)) 
            {
                plik << "S " << aktualne_konto->getNumer() << " " << aktualne_konto->getSaldo() << "\n";
            }
        }
    }
    
    plik.close();
    std::cout << "Baza zostala poprawnie zapisana do pliku baza_banku.txt\n";
}
void System::wczytBazy()
{
    std::ifstream plik("baza_banku.txt");
    if (!plik.is_open()) 
    {
        std::cout << "Blad: Brak pliku bazy lub nie mozna go otworzyc.\n";
        return;
    }

    delete[] listaKlientow;
    listaKlientow = nullptr;
    liczba_klientow = 0;

    int wczytana_liczba_klientow;
    plik >> wczytana_liczba_klientow;

    for (int i = 0; i < wczytana_liczba_klientow; i++)
    {
        std::string t_login, t_haslo, t_imie, t_nazwisko, t_pesel;
        int t_ile_kont;
        
        plik >> t_login >> t_haslo >> t_imie >> t_nazwisko >> t_pesel >> t_ile_kont;

        Klient wczytywany_klient(nastepne_id, t_login, t_haslo, t_imie, t_nazwisko, t_pesel);
        nastepne_id++;

        for (int j = 0; j < t_ile_kont; j++)
        {
            char typ_konta;
            std::string t_numer;
            double t_saldo;

            plik >> typ_konta >> t_numer >> t_saldo;

            if (typ_konta == 'O') 
            {
                auto konto = std::make_unique<KontoOsobiste>(t_numer);
                konto->zmienSaldo(t_saldo);
                wczytywany_klient.dodajKonto(std::move(konto));
            }
            else if (typ_konta == 'K') 
            {
                auto konto = std::make_unique<KontoKredytowe>(t_numer);
                konto->zmienSaldo(t_saldo);
                wczytywany_klient.dodajKonto(std::move(konto));
            }
            else if (typ_konta == 'S') 
            {
                auto konto = std::make_unique<KontoOszczednosciowe>(t_numer);
                konto->zmienSaldo(t_saldo);
                wczytywany_klient.dodajKonto(std::move(konto));
            }
        }
        Klient* nowa_lista = new Klient[liczba_klientow + 1];
        for (int k = 0; k < liczba_klientow; k++) 
        {
            nowa_lista[k] = std::move(listaKlientow[k]);
        }
        nowa_lista[liczba_klientow] = std::move(wczytywany_klient);
        
        delete[] listaKlientow;
        listaKlientow = nowa_lista;
        liczba_klientow++;
    }
    plik.close();
    std::cout << "Baza zostala poprawnie wczytana z pliku.\n";
}

void System::symulujOdsetki()
{
    for (int i = 0; i < liczba_klientow; i++)
    {
        listaKlientow[i].symulujMiesiac();
    }
    std::cout << "Minal miesiac. Odsetki na wszystkich kontach oszczednosciowych w banku zostaly naliczone!\n";
}