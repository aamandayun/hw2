#include <string>
#include <set>
#include "movie.h"
#include "product.h"

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
  keywords.insert(genre_);
  keywords.insert(rating_);
  return keywords;
}



