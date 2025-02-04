#include "book.h"
#include "util.h"
#include <iostream>
#include <set>
using namespace std;

Book::Book(const string isbn, const string author, const string category, const string name, const double price, const int qty) : Product(string category, const string name, double price, int qty) {
    isbn_ = isbn;
    author_ = author;
    category_ = category;
    name_ = name;
    price_ = price;
    qty_ = qty;
}
Book::~Book() {

}
std::set<string> Book::keywords() const {
    std::set<string> keywords;
    keywords.insert(parseStringToWords(this->name_)); //will have spaces so parse
    keywords.insert(convToLower(this->author_)); //these items are one word
    keywords.insert(convToLower(this->isbn_)); //one word too

    return keywords;
}
std::string Book::displayString() const {
    string display = "";
    display = display + this->name_ + "\n" + "Author: " +  this->author_ + " ISBN: " + this->isbn_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
    
    return display;
}
void Book::dump(std::ostream& os) const
{
    os << this->category_ << endl;
    os << this->name_ << endl;
    os << this->price_ << endl;
    os << this->qty_ << endl;
    os << this->isbn_ << endl;
    os << this->author_ << endl;
}