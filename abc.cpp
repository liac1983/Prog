#include <iostream>
using namespace std;

void f(char* s){
    char* p = s;
    char* q = s;
    while (*q != '\0') { q++; }
    while (p < p && *p != *q) { p++; q--; }
    *q = '\0';
}
int main(){
    char s[] = "leic/c++";
    f(s);
    cout<< s << '|n';
    return 0;
}