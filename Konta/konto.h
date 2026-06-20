#pragma once

#include "../Operacje/transakcje.h"
#include <vector>

class Konto
{
    private:
        std::string numer_konta;
        double saldo;
        Transakcja *historia;
        int liczba_transakcji;
    public:
        Konto() { numer_konta = "0"; saldo = 0.0; historia = nullptr; liczba_transakcji = 0; }
        Konto(std::string pom_numer_konta);
        Konto(std::string pom_numer_konta, double pom_saldo, Transakcja *pom_historia, int pom_liczba_transakcji);
        ~Konto()
        {
            delete[] historia;
        }
        virtual void wyswietlInfo();
        bool wplac(double kwota);
        virtual bool wyplac(double kwota);
        double getSaldo() {return saldo;}
        void zmienSaldo(double kwota) {saldo+=kwota;}
        void dodajTransakcje(Transakcja t);
        void wyswietlHistorieKonto();
        int getLiczbaTransakcji() {return liczba_transakcji;}
        std::string getNumer() {return numer_konta;}

};