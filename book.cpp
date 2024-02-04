#include <string>
#include <set>
#include "book.h"
#include "product.h"

using namespace std;

//product: name, price, quantity in stock
//book: ISBN, author

using namespace std;

Book::Book(const std::string ISBN, const std::string author, const std::string category, const std::string name, double price, int qty) : Product(category, name, price, qty), ISBN_(ISBN), author_(author)
{
}

Book::~Book(){
}

set<string> Book::keywords() const{
  set<string> keywords;
  keywords.insert(ISBN_);
  keywords.insert(author_);
  return keywords;
}
