#include "Pracownicy.h"
struct PrinterPracownikow{
    void operator() (Inz I) { I.drukuj();}
    void operator() (Mag I) { I.drukuj();}
    void operator() (Mkt I) { I.drukuj();}
    void operator() (Rob I) { I.drukuj();}
};
struct WynagrodzeniePracownikow{
    double operator() (Inz I) { return I.get_zarobki();}
    double operator() (Mag I) { return I.get_zarobki();}
    double operator() (Mkt I) { return I.get_zarobki();}
    double operator() (Rob I) { return I.get_zarobki();}
};