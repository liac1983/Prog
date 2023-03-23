#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct sm_entry {
  size_t row;
  size_t col;
  int value;
};

typedef vector<sm_entry> smatrix;

//! Print a sparse matrix.
void print(const smatrix& sm) {
  cout << "[ ";
  for (sm_entry e : sm) {
    cout << '(' << e.row << ", " << e.col << ", " << e.value << ") ";
  }
  cout << "]\n";
}

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t a_pos = 0;
    size_t b_pos = 0;
    // loop until the end of one of the vectors is reached (possibly in both)
    while (a_pos < a.size() && b_pos < b.size()) {
        sm_entry e_a = a[a_pos];
        sm_entry e_b = b[b_pos];
        if (e_a.row == e_b.row && e_a.col == e_b.col) {
            // same position - calculate sum of values
            int v = e_a.value + e_b.value;
            if(v != 0){
                r.push_back({ e_a.row, e_a.col, v});
            }
            a_pos++;
            b_pos++;
        }
        else if (e_a.row < e_b.row || (e_a.row == e_b.row && e_a.col < e_b.col)) {
            // sum entry in a to result
            r.push_back(e_a);
            a_pos++;
        }
        else {
            // sum entry in b to result
            r.push_back(e_b);
            b_pos++;
        }
    }
    // Reached end of a or b
    while (a_pos < a.size()) {
        r.push_back(a[a_pos]);
        a_pos++;
    }
    while (b_pos < b.size()) {
        r.push_back(b[b_pos]);
        b_pos++;
    }
}

int main() {
    smatrix r;
sum({ },
    { {0, 3, 1}, {0, 50, 1} },
    r);
print(r);
    return 0;
}