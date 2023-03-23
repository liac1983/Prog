#include <vector>
#include <iostream>
using namespace std;
 
//! Print vector with elements of type T.
template <typename T>
void print(const vector<T>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << "]\n";
}

//Normalise elements of vector foe values between min and max
template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
  for (size_t i = 0; i < v.size(); i++) {
    T& e = v[i];
    if (e > max)
    e = max;
    else if (e < min)
    e = min;
  }
}

int main() {
	
vector<int> v { };
normalise(v, 0, 1);
print(v);
  return 0;
}