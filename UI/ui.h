#pragma once 

#include "../Operacje/system.h"

class Ui
{
    private:
    System silnikSystemu;
    bool wyjscie=false;
    public:
        void start();
        void przerywnik();
        void czyscEkran();
        void menuLogowania();
        void menuRejestracji();
        void menuGlowne(std::string zalogowany_login);
        void podmenuZarzadzanie();
};