#include <vector>
#include <list>
#include <iostream>
#include <sstream>
 
using namespace std;

template <typename Itr>
string to_string(Itr start, Itr end) {
    ostringstream out;
    Itr itr = start;
    out << '[';
    while(itr != end) {
        out << ' ' << itr;
        itr++;
    }
    out << " ]";
    return out.str();
}

template <typename Itr, typename T>
size_t replace(Itr start, Itr end, const T& a, const T& b) {
    Itr itr = start;
    size_t count = 0;
    while (itr != end) {
        if (*itr == a) {
            *itr = b;
            count ++;
        }
        itr++;
    }
    return count;
}

int main() {
    vector<int> v;
    cout << replace(v.begin(), v.end(), 0, 1) << ' '
     << to_string(v.cbegin(), v.cend()) << '\n';
    return 0;
}