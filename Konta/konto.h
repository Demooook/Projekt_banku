#pragma once

#include "../Operacje/transakcje.h"
#include <vector>

class Konto
{
    private:
        std::string numer_konta;
        double saldo;
        std::vector<Transakcja> historia;
    public:
        Konto(std::string numer_konta, double saldo, std::vector<Transakcja> historia);
        Konto(std::string pom_numer_konta);
        virtual void wyswietlInfo();
        bool wplac(double kwota);
        virtual bool wyplac(double kwota);
        double getSaldo() {return saldo;}
        void zmienSaldo(double kwota) {saldo+=kwota;}
        void dodajTransakcje(Transakcja t);
        void wyswietlHistorieKonto();
        std::string getNumer() {return numer_konta;}

};