#include "book.h"
#include "product.h"
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>
#include "util.h"
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author):Product(){
    mAuthor = author;
    mISBN = ISBN;
}
std::set<std::string> Book::keywords() const{
	//parseStringToWords to make account for any spaces, then chuck it in the bag (set)
    set<string> authorK = parseStringToWords(mAuthor);
    set<string> nameK = parseStringToWords(name_);
    set<string> keysT = setUnion(authorK,nameK);
    keysT.insert(mISBN);
    return keysT;
}

bool Book::isMatch(std::vector<string>& searchTerms) const{
	//iterate through the set and return true if any of the searchTerms are found
    std::set<string> key = keywords();
    for(vector<string>::iterator it = searchTerms.begin(); it != searchTerms.end(); ++it){
        if(key.find(*it) != key.end()){
            return true;
        }
    }
    return false;
}
//convert price and qty to strings then concatenate everything, adding some formatting stuff in between
std::string Book::displayString() const{
    std::string display = "";
    string string_price = to_string(price_);
    display = name_ + "\n" + "Author: " + mAuthor + " ISBN: " + mISBN + "\n" + string_price + " " + to_string(qty_) + " left.";
    return display;
}
//throw everything into the output stream with the << operator
void Book::dump(ostream& os) const{
    os << category_ << name_ << price_ << qty_ << mISBN << mAuthor;
}