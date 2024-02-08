#include <string>
#include <set>
#include "book.h"
#include "product.h"
#include "util.h"

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
  set<string> author = parseStringToWords(author_);
  set<string>::iterator at = author.begin();
  while(at != author.end()){
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

string Book::displayString() const{
  return ISBN_ + "\n" + author_ + "\n";
}
