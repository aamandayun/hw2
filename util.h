#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

#include <algorithm>

//gitignore amazon.cpp book.cpp book.h clothing.cpp clothing.h database.txt datastore.h db_parser.cpp db_parser.h Makefile movie.cpp movie.h product.cpp product.h product_parser.cpp product_parser.h user.cpp user.h util.cpp util.h 

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> intersection;
  std::set<T> longest = s1.size() > s2.size() ? s1:s2;
  const std::set<T> shortest = s1.size() >s2.size()? s2:s1;

  for(auto i = longest.begin(); i!=longest.end(); ++i){
    if(shortest.find(*i) != shortest.end()){
      //found
      intersection.insert(*i);
    }
  }
  return intersection;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

  std::set<T> unionSet;

  for(auto i = s1.begin(); i!= s1.end(); ++i){
    unionSet.insert(*i);
  }

  for(auto i = s2.begin(); i!= s2.end(); ++i){
    unionSet.insert(*i);
  }

  return unionSet;
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
