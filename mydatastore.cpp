#include <iostream>
#include <string>
#include <set>
#include <map>
#include <map>
#include "mydatasore.h"
#include "datastore.h"
#include "user.h"
#include "product_parser.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "util.h"
using namespace std;
void MyDataStore::addProduct(Product* product) {
    keyword.insert({product->keywords(), product});
    totalProds.insert(product);
}
void MyDataStore::addUser(User* username) {
    user.insert({username->getName(), username});
    totalUsers.insert()
}
void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << endl;
    for(std::set<Product *> iterator it = totalProds.begin(); it!= totalProds.end(); ++it) {
            (*it) -> dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for(std::set<User *> iterator it = totalUsers.begin(); it != totalUsers.end(); ++it) {
            (*it) -> dump(ofile);
    }
    ofile << "</users>" << endl;
}
void MyDataStore::addCart(std::string username_, Product *product) {
    if(user.find(username_) != user.end()) {
        cart[username_].push_back(product); //once username is found, add the product
    } else {
        cout << "Invalid username";
    }
}
void MyDataStore::viewCart(std::string username_) {
    int items = 0;
    if(user.find(username_) != user.end()) {
        for(std::vector<Product *> iterator it = cart[username_].begin(); it != cart[username_].end(); ++it) {
            items++;
            cout << "Item " << items << endl;
            cout << (*itr)->displayString() << endl;
        }
    } else {
        cout << "Invalid username";
    }
}
void MyDataStore::buyCart(std::string username_) {
    double cost;
    if(user.find(username_) != user.end()) {
        for(int i = 0; i < cart[username_].size(); i++) {
            cost = 0;
            cost = cost + cart[username_][i]->getPrice();
            if(user[])
        }
    } else {
        cout << "Invalid username";
    }
}