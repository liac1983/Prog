#include <iostream>
#include <string>
using namespace std;

string g = "xyz";

int main() {
    string inp;
    cin >> inp;
    if (inp.length() <= 2) {
        string inp2 = "abc";
        inp2.append(inp);
        cout << inp2 << '\n';
    } else {
        string* inp3 = new string("ghi");
        inp3->append(g);
        cout << (*inp3) << '\n';
    }
    return 0;
}