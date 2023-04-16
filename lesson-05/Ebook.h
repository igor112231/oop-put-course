#pragma once
#include "Book.h"
#include <string>
using namespace std;

class Ebook :public Book
{
public:
	Ebook* add_review(float review) override;
	string see_review() override;
	Ebook(float score);
private:
	float score;
};