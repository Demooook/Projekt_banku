#pragma once

#include "konto.h"

class KontoKredytowe : public Konto
{
    private:
        double limit_debetu;
};