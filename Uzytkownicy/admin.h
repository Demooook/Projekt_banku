#pragma once

#include "uzytkownik.h"
class Admin: public Uzytkownik
{
    public:
        void zarzadzajKontami();
        void sprawdzOperacje();
        void stworzRaport();
};