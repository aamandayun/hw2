#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include "product.h"


class Clothing : public Product{
  public:
    Clothing(const std::string size, const std::string brand, const std::string category, const std::string name, double price, int qty);

    virtual ~Clothing();

    virtual std::set<std::string> keywords() const override;
    virtual std::string displayString() const override;

  private:
    std::string size_;
    std::string brand_;
};
#endif