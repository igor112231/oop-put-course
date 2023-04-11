#include <iostream>
#include <string>

using namespace std;

class Ryba
{
public:
    string gatunek;
    bool slodkowodna;
    int ilosc_lusek;
};

class Ptak
{
public:
    string gatunek;
    string ulubiona_ryba;
    int ilosc_pior;
};

class Kot
{
public:
    string ulubiona_ryba;
    string ulubiony_ptak;
    int ilosc_zyc;
};

int main()
{
    Ryba nemo;
    nemo.gatunek = "blazenek";
    nemo.slodkowodna = 0;
    nemo.ilosc_lusek = 99;

    Ptak simba;
    simba.gatunek = "orzel";
    simba.ulubiona_ryba = "nemo";
    simba.ilosc_pior = 999;

    Kot w_butach;
    w_butach.ulubiona_ryba = "nemo";
    w_butach.ulubiony_ptak = "simba";
    w_butach.ilosc_zyc = 9;

}

