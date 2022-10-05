#include "movie.h"
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

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):Product(){
    mGenre = genre;
    mRating = rating;

}
std::set<std::string> Movie::keywords() const{
    set<string> genreK = parseStringToWords(mGenre);
    set<string> nameK = parseStringToWords(name_);
    set<string> ratingK = parseStringToWords(mRating);
    set<string> keysTemp = setUnion(genreK,nameK);
    set<string> keysT = setUnion(keysTemp, ratingK);
    return keysT;
}
bool Movie::isMatch(std::vector<string>& searchTerms) const{
    std::set<string> key = keywords();
    for(vector<string>::iterator it = searchTerms.begin(); it != searchTerms.end(); ++it){
        if(key.find(*it) != key.end()){
            return true;
        }
    }
    return false;
}
std::string Movie::displayString() const{
    std::string display = "";
    string string_price = to_string(price_);
    display = name_ + "\n" + "Genre: " + mGenre + " Rating: " + mRating + "\n" + string_price + " " + to_string(qty_) + " left.";
    return display;
}
void Movie::dump(ostream& os) const{
    os << category_;
    os << name_;
    os << price_;
    os << qty_;
    os << mGenre;
    os << mRating;
}