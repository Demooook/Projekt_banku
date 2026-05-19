

#include "uzytkownik.h"
Uzytkownik::Uzytkownik()
{
    id_uzytkownika=0000;
    login="Nieznany";
    haslo="Nieznany";
};

Uzytkownik::Uzytkownik(int pom_id_uzytkownika, std::string pom_login, std::string pom_haslo)
{
    id_uzytkownika=pom_id_uzytkownika;
    login=pom_login;
    haslo=pom_haslo;
}