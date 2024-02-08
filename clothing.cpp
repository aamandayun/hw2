#include <string>
#include <set>
#include "clothing.h"
#include "product.h"
#include "util.h"

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

  set<string> brand = parseStringToWords(brand_);
  set<string>::iterator at = brand.begin();
  while(at != brand.end()){
    keywords.insert(*at);
    at++;
  }


  set<string> name = parseStringToWords(name_);

  set<string>::iterator it = name.begin();
  while(it != name.end()){
    keywords.insert(*it);
    it++;
  }
  return keywords;
}

string Clothing::displayString() const{
  return size_ + "\n" + brand_ + "\n";
}