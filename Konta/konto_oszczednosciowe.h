#pragma once

#include "konto.h"

class KontoOszczednosciowe : public Konto
{
    private:
        double oprocentowanie;
    public:
        void naliczOdsetki(double saldo);
        void wyswietlInfo() override;
};
    
