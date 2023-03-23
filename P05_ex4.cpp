#include <iostream>
using namespace std;

// Complex number
struct complex {
    int real;   // Real part
    int img;    // Imaginary part
};

// Print array of complex numbers
void print(const complex z[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        if (z[i].real == 0 && z[i].img == 0)
            cout << 0;
        else {
            if(z[i].real != 0)
                cout << z[i].real;
            if (z[i].img > 0)
                cout << '+' << z[i].img << 'i';
            else if (z[i].img < 0)
                cout << z[i].img << 'i';
        }
        cout << ' ';
    }
    cout << "]\n";
}

// Add two complex numbers
complex add(complex a, complex b) {
    return { a.real + b.real, a.img + b.img};
}

// Multiply two complex numbers
complex mul(complex a, complex b) {
    return { a.real * b.real - a.img * b.img, a.real * b.img + b.real * a.img };
}

// Compute the first n complex numbers of Mandelbrot set recurrence defined for c.
void mandel(complex c, int n, complex z[]) {
    z[0] = { 0, 0 };
    for (int i = 1; i < n; i++) {
        z[i] = add(mul(z[i-1], z[i-1]), c);
    }
}

int main() {
complex c = { 0, 0 };
const int n = 1;
complex z[n];
mandel(c, n, z);
print(z, n);
    return 0;
}