#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

// Compute the number of occurrences of the word in the file
int count(const string& fname, const string& word) {
    ifstream in(fname);
    string word_uc = word;
    for (char& c : word_uc) c = toupper(c);
    int n = 0;
    for (string s; in >> s;) {
        for (char& c : s) c = toupper(c);
        if (s == word_uc) n++;
    }
    return n;
}

int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
    return 0;
}