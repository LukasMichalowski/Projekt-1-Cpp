#include "Firma.h"

class Gra{
   bool stan;
    Firma firma;
private:
   constexpr static const double wygrana = 100000.;
   void tick(){
        firma.otrzymaj_przychod();
        firma.zaplac_wynagorodzenie();
        firma.splac_raty();
        std::cout<<"Aktualny stan konta: "<<firma.get_stan_konta()<<std::endl;
    }

public:
    //~Gra(){delete firma;}
   bool get_stan() const {return stan;}
    void akcja_gracza(){
        std::cout << "Wpisz komende. (Do wyboru:lp, zinz, zmag, zmkt, zrob, kred, kt, koniec): ";
        std::string akcja;
        std::cin >> akcja;
        std::cout << std::endl;
        if (akcja == "lp")
            firma.drukuj_pracownikow();
        else if (akcja == "zinz")
            firma.zatrudnij_inz();
        else if (akcja == "zmag")
            firma.zatrudnij_mag();
        else if (akcja == "zmkt")
            firma.zatrudnij_mkt();
        else if (akcja == "zrob")
            firma.zatrudnij_rob();
        else if (akcja == "kred") {
            std::cout << "Wpisz kwote pozyczki: ";
            double x;
            std::cin >> x;
            std::cout << std::endl;
            std::cout << "Czas splaty (miesiace): ";
            int y;
            std::cin >> y;
            std::cout << std::endl;
            firma.wez_kredyt(x, y);
        } else if (akcja == "kt") {
            tick();
            if (firma.get_stan_konta() < 0) {
                std::cout << "Zostales bankrutem. GAME OVER!!!" << std::endl;
                stan = false;
                return;
            } else if (firma.get_stan_konta() > wygrana) {
                std::cout << "WYGRALES!!!" << std::endl;
                stan = false;
                return;
            }
        } else if (akcja == "koniec")
            stan = false;
        else
            std::cout << "BLAD!! Niepoprawna komenda!!" << std::endl;
    }




};