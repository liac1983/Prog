
#include <iostream>
using namespace std;

// print array
void print(int a[], int size) {
    cout << "[ ";
    for (int i  = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "]";
    cout << endl;
}

// Removes all the duplicate elements
void remove_duplicates(int a [] , int& size) {
    int i = 0;
    while (i < size - 1) {
        if (a[i] == a[i + 1]) {
            for (int j  = i; j < size - 1; j++) {
                a[j] = a[j + 1];
            }
            size--;
        }
        else {
            i++;
        }
    }
}

int main(){
int a[] = { 1, 2, 3 };
int size = sizeof(a) / sizeof(int);
remove_duplicates(a, size);
print(a, size);
    return 0;
}