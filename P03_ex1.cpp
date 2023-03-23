#include <iostream>;
using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long r = 0;    //Acc
    int i = 0;
    while(hstr[i] != '\0'){
        unsigned long v2 = 0;
        char c = hstr[i];
        if (c >= '0' && c <= '9')   v2 = c - '0';
        else if (c >= 'A' && c <= 'F')  v2 = c - 'A' + 10;
        else v2 = c - 'a' + 10;
        r = r * 16 + v2;
    i++;
    }
    return r;
}

int main(){
    cout << hstr_to_integer("0") << '\n' << hstr_to_integer("A") << '\n' << hstr_to_integer("19") << '\n' << hstr_to_integer("fF") << '\n' << hstr_to_integer("CafeBabe2022");
}