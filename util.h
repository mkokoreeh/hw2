#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
#include <iterator>
#include <cstdlib>  

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T> temp;
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it){//loop = O(N)
        if(s2.find(*it)!=s2.end()){ //Works in O(log(n)) so entire function is O(n(log(N)))
            temp.insert(*it);
        }
    }
    return temp;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T> temp;
    //2 outer loops of O(n) and 2 instances of insert() (log(n)), so runtime ~ O(n(log(n)))
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it){
        temp.insert(*it);
    }
    for(typename std::set<T>::iterator it = s2.begin(); it != s2.end(); ++it){
        temp.insert(*it);
    }
    return temp;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
