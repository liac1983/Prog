#include <iostream>
using namespace std;

struct fraction {
   int num; // Numerator
   int den; // Denominator
}; 

// Return the Greatest Common Divisor (gdc) of two numbers

int gcd_rec(int a, int b){
    if (b == 0) return a;
    else return gcd_rec(b,a % b);
}

int gcd(int a, int b){
    while (b != 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

// Return the sum of two fractions as an irreducible fraction

fraction sum(const fraction fa[], int n){
    fraction s{ 0, 1 };
    for (int i = 0; i < n; i++){
        int n = s.num * fa[i].den + fa[i].num * s.den,
        d = s.den * fa[i].den,
        g = gcd(n, d);
    s.num = n / g;
    s.den = d / g;
    }
    if(s.den < 0){
        s.num = -s.num;
        s.den = -s.den;
    }
    return s;
}
int main(){
    	
	
fraction fa[] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5}};
fraction s = sum(fa, 5);
cout << s.num << '/' << s.den << "\n";
}