#include "movie.h"
#include "util.h"
#include <iostream>
#include <set>
using namespace std;

Movie::Movie(const string genre, const string rating, const string category, const string name, const double price, const int qty) : Product(string category, const string name, double price, int qty) {
    genre_ = genre;
    rating_ = rating;
    category_ = category;
    name_ = name;
    price_ = price;
    qty_ = qty;
}
Movie::~Movie() {

}
std::set<string> Movie::keywords() const {
    std::set<string> keywords;
    keywords.insert(parseStringToWords(this->name_)); //will have spaces so parse
    keywords.insert(convToLower(this->genre_)); //these items are one word
    keywords.insert(convToLower(this->rating_)); //one word too

    return keywords;
}
std::string Movie::displayString() const {
    string display = "";
    display = display + this->name_ + "\n" + "Genre: " +  this->genre_ + " Rating: " + this->rating_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
    
    return display;
}
void Movie::dump(std::ostream& os) const
{
    os << this->category_ << endl;
    os << this->name_ << endl;
    os << this->price_ << endl;
    os << this->qty_ << endl;
    os << this->genre_ << endl;
    os << this->rating_ << endl;
}