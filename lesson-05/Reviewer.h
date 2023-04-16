#pragma once
#include "Book.h"
#include <string>

class Reviewer
{
public:
	Reviewer(string name, Book* review);
	void print_information();
private:
	string name;
	Book* review;
};
