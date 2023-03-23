#include <iostream>
using namespace std;

//! Determines if two s-trings are anagrams.
bool anagrams(const char a[], const char b[], int& n) {
  int count[26] = { 0 };
  // add letters of a
  for (int i = 0; a[i] != '\0'; i++) {
    if (a[i] != ' ') {
      if (a[i] >= 'a' && a[i] <= 'z') 
        count[a[i] - 'a']++;
      else
        count[a[i] - 'A']++;
    }
  }
  // remove letters of b
  for (int i = 0; b[i] != '\0'; i++) {
    if (b[i] != ' ') {
      if (b[i] >= 'a' && b[i] <= 'z') 
        count[b[i] - 'a']--;
      else 
        count[b[i] - 'A']--;
    }
  }
  // count different letters
  n = 0;
  for (int c : count) {
    if (c < 0) 
      c = -c;  // differences are positive
    n += c; 
  } 
  return n == 0;
}

int main() {
char a[] = "Z Plus Plus after Python";
char b[] = "zYTHON after p plus plus";
int n = -1;
bool r = anagrams(a, b, n);
cout << '\"' << a << '\"' << ' '
     << '\"' << b << '\"' << ' '
     << boolalpha << r << ' ' << n << '\n';
    return 0;
}