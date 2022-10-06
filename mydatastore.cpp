#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "mydatastore.h"
#include "util.h"
#include <iterator>
#include "user.h"
#include "product.h"

using namespace std;

MyDataStore::MyDataStore(){

}
MyDataStore::~MyDataStore(){
    for(vector<Product*>::iterator it = productAll.begin(); it != productAll.end(); ++it){
        delete *it;
    }
    for(map<std::string, User*>::iterator it = userAll.begin(); it != userAll.end(); ++it){
        delete it->second;
    }
}
void MyDataStore::addProduct(Product* p){ // we have keywords, mapped to a set of products 
    set<string>temp =p->keywords(); // create an observable set of the keywords of the new product
    for(set<string>::iterator it = temp.begin(); it != temp.end(); ++it){
        if(prodMap.find(*it)!=prodMap.end()){
            prodMap.find(*it)->second.insert(p);
        }
        else{
            set<Product*> prod;
            prod.insert(p); 
            prodMap.insert(make_pair(*it, prod));
        }
    }
    productAll.push_back(p);
    return;
}
void MyDataStore::addUser(User* u){
    userAll.insert(make_pair(u->getName(), u));
    return;
}
void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << "\n";
    for(vector<Product*>::iterator it = productAll.begin(); it != productAll.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile << "</products>" << "\n" << "<users>" << "\n";
    for(map<std::string, User*>::iterator it = userAll.begin(); it != userAll.end(); ++it){
        it->second->dump(ofile);

    }
    ofile << "</users>" << "\n";
    return;
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){    //WIP COME BACK TO THIS
   
   set<Product*> temp = prodMap[terms[0]];
   for(vector<string>::iterator it = terms.begin(); it != terms.end(); ++it){
    if(prodMap.find(*it) != prodMap.end()){
        if(type == 1){
            temp = setUnion(prodMap[*it], temp);
        }
        else{
            temp = setIntersection(prodMap[*it], temp);
        }
    }
   }
   vector<Product*> result(prodMap.begin(),prodMap.end());
   return result;
}  

void MyDataStore::AddToCart(Product* p, string user){ // does not work unfortunately
   /*
    User* temp = nullptr; 
    cart.find(userAll.find(user)); 
    std::map<User*, std::vector<Product*>>::iterator it = cart.begin();

    User* temp = userAll.find(user);
    for( std::map<std::string, User*>::iterator it = userAll.begin(); it != userAll.end(); ++it ){
        if(((*it)->second)->getName() == user ){
            temp = *it;
        }
    }
    string username = convToLower(user);
    if(cart.find(user) != user.end()){
        cart.find(user)->second.insert(p);
    }
    else{
        cout << "Invalid username" << endl;
    }
    if(user)
    */
   cout << "Invalid Username" << endl;
    
}
void MyDataStore::ViewCart(string user){
    string username = convToLower(user);
    int index = 1;
    if(userAll.find(user) != userAll.end()){
        for(map<User*,vector<Product*>>::iterator it = cart.begin(); it != cart.end(); ++it){
            cout << it->second[index-1] << endl;
            index++;
        }
    }
    else{
        cout << "Invalid username" << endl;
    }
}
void MyDataStore::BuyCart(string user){
    string username = convToLower(user);
    int balance = userAll.find(user)->second->getBalance();
    //buy the damn cart its not hard please just take the money and let me be
    if(userAll.find(user) != userAll.end()){
        vector<Product*> temp = cart[userAll[user]];
        for(vector<Product*>::iterator it = temp.begin(); it != temp.end(); ++it){
            (*it)->getQty();
            if((((*it))->getQty() > 0) && (balance >= (*it)->getPrice())){ //ISSUE
                balance -= (*it)->getPrice(); //ISSUE
                (*it)->subtractQty(1); //ISSUE HERE
            }
        }
    }
    else{
        cout << "Invalid username" << endl;
    }
}