#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>

class MyDataStore : public DataStore{
    public:
        MyDataStore();
        ~MyDataStore();
        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        void ViewCart(std::string user);
        void AddToCart(Product* p, std::string user);
        void BuyCart(std::string user);
    protected:
        std::map<std::string,std::set<Product*>> prodMap; //map of keywords to a set of corresponding products
        std::vector<Product*> productAll; //master product vect
        std::map<std::string, User*> userAll; // master user map
        std::string keys;
        std::map<User*, std::vector<Product*>> cart;
};
#endif