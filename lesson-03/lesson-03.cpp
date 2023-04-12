#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Kot;

class Ryba
{
private:
    string gatunek;
    string status = "alive";
public:
    Ryba poznaj_gatunek(string p_gatunek)
    {
        this->gatunek = move(p_gatunek);
        return *this;
    }
    void jaki_gatunek()
    {
        cout<< this->gatunek<<endl<<this->status;
    }
    void change_status()
    {
        this->status = move("dead");
    }
};

class Ptak
{
private:
    string ulubiona_ryba;
    string status = "alive";
public:
    void eat_fish(Ryba &ryba)
    {
        ryba.change_status();
    }
    void change_status()
    {
        this->status = move("dead");
    }
    void fight_back(Kot &kot)
    {
      kot.getting_damage();
    }
};

class Kot
{
private:
    int ilosc_zyc=9;
    string status = "alive";
public:
    void eat_fish(Ryba &ryba)
    {
        ryba.change_status();
    }
    void eat_bird(Ptak &ptak)
    {
        ptak.change_status();
    }
    void getting_damage()
    {
        this->ilosc_zyc--;
        cout <<endl<< this->ilosc_zyc;

        if (ilosc_zyc == 0) {
            this->status = move("dead");
        }
    }
};

int main()
{
    Ryba nemo;
    Ptak wrobel;
    Kot w_butach;
    nemo.poznaj_gatunek("blazenek");
    wrobel.eat_fish(nemo);
    //wrobel.fight_back(w_butach);
    w_butach.getting_damage();

}

