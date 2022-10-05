#include "product.h"
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product{ 
    public:
        Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author);
        std::set<std::string> keywords() const;
        bool isMatch(std::vector<std::string>& searchTerms) const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        std::string mAuthor;
        std::string mISBN;
};
#endif