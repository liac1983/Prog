#include <iostream>
using namespace std;

int main(){
    int i = 10;
    do{
        cout << i;
        i--;
    } while (i%2 != 0);
}