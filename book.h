#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "product.h"


class Book : public Product{
  public:
    Book(const std::string ISBN, const std::string author, const std::string category, const std::string name, double price, int qty);
    virtual ~Book();

    virtual std::set<std::string> keywords() const override;

    private:
      std::string ISBN_;
      std::string author_;

};
#endif