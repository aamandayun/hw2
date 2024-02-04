#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "product.h"


class Movie : public Product{
public:
  Movie(const std::string genre, const std::string rating, const std::string category, const std::string name, double price, int qty);

  virtual ~Book();
  std::string getGenre() const;
  std::string getRating() const;

  virtual std::set<std::string> keywords() const override;

  private:
    std::string genre_;
    std::string rating_;

};
#endif