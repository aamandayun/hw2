#include <iostream>
#include <sstream>
#include <string>
#include "util.h"

using namespace std;

int main(){
  string test = "hello my name is amanda: her dog's we're I'll cat is cute! 212 hot";

  set<string> parsed = parseStringToWords(test);

  int count = 0;
  for(string obj : parsed) {
    count++;
    cout << count<<": "<<obj<<endl;
  }

  string test2 = "hello marcos how are you";
  set<string> parsed2 = parseStringToWords(test2);

  set<string> intersection = setIntersection(parsed, parsed2);
  set<string> OR = setUnion(parsed, parsed2);


  cout <<"INTERSECTION"<<endl;
  int track = 0;
  for(string obj : intersection) {
    track++;
    cout << track<<": "<<obj<<endl;
  }

  cout <<"UNION"<<endl;
  int track2 = 0;
  for(string obj : OR) {
    track2++;
    cout << track2<<": "<<obj<<endl;
  }

  


  return 0;
}