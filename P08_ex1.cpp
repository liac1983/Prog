#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Point2d.h"


double Point2d::distance_to(const Point2d& p) const {
    double dx = x - p.x; double dy = y - p.y;
    return std::sqrt(dx*dx+dy*dy);
}

void Point2d::translate(const Point2d& t) {
    x += t.x;
    y += t.y;
}

int main() {
    Point2d a { 1.0, 2.1 };
a.translate({ -0.3, 0.5 });
cout << fixed << setprecision(2)
     << a.get_x() << ' ' << a.get_y() << '\n';
    return 0;
}