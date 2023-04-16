#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book() {};
	virtual ~Book() {};
	virtual Book *add_review(float review)=0;
	virtual string see_review()=0;

};