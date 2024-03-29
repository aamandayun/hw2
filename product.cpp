#include <sstream>
#include <iomanip>
#include "product.h"
#include "mydatastore.h"

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{

}

Product::~Product()
{
  // for(size_t i = 0; i<products_.size(); i++){
  //   delete products_[i];
  // }
  // products_.clear();

}


double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
   // os << category_ << "\n" << name_ << "\n" <<std::fixed<<std::setprecision(2)<< price_ << "\n" << qty_ << endl;
    dump(os);
}



