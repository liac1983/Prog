#include <iostream>
#include <algorithm>
using namespace std;

int adigits(int a, int b, int c){
    int e = max(a, max(b,c));
    int u = min(a, min(b,c));
    int d = a+b+c-e-u;
    return e*100+d*10+u;
}

int main(){
    cout << adigits(1, 2, 3) << '\n' << adigits(1, 0, 0);
    ;
}