#include<iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b && a == c)
        cout << "equilateral";
    else if (a == b || a == c || b == c)
        cout << "isosceles";
    else 
        cout << "scalene";
    return 0;
}
