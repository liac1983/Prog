#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    cout << "a:" << "b:";
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        int n = i;
        int ones = 0;
        while (n != 0){
            ones += n % 2;
            n /= 2;
        }
        int j = 2 ;
        while (j < ones && ones % j != 0){ j++; }
        if (j == ones){
            //percinious
            // j é o nº de 1's na representação em binário
            while (j < i && i % j != 0){ j++; }
                if(j == i){
                    //prime
                    cout << i << endl;
                }
        }
    }
    return 0;
}