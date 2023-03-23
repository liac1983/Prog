#include <iostream>
using namespace std;

unsigned long bc(unsigned long n, unsigned long k) {
  unsigned long num = 1;
  unsigned long den = 1;
  for (unsigned long i = 1; i<= k; i++) {
     num *= (n - i + 1);
     den *= i;
  }
  return num/den;
}

unsigned long bell(unsigned long n){
    if (n <= 1) return 1;
    unsigned long int r = 0;
    for (unsigned long k = 0; k < n;k++){
        r += bc(n-1, k) * bell(k);
    }
    return r;
}

int main(){
    cout << bell(0) << '\n' << bell(1) << '\n' << bell(2) << '\n' << bell(3) << '\n' << bell(4) << '\n';
}
 
 