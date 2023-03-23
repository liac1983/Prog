#include <iostream>
using namespace std;

// Auxiliar function to print n elements of an array

void print_array(const int a[], int n){
    cout << '[' << a[0];
    for (int i = 1; i < n; i++){
        cout << ',' << a[i];
    }
    cout << "]\n";
}

// Merge two sorted arrays into a sorted array

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb){
        if (a[i] < b[j]){
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < na){
        c[k++] = a[i++];
    }
    while (j < nb){
        c[k++] = b[j++];
    }
}

int main(){
    	
const int NA = 15, NB = 15;
int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
int c[NA+NB];
merge_arrays(a, NA, b, NB, c);
print_array(c, NA+NB);
}