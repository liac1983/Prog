#include <iostream>
using namespace std;

void advance(int& d, int& m, int& y){
    int ldm; //last day in month
    switch(m){
        case 2:
            ldm = y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) ? 29 : 28;
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            ldm = 31;
            break;
        default:
            ldm = 30;
    }
    if (d == ldm) {
        //Last day in month
        d = 1;
        if (m == 12){
            //Last day in December
            y++;
            m = 1;
        } else{
            m++;
        }
    }else{
        d++;
    }
}
void advance(int delta, int& d, int& m, int& y){
    for (int i = 0; i < delta; i++){
        advance(d, m ,y);
    }
}

int main(){
    int d = 1, m = 1, y = 2024; advance(365, d, m, y); cout << d << ' ' << m << ' ' << y;
}