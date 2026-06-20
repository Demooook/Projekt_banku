#pragma once

#include "konto.h"

class KontoOszczednosciowe : public Konto
{
    private:
        double oprocentowanie;
    public:
        KontoOszczednosciowe(std::string pom_numer);
        void naliczOdsetki(double saldo);
        void wyswietlInfo() override;
        bool wyplac(double kwota) override;
        void naliczOdsetki() override;
};
    
