#pragma once

#include "../Konta/konto.h"

class Transakcja
{
    private: 
        double kwota;
        std::string data;
        std::string odbiorca;
        std::string tytul;
    public:
        void getInfo(int id_konta);
};