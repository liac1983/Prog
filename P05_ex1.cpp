#include <iostream>
using namespace std;

int main(void) {
    char c;
    cin >> c;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        cout << "LETTER";
    else if (c >= '0' && c <= '9')
        cout << "DIGIT";
    else
        cout << "OTHER";
    cout << endl;
    return 0;
}
