#pragma once

#include "konto.h"

class KontoOsobiste : public Konto
{
    public:
        void wyswietlInfo() override;
        KontoOsobiste(std::string pom_numer);
        bool wyplac(double kwota) override;
};