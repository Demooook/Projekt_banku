#pragma once

#include <vector>

class Konto
{
    private:
        int numer_konta;
        double saldo;
        std::vector<int> historia;
    public:
        Konto(int numer_konta, double saldo, std::vector<int> historia);
        bool wplac(double kwota);
        bool wyplac(double kwota);
        double getSaldo() {return saldo;}

};