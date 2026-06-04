#pragma once

#include <vector>

class Konto
{
    private:
        std::string numer_konta;
        double saldo;
        std::vector<int> historia;
    public:
        Konto(std::string numer_konta, double saldo, std::vector<int> historia);
        Konto(std::string pom_numer_konta);
        virtual void wyswietlInfo();
        bool wplac(double kwota);
        virtual bool wyplac(double kwota);
        double getSaldo() {return saldo;}
        void zmienSaldo(double kwota) {saldo+=kwota;}
        std::string getNumer() {return numer_konta;}

};