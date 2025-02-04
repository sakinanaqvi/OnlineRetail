#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>
#include <string>

class Movie : public Product {
    public:
    std::string genre_;
    std::string rating_;

    Movie(const string genre, const string rating, const string category, const string name, const double price, const int qty);
    ~Movie();

    virtual std::std::set<string> Movie::keywords() const;
    virtual std::string Movie::displayString() const;
    virtual void Movie::dump(std::ostream& os) const;
}