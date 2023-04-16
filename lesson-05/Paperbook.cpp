#include "Paperbook.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

string Paperbook::see_review() {
	stringstream stream;
	stream << setprecision(2) << score;
	string s = stream.str();
	return s + "/10";
}

Paperbook *Paperbook::add_review(float review)
{
	Paperbook* a = new Paperbook((review+score)/2);
	return a;
}

Paperbook::Paperbook(float score) { this->score = score; }