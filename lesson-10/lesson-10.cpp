#include <string>
#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

using namespace std;

atomic <int> A(0), C(0), G(0), T(0);

void count(string seq, int start, int end)
{
    for (start; start < end; start++)
    {
        switch (seq[start])
        {
        case 'A':
            A++;
            break;
        case 'C':
            C++;
            break;
        case 'G':
            G++;
            break;
        case 'T':
            T++;
            break;
        }
    }
}

int main()
{
    string seq="ACGTGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCT";
    int start = 0, end = seq.length() / 5;
    //ector <thread> threads { count(seq, start, end) };
    thread tr(count,seq, start, end);
    for (int i = 0; i < 5; i++) 
    { 
        start = end;
        end += seq.length() / 5;
        //threads.push_back(count(seq, start, end));
    }

   // for (auto& t : threads) 
    { 
        tr.join(); 
        //count(seq, start, end);
        //start = end;
        //end += seq.length() / 5;
    }
    //cout << count(seq, start, end);
}



/*#include <iostream>
#include <atomic>
 #include <thread>
 #include <vector>
 std::atomic<int> counter(0);
 void increment() {
     for (int i = 0; i < 1000; ++i) { ++counter; }
    
}
 int main() {
     std::vector<std::thread> threads;
     for (int i = 0; i < 10; ++i) { threads.emplace_back(increment); }
     for (auto& t : threads) { t.join(); }
     std::cout << "Counter: " << counter << std::endl;
    
}*/