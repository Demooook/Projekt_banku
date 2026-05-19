#pragma once 

#include "../Operacje/system.h"

class Ui
{
    private:
    System silnikSystemu;
    bool wyjscie=false;
    public:
        void start();
        void czyscEkran();
        void menuLogowania();
        void menuRejestracji();
};