#include <iostream>
#include <string>

using namespace std;

class Super_szypki_samochod
{
private:
    string marka, model;
    int max_predkosc;
public:
    Super_szypki_samochod(string marka, string model, int max_predkosc);
    ~Super_szypki_samochod();
};

Super_szypki_samochod::Super_szypki_samochod(string mar, string mod, int maxpr)
{
    cout << "Samochod marki: " << mar << mod << " jedzie z maksymalna predkoscia: " << maxpr << " km/h" << endl;
    marka = mar;
    model = mod;
    max_predkosc = maxpr;
}

Super_szypki_samochod::~Super_szypki_samochod()
{
    cout << "Destruktor informuje o zezlomowaniu samochodu "<<marka << " " << model;
}

int main() 
{
    Super_szypki_samochod czerwona_rakieta("Fiat", "Punto", 140);
    return 0;
}