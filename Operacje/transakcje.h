#pragma once

#include <string>
#include <iostream>
class Transakcja
{
    private: 
        double kwota;
        std::string data;
        std::string odbiorca;
        std::string tytul;
    public:
     Transakcja(){}
     Transakcja(double temp_kwota, std::string temp_data, std::string temp_odbiorca, std::string temp_tytul) 
        {
        kwota = temp_kwota;
        data = temp_data;
        odbiorca = temp_odbiorca;
        tytul = temp_tytul;
        }
    friend std::ostream& operator<<(std::ostream& os, const Transakcja& t) {
    os << "Data: " << t.data << " | Kwota: " << t.kwota << " PLN | Odbiorca: " << t.odbiorca;
    return os;
}
};