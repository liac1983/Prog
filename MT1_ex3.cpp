#include<iostream>
using namespace std;

bool heterogram(const char s[], char r[]) {
    int count[26] = { 0 };
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ') {
            if(s[i] >= 'a' && s[i] <= 'z')
                count[s[i] - 'a']++;
            else    count[s[i] - 'A']++;
        }
    }
    int n_r = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c - 'a'] > 1 ) {
            r[n_r] = c;
            n_r++;
        }
    }
    r[n_r] = '\0';
    return n_r == 0;
}

int main() {
    char s[] = "";
char r[27] = { -1 };
bool b = heterogram(s, r);
cout << '\"' << s << "\" "
     << boolalpha << b << " \"" << r << "\"\n";
    return 0;
}