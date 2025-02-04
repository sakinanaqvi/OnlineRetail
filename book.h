#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <iostream>
#include <string>

class Book : public Product {
    public:
    std::string ISBN_;
    std::string author_;

    Book(const string isbn, const string author, const string category, const string name, const double price, const int qty);
    ~Book();

    virtual std::std::set<string> Book::keywords() const;
    virtual std::string Book::displayString() const;
    virtual void Book::dump(std::ostream& os) const;
}