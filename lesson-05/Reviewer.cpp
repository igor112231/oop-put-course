#include "Reviewer.h"
#include<iostream>

Reviewer::Reviewer(string name, Book* review) : name(name), review(review) {};

void Reviewer::print_information() 
{
	cout << "I am " << this->name << " I think this book is " << this->review->see_review()<<endl;
}