#include "Ebook.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

string Ebook::see_review() {
	stringstream stream;
	stream << setprecision(2) << score;
	string s = stream.str();
	return s + "/10";
}

Ebook* Ebook::add_review(float review)
{
	Ebook* a = new Ebook((review + score) / 2);
	return a;
}

Ebook::Ebook(float score) { this->score = score; }