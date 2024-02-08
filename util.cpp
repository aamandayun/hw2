#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
//split into individual keywords at punctuation
  set<string> words;
  string newWords = convToLower(rawWords);

  int start = 0;
  int end = 0;
  for(size_t i = 0; i<=newWords.size(); i++){
    char c = newWords[i];
    if(ispunct(c) || c==' ' || c=='\0'){
      string sub = newWords.substr(start, end);
      if(sub.size()>1 && newWords.substr(start, end).find('/0')==std::string::npos){
        words.insert(newWords.substr(start, end));
      }else if(sub.size()>2U && newWords.substr(start, end).find('/0')==std::string::npos){
        words.insert(newWords.substr(start, end));
      }
      start = start+end+1;
      end=0;
    }else{
      end++;
    }
  }

  return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
