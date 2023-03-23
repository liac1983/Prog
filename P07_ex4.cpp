#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double average(const string& fname) {
    double counter = 0, soma = 0, num = 0;
    ifstream in(fname);
    while (!in.eof()) {
        if (in >> num) {
            soma += num;
            counter += 1;
        }
        else {
            in.clear();
            in.ignore(1);
        }
    }
    return soma / counter;
}

int main() {
    	
double m = average("p4_test1.txt");
cout << fixed << setprecision(2) << m << '\n';
    return 0;
}