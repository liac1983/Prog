#include "Point.h"

using namespace std;

// constructores
Point::Point(): x_(0), y_(0){}
Point::Point(int x, int y): x_(x), y_(y) {}
Point::Point::Point(const Point& p): x_(p.x_), y_(p.y_) {}

// acessors
int Point::get_x() const{return x_;}
int Point::get_y() const{return y_;}

// operator overloading
Point& Point::operator=(const Point& p) {
    x_ = p.x_; y_ = p.y_;
    return *this;
}

Point Point::operator + (const Point& p) const{
    int a = x_ + p.x_;
    int b = y_ + p.y_;
    return Point(a, b);
}

Point& Point::operator += (const Point& p){
    x_ += p.x_; y_ += p.y_;
    return *this;
}

Point Point::operator*(int v) const{
    return Point(v*x_, v*y_);
}

Point operator*(int x, const Point& p){
    return Point(x*p.get_x(), x*p.get_y());
}

ostream& operator << (std::ostream& os, const Point& p){
    os << '(' << p.get_x() << ',' << p.get_y() << ')';
    return os;
}

int main() {
    Point a, b(1,2), c(b), d(3,4); 
    b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    return 0;
}