#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Computes the longest common prefix to all of the strings
string longest_prefix(const vector<string>& v) {
    if (v.size() == 0) {
        return "";
    }
    string prefix = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        size_t pos = 0;
        while (pos < prefix.length() && pos < v[i].length()) {
            if (v[i][pos] != prefix[pos]) break;
            pos++;
        }
        if (pos == 0) {
            return "";
        }
        if (pos < prefix.length()) {
            prefix = prefix.substr(0, pos);
        }
    }
    return prefix;
}

int main() {
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
"ap"
"ap"
cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
    return 0;
}