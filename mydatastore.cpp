#include <iostream>
#include <set>
#include <string>
#include <map>
#include "mydatastore.h"
#include "util.h"
#include "product.h"
#include "user.h"

//store user info
//add to cart
//g++ -g -Wall mydatastore.cpp util.cpp -o dsTest

using namespace std;



void MyDataStore::addProduct(Product *p){
  //numProducts_ = 0;
  set<string> pTerms = p->keywords();
  for (string term: pTerms) {
    if (termToProducts_.find(term) == termToProducts_.end()) {
      termToProducts_[term] = set<Product *>();
      numProducts_++;
    }
    termToProducts_[term].insert(p);
  }
  products_.push_back(p);
}

void MyDataStore::addUser(User* u){
  //need to check if user already added?
  userProducts_[u] = vector<Product *>();
  numUsers_++;
  users_.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>&terms, int type){
//and
  set<Product*> foundProducts;

if(type==0){
  map<std::string, set<Product *>>::iterator it = termToProducts_.begin();
  int count = 0;
  std::map<int, set<Product *>> M;

  for(size_t i = 0; i<terms.size(); i++){
    string cur = terms[i];
    cout <<"CUR:"<<cur<<endl;

    while(it != termToProducts_.end()){
      set<Product *> test = it->second;
      cout <<"KEY: " <<it->first <<", Value: ";
      for(set<Product *>::iterator k=test.begin(); k!=test.end(); k++){
        cout << (*k)->getName() << " ";
      }
      cout <<endl;
      it++;
    }
    
    it = termToProducts_.find(cur);
    if(it == termToProducts_.end()){
      cout << "product not available" <<endl;
    }else{
      const set<Product *>& p = it->second;
      for(const auto& product : p){
        M[count].insert(product);
        cout << product->getName()<<endl;
        //foundProducts.insert(product);
      }
      count++;
    }
  }
  if(count > 1){
    set<Product *> found1 = M[0];
    set<Product *> found2 = M[1];

    foundProducts = setIntersection(found1, found2);
    
    for(int i=2; i<count; i++){
      set<Product *> found = M[i];
      foundProducts = setIntersection(foundProducts, found);
      if(foundProducts.empty()){
        cout <<"no products found"<<endl;
        break;
      }
    }
  }else{
    foundProducts = M[0];
    for(set<Product*>::iterator at=foundProducts.begin(); at != foundProducts.end(); ++at){
      cout << "within found products : "<<(*at)->getName() <<endl;
    }
    
  }
}
//OR
  if(type == 1){
    map<string, set<Product *>>::iterator it = termToProducts_.begin();

    for(size_t i = 0; i<terms.size(); i++){
      string cur = terms[i];
      it = termToProducts_.find(cur);
      if(it == termToProducts_.end()){
        cout << "term not available" <<endl;
      }
      else{
        //iterate through the set of products and push to the vector
        const set<Product *>& p = it->second;
        for(const auto& product : p){
          foundProducts.insert(product);
        }
      }
    }
  }

//convert from set to vector
  vector<Product*> result;

  for(set<Product*>::iterator iter=foundProducts.begin(); iter != foundProducts.end(); ++iter){
    // cout << "within found products : "<<(*iter)->getName() <<endl;
    // cout << "within found products : "<<(*iter)<<endl;
    result.push_back((*iter));
  }

  return result;

}

void MyDataStore::dump(ostream& ofile){
  ofile << "<products>"<< endl;
  for(size_t i=0; i<products_.size();i++){
    products_[i]->dump(ofile);
  }
  ofile << "</products>"<< endl;
  ofile << "<users>"<< endl;
  for(size_t i=0; i<users_.size();i++){
    users_[i]->dump(ofile);
  }
  ofile << "</users>"<< endl;
}


void MyDataStore::addToCart(User *u, Product *p){
  userProducts_[u].push_back(p);
}

void MyDataStore::viewCart(User *u){
  //need to check if user is valid here or in amazon?
  auto it = userProducts_.find(u);
  if (it == userProducts_.end()) {
    std::cout << "User not found in the cart." << std::endl;
    return;
  }
  vector<Product *>& inCart = it->second;


  for(vector<Product*>::iterator at=inCart.begin(); at != inCart.end(); ++at){
    cout << (*at)->displayString()<<endl;
  }

}


void MyDataStore::buyCart(User *u){
  auto it = userProducts_.find(u);
  vector<Product *>& inCart = it->second;

  for(vector<Product*>::iterator iter=inCart.begin(); iter != inCart.end();){
    if(u->getBalance()>=(*iter)->getPrice() && (*iter)->getQty()>0){
      (*iter)->subtractQty(1);
      u->deductAmount((*iter)->getPrice());
      iter = inCart.erase(iter);
    }else{
      cout << "balance too low or no products left" <<endl;
      ++iter;
    }
  }

  
/*
  for(size_t i=0; i<inCart.size(); i++){
    if(u->getBalance()>=inCart[i]->getPrice() && inCart[i]->getQty()>0){
      inCart[i]->subtractQty(1);
      u->deductAmount(inCart[i]->getPrice());
      delete[] inCart[i];
    }else{
      cout << "balance too low or no products left" <<endl;
    }
  }*/

}