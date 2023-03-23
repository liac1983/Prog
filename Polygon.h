#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "Point.h"

class Polygon {
    public:
        Polygon();
        Polygon(std::vector<Point> v);
        bool get_vertex(size_t i, Point& p) const;
        void add_vertex(size_t i, Point p);
        float perimeter() const;
        void show() const;
    private:
        std::vector<Point> v_;
};

#endif