#include <iostream>
#include <map>
 
using namespace std;

// converts roman numbers to arabic numbers
unsigned roman_to_arab(const string& s) {
    static map<char, unsigned> map_roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};

unsigned decimal = 0;
for (size_t i = 0, n = s.length(); i < n; i++) {
    unsigned this_dec = map_roman[s[i]];
    if (i < n && this_dec < map_roman[s[i+1]]) decimal -= this_dec;
    else decimal += this_dec; 
}
return decimal;
}

int main() {
    string r = "XV";
cout << roman_to_arab(r) << '\n';
    return 0;
}