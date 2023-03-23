#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// template class Pair
template <typename T1, typename T2>
class Pair {
public:
    Pair(const T1& first, const T2& second) : first_(first), second_(second) { }
    T1 get_first() const { return first_;}
    T2 get_second() const {return second_;}
    void show() const {std::cout << '{' << first_ << ',' << second_ << '}';}
private:
    T1 first_;
    T2 second_;
};

// Compare two pairs based on the value of first_
bool compare_first(const Pair<string, int>& p1, const Pair<string, int>& p2) {
    return p1.get_first() < p2.get_first();
}

// compare two pairs based on the value of second_
bool compare_second(const Pair<string, int>& p1, const Pair<string, int>& p2) {
    return p1.get_second() < p2.get_second();
}

// sort a vector of pairs by first
void sort_by_first(vector<Pair<string, int>>& v) {
    sort(v.begin(), v.end(), compare_first);
}

//sort a vector of pairs by second
void sort_by_second(vector<Pair<string, int>>& v) {
    sort(v.begin(), v.end(), compare_second);
}

// print a vector of pairs
void show(const vector<Pair<string, int>>& v) {
    cout << '{';
    for (const auto& p : v)
        p.show();
    cout << '}';
}

int main() {
    vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
sort_by_first(persons);
show(persons); cout << '\n';
    return 0;
}