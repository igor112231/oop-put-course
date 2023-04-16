#pragma once
#include "Book.h"
#include <string>
using namespace std;

class Paperbook:public Book
{
public:
	Paperbook* add_review(float review) override;
	string see_review() override;
	Paperbook(float score);
private:
	float score;
};