#include <cmath>

int solve_eq(int a, int b, int c, double& x1, double& x2) {
  int delta = b * b - 4 * a * c;
  if (delta < 0) {
    x1 = x2 = NAN;
    return 0;
  }
  if (delta == 0) {
    x1 = - b / (2.0 * a);  // We must use 2.0, not 2
    x2 = NAN;
    return 1;
  }
  double d = sqrt(delta);
  x1 = (-b - d) / (2.0 * a);
  x2 = (-b + d) / (2.0 * a);
  return 2;
}

int main(){
    double x1, x2; int r = solve_eq(1, -2, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2;
}