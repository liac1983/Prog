#include <iostream>
using namespace std;

bool is_mersenne_number(unsigned long n){
    do{
        if(n % 2 == 0){
            return false;
        }
        n /= 2;
    } while(n != 0);
    return true;
}

int main(){
    cout << is_mersenne_number(0) << '\n' << is_mersenne_number(3) << '\n' << is_mersenne_number(4) << '\n' << is_mersenne_number(65535) << '\n' << is_mersenne_number(18446744073709551614UL);
}