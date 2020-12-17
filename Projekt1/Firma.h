#include "PrinterPracownikow.h"
#include "Kredyt.h"
#include <variant>
#include <memory>

class Firma{
    unsigned int n_rob;
    unsigned int n_mag;
    unsigned int n_inz;
    unsigned int n_mkt;
    double przychod;
    static const int CR = 10;
    static const int Cmag = 15;
    static const int CMkt = 10;
    constexpr static const double CI = 666.66;
private:

double stan_konta;
unsigned int n_pracownikow;
unsigned int n_kredytow;

using pracownik_t =  std::variant<Inz,Mag,Mkt,Rob>;
//pracownik_t *pracownicy = new pracownik_t[n_pracownikow] ;
//Kredyt *kredyty = new Kredyt[n_kredytow];
std::unique_ptr<pracownik_t []> pracownicy = std::make_unique<pracownik_t []>(n_pracownikow);
std::unique_ptr<Kredyt []> kredyty = std::make_unique<Kredyt []>(n_kredytow);
public:
Firma(){
    stan_konta = 50000.;
    n_pracownikow = 4;
    n_rob = 1;
    n_mag = 1;
    n_inz = 1;
    n_mkt = 1;
    pracownicy[0] = Inz();
    pracownicy[1] = Mag();
    pracownicy[2] = Mkt();
    pracownicy[3] = Rob();
    przychod = 0;


}

//~Firma(){ delete[] pracownicy; /*delete[] kredyty;*/}

void drukuj_pracownikow(){
    for(int i=0; i<n_pracownikow;++i)
        std::visit(PrinterPracownikow{},pracownicy[i]);
}

void zatrudnij_inz(){
    pracownicy[n_pracownikow] = Inz();
    n_inz++;
    n_pracownikow++;
}
void zatrudnij_mag(){
    pracownicy[n_pracownikow] = Mag();
    n_mag++;
    n_pracownikow++;
}
void zatrudnij_mkt(){
    pracownicy[n_pracownikow] = Mkt();
    n_mkt++;
    n_pracownikow++;
}
void zatrudnij_rob(){
    pracownicy[n_pracownikow] = Rob();
    n_rob++;
    n_pracownikow++;
}
void zaplac_wynagorodzenie(){
    for(int i =0;i<n_pracownikow;++i)
       stan_konta-=std::visit(WynagrodzeniePracownikow{},pracownicy[i]);
}
[[nodiscard]] double get_stan_konta() const {return stan_konta;}

    void otrzymaj_przychod(){
        unsigned int n_produktow;
        if(CR*n_rob< Cmag*n_mag)
            n_produktow = CR*n_rob;
        else
            n_produktow = Cmag*n_mag;
        if(n_mkt*CMkt<n_produktow)
            przychod = n_mkt*CMkt*n_inz*CI;
        else
            przychod = n_produktow*n_inz*CI;
        stan_konta+=przychod;

    }
    [[nodiscard]] double get_przychod() const {return przychod;}

    void wez_kredyt(double kwota,int czas_splaty)
    {
    kredyty[n_kredytow] = Kredyt(czas_splaty,kwota);
    n_kredytow++;
    stan_konta+=kwota;
    }
    void drukuj_kredyty() {
    if(n_kredytow==0)
        std::cout<<"BRAK KREDYTOW"<<std::endl;
    else{
        for(int i =0 ; i<n_kredytow;++i)
            kredyty[i].print();
    }
    }
    void splac_raty(){
    if(n_kredytow!=0){
        for(int i =0 ; i<n_kredytow;++i) {
            kredyty[i].splac_rate();
            stan_konta -= kredyty[i].get_rata();
        }}
    }
};

