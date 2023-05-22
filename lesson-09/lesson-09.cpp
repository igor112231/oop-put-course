#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

class IntegerSequence
{
public:
    ~IntegerSequence() = default;
    virtual vector <int> Numbers() = 0;
};


class VectorSequence :IntegerSequence
{
public:
    explicit VectorSequence(const vector<int> &numbers) :numbers_(numbers) {};
    
    vector<int> Numbers() override
    {
        return numbers_;
    }

private:
    vector<int> numbers_;
};

class IntegerDecorator : public IntegerSequence
{
public:
    virtual ~IntegerDecorator() = default;
};

class PositiveSequence : public IntegerDecorator {
public:
    explicit PositiveSequence(unique_ptr<IntegerDecorator> intseq) : intseq_(move(intseq)) {}
    
    vector<int> Numbers() override {
        vector<int> vect = intseq_->Numbers();
        
        vect=remove_if
    }

private:
    unique_ptr<IntegerDecorator> intseq_;
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vect1{-1,-2, 2,1,3,4,5,6 };
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
