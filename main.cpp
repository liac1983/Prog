#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include "Page.h"
#include "Book.h"
 
using namespace std;

int main() {
  Book b;
if (!(b.import("book_01.txt"))) cout << "book not found! \n";
set<string> words = { "C++", "linux", "computer" };
b.build_index(words);
b.show_index();
  return 0;
}

