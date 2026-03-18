# Projekt banku (C++ OOP)
Ponizej znajduje się diagram UML - architektura systemu bankowego z zastosowaniem programowania obiektowego.
```mermaid  
 classDiagram
    class Uzytkownik{
        -int id_uzytkownik
        -string login
        -string haslo
        +Logowanie(haslo)
    }
    Uzytkownik <|--Admin : dziedziczy
    class Admin{
        +zarzadzajKontami()
        +sprawdzOperacje()
        +stworzRaport()
    }
    Uzytkownik <|-- Klient : dziedziczy
    class Klient{
        lista_kont:vector
        -string imie
        -string nazwisko
        -int pesel
        +utworzKonto()
        +wyswietlHistorie() 
        +zrobPrzelew()
    }
    class Konto{
        -int numer_konta
        -double saldo
        -historia vector<Transakcja>
        +wplac()
        +wyplac()
        +wyswietlStan()
    }
    Konto <|-- kontoOsobiste
    class kontoOsobiste{
    }
    Konto <|-- kontoOszczednosciowe
    class kontoOszczednosciowe{
        -double oprocentowanie
        +naliczOdsetki()
    }
    Konto --|> kontoKredytowe
    class kontoKredytowe{
        -double limit_debetu
    }
    Konto *-- Transakcja
    class Transakcja{
        -double kwota
        -string data
        -string odbiorca
        -string tytul
        +getInfo()
    }
 ```
