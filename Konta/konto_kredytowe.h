#pragma once

#include "konto.h"

class Konto_kredytowe : public Konto
{
    private:
        double limit_debetu;
};