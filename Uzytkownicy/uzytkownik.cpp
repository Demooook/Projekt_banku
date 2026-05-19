

#include "uzytkownik.h"
Uzytkownik::Uzytkownik()
{
    id_uzytkownika=0000;
    login="Nieznany";
    haslo="Nieznany";
};

Uzytkownik::Uzytkownik(int temp_id_uzytkownika, std::string temp_login, std::string temp_haslo)
{
    id_uzytkownika=temp_id_uzytkownika;
    login=temp_login;
    haslo=temp_haslo;
}