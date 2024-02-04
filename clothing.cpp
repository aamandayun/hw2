#include <string>
#include <set>
#include "clothing.h"
#include "product.h"

//product: name, price, quantity in stock
//clothing: size, brand


using namespace std;

Clothing::Clothing(const std::string size, const std::string brand, const std::string category, const std::string name, double price, int qty) : Product(category, name, price, qty), size_(size), brand_(brand){

}

Clothing::~Clothing(){
}

set<string> Clothing::keywords() const{
  set<string> keywords;
  keywords.insert(size_);
  keywords.insert(author_);
  return keywords;
}