#include <iostream>
#include "Paperbook.h"
#include "Ebook.h"
#include "Reviewer.h"
using namespace std;

int main()
{
    Paperbook fellowship_of_the_ring(9.6);
    Paperbook* two_towers = fellowship_of_the_ring.add_review(9.3);
    Ebook twilight(6.9);
    Ebook* twilight_part2 = twilight.add_review(4.2);

    cout << two_towers->see_review()<<endl<< twilight_part2->see_review()<<endl;
    
    Book* discworld = new Paperbook(8.88);
    Book* podstawy_chemii_dla_bioinformatykow = new Ebook(6.66);
    Reviewer Jack_Black("Jacek Czarny", discworld);
    Reviewer Walter_White("Wlodzimierz Bialy", podstawy_chemii_dla_bioinformatykow);
    Jack_Black.print_information();
    Walter_White.print_information();
}

