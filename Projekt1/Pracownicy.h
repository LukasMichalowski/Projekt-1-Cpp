#include "RandomNameGenerator.hpp"
#include <iostream>

class Pracownik {
public:
    explicit Pracownik(double z) : imie(get_random_name()), zarobki(z) {}
    virtual void drukuj() { std:: cout<<imie<<std::endl;}
    virtual double get_zarobki() {return zarobki;}
protected:
    std:: string imie;
    double zarobki;
};

class Inz : public Pracownik {
public:
    Inz() : Pracownik(ZAROBKI), wydzial("PW"){}
    explicit Inz(std::string w): Pracownik(ZAROBKI), wydzial(std::move(w)){}
    void drukuj() override { std:: cout<<imie<<". Wydzial: "<< wydzial<<std::endl;}
    double get_zarobki() override {return zarobki;}

private:
    std::string wydzial;
    constexpr static const double ZAROBKI= 4000.;


};

class Mkt : public Pracownik {
public:
    Mkt(): Pracownik(ZAROBKI),follows(1000){}
    explicit Mkt(int obs): Pracownik(ZAROBKI),follows(obs){}
    void drukuj() override { std:: cout<<imie<<". Obserwatorzy: "<<follows<<std::endl;}
    double get_zarobki() override {return zarobki;}
private:
   int follows;
   constexpr static const double ZAROBKI = 3000.;

};

class Mag : public Pracownik {
public:
    Mag(): Pracownik(ZAROBKI),o_w(false){}
    explicit Mag(bool tn): Pracownik(ZAROBKI),o_w(tn){}
    void drukuj() override { std:: cout<<imie<<". Obsluga widlaka: "<< o_w << std::endl;}
    double get_zarobki() override {return zarobki;}
private:
    bool o_w;
    constexpr static const double ZAROBKI = 3000.;

};
class Rob : public Pracownik {
public:
    Rob(): Pracownik(ZAROBKI),Rb(44) {}
    explicit Rob(int r): Pracownik(ZAROBKI),Rb(r){}
    void drukuj() override { std:: cout<<imie<<". Rozmiar buta: "<<Rb<<std::endl;}
    double get_zarobki() override {return zarobki;}
private:
    int Rb;
    constexpr static const double ZAROBKI = 2000.;


};

