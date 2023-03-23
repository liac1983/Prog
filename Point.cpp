#include "Point.h"

// Default constructor
Point::Point(): x_(0), y_(0) {}

// Constructor
Point::Point(int x, int y): x_(x), y_(y) {}

// Get x
int Point::get_x() const { return x_; }

// Get y
int Point::get_y() const { return y_; }

// Show coordinates
void Point::show() const {
    std::cout << '(' << x_ << ',' << y_ << ')';
}