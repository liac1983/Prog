#include <iostream>
using namespace std;

int main(){
    int r = 0;
    int n;
    cout << "n:";
    cin >> n;
    while (n != 0){
        r = r * 10 + n % 10;
        n /= 10;
    }
    cout << r;
}