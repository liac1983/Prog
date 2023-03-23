#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include "Page.h"
#include "Book.h"
 
using namespace std;

//! Builds ‘index’ for the ‘words’ received as parameter
void Book::build_index(const set<string>& words) 
{
  bool isInPage, addedToIndex;
  for(string word : words)
  {
    addedToIndex = false;
    for(size_t i = 0;i<book_.size();i++)
    {
      isInPage = false;
      Page currpage = book_[i];

      // Verify if word in page i
      for(size_t numline = 0; numline<currpage.get_num_lines(); numline++)
      {
        if(currpage.get_line(numline).find(word)!=string::npos){
          isInPage = true;
          break;
        }
      }

      //Add word to index
      if(isInPage) 
      {
        if(!addedToIndex && !index_.count(word))
        {
          index_.insert({word,{}});
          addedToIndex = true;
        }
        index_.at(word).insert(i+1);
      }
    }
  }
}