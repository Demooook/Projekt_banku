#pragma once

#include "konto.h"

class Konto_oszczednosciowe : public Konto
{
    private:
        double oprocentowanie;
    public:
        void naliczOdsetki(double saldo);
};
    
