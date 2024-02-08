#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <iostream>
#include <string>
#include <set>
#include <map>

#include "datastore.h"

using namespace std;

class MyDataStore : public DataStore{
  public:
    MyDataStore(){
      numProducts_= 0;
      numUsers_ = 0;
    }
     //virtual ~MyDataStore();
     void deleteAllProducts(); 
     void deleteAllUsers(); 


    void addProduct(Product *p) override;

    /**
     * Adds a user to the data store
     */
    void addUser(User* u) override;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile) override;


    void addToCart(User *u, Product *p);

    void viewCart(User *u);

    void buyCart(User *u);

    vector<User *> getUsers(){
      return users_;
    }

  //protected:
  private:
    std::map<std::string, std::set<Product *>> termToProducts_;
    vector<Product *> products_;
    //maps user to a set of their products
    std::map<User *, std::vector<Product *>> userProducts_;
    //or just a vector of users?
    std::vector<User *> users_;
    int numProducts_;
    int numUsers_;
};
#endif