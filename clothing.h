#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <iostream>
#include <string>

class Clothing : public Product {
    public:
    std::string size_;
    std::string brand_;

    Clothing(const string isbn, const string author, const string category, const string name, const double price, const int qty);
    ~Clothing();

    virtual std::std::set<string> Clothing::keywords() const;
    virtual std::string Clothing::displayString() const;
    virtual void Clothing::dump(std::ostream& os) const;
}