#include <iostream>
using namespace std;
 
//! Fraction
struct fraction {
  int num;  // Numerator
  int den;  // Denominator
};
 
//! Compute the gcd of two numbers.
int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction
fraction normalize(fraction f) {
    int g = gcd(f.num, f.den);
    int num = f.num / g;
    int den = f.den /g;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    return { num, den };
}

// Add two fractions
fraction add(fraction a, fraction b) {
    return normalize({a.num * b.den + b.num * a.den, a.den * b.den});
}

// Multiply two fractions
fraction mul(fraction a, fraction b) {
    return normalize({a.num * b.num, a.den * b.den});
}

// Evaluate the polynomial for fraction x
fraction eval(const fraction poly[], int n, fraction x){
    fraction r = poly[0];
    fraction p = x;
    for (int i = 1; i < n; i++) {
        r = add(r, mul(poly[i], p));
        p = mul(p, x);
    }
    return r;
}

int main() {
    const int n = 1;
fraction p[n] = { { 1, 2 } };
fraction x = { 3, 4 };
fraction r = eval(p, n, x);
cout << r.num << '/' << r.den << '\n';
    return 0;
}

