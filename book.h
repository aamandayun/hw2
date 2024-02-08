#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include "product.h"


class Book : public Product{
  public:
    Book(const std::string ISBN, const std::string author, const std::string category, const std::string name, double price, int qty);
    virtual ~Book();

    virtual std::set<std::string> keywords() const override;
    virtual std::string displayString() const override;

    void dump(std::ostream& os) const;

  private:
    std::string ISBN_;
    std::string author_;

};
#endif