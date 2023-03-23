#include <string>
using namespace std;

// Determines if a string is a pangram
bool pangram(const string& s, string& m) {
    int count [26] = {0};
    //existing char
    for (size_t i = 0; i< s.length(); i++){
        char c = s[i];
        if (c >= 'a' && c <= 'z') count[c - 'a']++;
        else if (c >= 'A' && c <='Z') count[c -'A']++;
    }
    // missing char 
    for (int i = 0; i< 26 ; i++) {
        if (count[i] == 0) m.push_back(i + 'a');
    }
    return m.length() == 0;
}

int main() {
string s = "The quick brown fox jumps over the lazy dog";
string m = "";
bool r = pangram(s, m);
cout << '\"' << s << "\" " 
     << boolalpha << r << " \"" << m << "\"\n";
    return 0;
}