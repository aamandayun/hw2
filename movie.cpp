#include <string>
#include <set>
#include "movie.h"
#include "product.h"
#include "util.h"

//product: name, price, quantity in stock
//movie: genre, rating

using namespace std;

Movie::Movie(const std::string genre, const std::string rating, const std::string category, const std::string name, double price, int qty) : Product(category, name, price, qty), genre_(genre), rating_(rating)
{
}

Movie::~Movie(){
}

set<string> Movie::keywords() const{
  set<string> keywords;
  string gen = convToLower(genre_);
  keywords.insert(gen);
  keywords.insert(rating_);

  set<string> name = parseStringToWords(name_);

  set<string>::iterator it = name.begin();
  while(it != name.end()){
    keywords.insert(*it);
    it++;
  }
  return keywords;
}

string Movie::displayString() const{
  return genre_ + "\n" + rating_ + "\n";

}



