#include "Polygon.h"
#include "Point.h"
#include <cmath>
// Auxiliary functions

float distance(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.get_x() - p1.get_x(), 2) + std::pow(p2.get_y() - p1.get_y(), 2));
}

// Default constructor
Polygon::Polygon(): v_(std::vector<Point>{}) {}

// Constructor
Polygon::Polygon(std::vector<Point> v): v_(v) {}

// Get vertex from polygon
bool Polygon::get_vertex(size_t i, Point& p) const {
    if(i < 1 || i > v_.size()) {
        return false;
    }
    p = v_[i-1];
    return true;
}

// Add vertex to polygon
void Polygon::add_vertex(size_t i, Point p) {
    v_.insert(v_.begin()+i-1, p);
}

// Calculates the perimeter
float Polygon::perimeter() const {
    float sum = 0;
    for(size_t i = 0; i < v_.size()-1; i++) {
        sum += distance(v_[i], v_[i+1]);
    }
    sum += distance(v_[v_.size()-1], v_[0]);
    return sum;
}

// Show polygon
void Polygon::show() const {
    std::cout << '{';
    for(size_t i = 0; i < v_.size(); i++) {
        v_[i].show();
    }
    std::cout << '}';
}