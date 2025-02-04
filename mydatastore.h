#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <iostream>
#include <string>
#include <map>
#include <set>
#include "util.h"
#include "datastore.h"

class MyDataStore : public DataStore 
{
    public:

    void addUser(User *user);
    void addProduct(Product *p);
    void addCart(std::string username_, Product * product);
    void buyCart(std::string username_);
    void viewCart(std::string username_);

    std::string username_;
    std::set<Product *> totalProds;
    std::set<Product *> search;
    std::set<User*> totalUsers;
    std::map<std::set<std::string>, Product *> keyword;
    std::map<std::string, User*> user;
    std::map<std::string, std::vector<Product *>> cart;
}
#endif