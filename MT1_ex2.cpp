#include<iostream>
using namespace std;

bool is_prime(int number) {
  if (number <= 1) return 0;
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) return false;
  }
  return true;
}

void print(int a[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "]";
    cout << endl;
}

void keep_prime_numbers(int a[], int& size) {
    int i = 0;
    while (i < size) {
        if (!is_prime(a[i])) {
            for (int j = i; j < size -1; j++) {
                a[j] = a[j + 1];
            }
            size--;
        }
        else {
            i++;
        }
    }
}

int main() {
    int a[] = { 1, 2, 3 };
int size = sizeof(a) / sizeof(int);
keep_prime_numbers(a, size);
print(a, size);
    return 0;
}