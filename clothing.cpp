#include "clothing.h"
#include "util.h"
#include <iostream>
#include <set>
using namespace std;

Clothing::Clothing(const string size, const string brand, const string category, const string name, const double price, const int qty) : Product(string category, const string name, double price, int qty) {
    size_ = size;
    brand_ = brand;
    category_ = category;
    name_ = name;
    price_ = price;
    qty_ = qty;
}
Clothing::~Clothing() {

}
std::set<string> Clothing::keywords() const {
    std::set<string> keywords;
    keywords.insert(parseStringToWords(this->name_)); //will have spaces so parse
    keywords.insert(convToLower(this->size_)); //these items are one word
    keywords.insert(convToLower(this->brand_)); //one word too

    return keywords;
}
std::string Clothing::displayString() const {
    string display = "";
    display = display + this->name_ + "\n" + "Size: " +  this->size_ + " Brand: " + this->brand_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
    
    return display;
}
void Clothing::dump(std::ostream& os) const
{
    os << this->category_ << endl;
    os << this->name_ << endl;
    os << this->price_ << endl;
    os << this->qty_ << endl;
    os << this->size_ << endl;
    os << this->brand_ << endl;
}