class Fraction {
public:
  Fraction();                            // default constructor
  Fraction(int num, int den);            // constructor from numerator and denominator values
  int numerator() const;                 // return numerator value
  int denominator() const;               // return denominator value
  Fraction sum(const Fraction& right);   // sum this fraction with 'right'
  Fraction sub(const Fraction& right);   // subtract 'right' to this fraction
  Fraction mul(const Fraction& right);   // multiply this fraction with 'right'
  Fraction div(const Fraction& right);   // divide this fraction with 'right'
  void normalise();                      // normalise fraction (irreducible & negative sign in numerator)
  void write() const;                    // shows fraction f on the screen
private:
  static int gcd(int a, int b);  // computes greatest common denominator of two integers
  // attributes
  int numerator_;    // fraction numerator
  int denominator_;  // fraction denominator
};

#include <iostream>
#include <cmath>

using namespace std;

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalise a fraction.
void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

// shows fraction on the screen
void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}

Fraction::Fraction() : numerator_(0), denominator_(1) { }

Fraction::Fraction(int num, int den) : numerator_(num), denominator_(den) {
  normalise();
}

int Fraction::numerator() const {
  return numerator_;
}

int Fraction::denominator() const {
  return denominator_;
}

Fraction Fraction::sum(const Fraction& right) {
  return Fraction(numerator_ * right.denominator_ + right.numerator_ * denominator_,
                  denominator_ * right.denominator_);
}

Fraction Fraction::sub(const Fraction& right) {
  return Fraction(numerator_ * right.denominator_ - right.numerator_ * denominator_,
                  denominator_ * right.denominator_);
}

Fraction Fraction::mul(const Fraction& right) {
  return Fraction(numerator_ * right.numerator_, 
                  denominator_ * right.denominator_);
}

Fraction Fraction::div(const Fraction& right) {
  return Fraction(numerator_ * right.denominator_, 
                  denominator_ * right.numerator_);
}

int main() {
    Fraction().sum({2, 4}).write(); cout << ' ';
    Fraction(1,1).sum({2, 4}).write(); cout << ' ';
    Fraction(2,4).sum({3, 9}).write(); cout << ' ';
    Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
    Fraction(3,27).sum({-27, 81}).write(); cout << '\n';
    return 0;
}