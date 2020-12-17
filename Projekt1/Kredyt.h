#include <iostream>
class Kredyt{
public:
    Kredyt() {}
    Kredyt(unsigned int czas, double kwota_pozyczki ){
        pozostale_raty = czas;
        dlug = kwota_pozyczki * (1. + czas/100.);
        rata = dlug/pozostale_raty;
    }
    void splac_rate() {
        if(pozostale_raty==0)
            rata = 0;
        else{
            dlug = dlug - rata;
            pozostale_raty--;
        }

    }
    double get_rata(){return rata;}
    void print() const{
        std::cout<<"Dlug wynosi: "<<dlug<<" . Rata wynosi: "<<rata<<". Pozostala ilosc rat do splacenia: "<<pozostale_raty<<std::endl;
    }
private:
    double dlug;
    double rata;
    unsigned int pozostale_raty;
};