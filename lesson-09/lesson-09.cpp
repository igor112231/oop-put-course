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
    
    vector<int> Numbers() override 
    {
        vector<int> pos_vect = intseq_->Numbers();
        for (int i = 0; i < pos_vect.size(); i++)
        {
            if (pos_vect[i] < 1)
            {
                pos_vect.erase(pos_vect.begin() + i);
            }
        }
        return pos_vect;
        //      vect=remove_if(vect.begin(), vect.end(),)
    }
private:
    unique_ptr<IntegerDecorator> intseq_;
};


class EvenSequence : public IntegerDecorator {
public:
    explicit EvenSequence(unique_ptr<IntegerDecorator> intseq) : intseq_ (move(intseq)) {}

    vector<int> Numbers() override
    {
        vector<int> even_vect = intseq_->Numbers();
        for (int i = 0; i < even_vect.size(); i++)
        {
            if (even_vect[i] % 2==0)
            {
                even_vect.erase(even_vect.begin() + i);
            }
        }
        return even_vect;
    }

private:
    unique_ptr<IntegerDecorator> intseq_;
};

class SortedSequence : public IntegerDecorator {
public:
    explicit SortedSequence(unique_ptr<IntegerDecorator> intseq) : intseq_(move(intseq)) {}

    vector<int> Numbers() override
    {
        vector<int> sort_vect = intseq_->Numbers();
        sort(sort_vect.begin(), sort_vect.end());
        return sort_vect;
    }
    
private:
    unique_ptr<IntegerDecorator> intseq_;
};

int main()
{
    vector<int> vect1{-1,-2, 2,1,3,6,5,4 };

    unique_ptr<IntegerSequence> intseq = make_unique<SortedSequence>(
        make_unique<EvenSequence>(
            make_unique<PositiveSequence>(
                make_unique<VectorSequence>(vect1))));
    
    vector<int> numbers = intseq->Numbers();

    cout << intseq << endl;
}
