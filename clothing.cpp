#include "clothing.h"
#include "product.h"
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>
#include "util.h"
using namespace std;

/* SEE BOOK.CPP FOR ALL CODE COMMENTS */

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):Product(){
    mSize = size;
    mBrand = brand;

}
std::set<std::string> Clothing::keywords() const{
    set<string> sizeK = parseStringToWords(mSize);
    set<string> nameK = parseStringToWords(name_);
    set<string> brandK = parseStringToWords(mBrand);
    set<string> keysTemp = setUnion(sizeK,nameK);
    set<string> keysT = setUnion(keysTemp, brandK);
    return keysT;
}
bool Clothing::isMatch(std::vector<string>& searchTerms) const{
    std::set<string> key = keywords();
    for(vector<string>::iterator it = searchTerms.begin(); it != searchTerms.end(); ++it){
        if(key.find(*it) != key.end()){
            return true;
        }
    }
    return false;
}
std::string Clothing::displayString() const{
    std::string display = "";
    string string_price = to_string(price_);
    display = name_ + "\n" + "Size: " + mSize + " Brand: " + mBrand + "\n" + string_price + " " + to_string(qty_) + " left.";
    return display;
}
void Clothing::dump(ostream& os) const{
    os << category_;
    os << name_;
    os << price_;
    os << qty_;
    os << mSize;
    os << mBrand;
}