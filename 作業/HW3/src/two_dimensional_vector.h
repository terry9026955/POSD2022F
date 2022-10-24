#pragma once

#include <cmath>
#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b): _a(a), _b(b) {}
    ~TwoDimensionalVector() {}

    const Point *a() const {
        return _a;
    }

    const Point *b() const {
        return _b;
    }

    // vector point
    const Point vp() const {
        Point vec_temp(_b->x() - _a->x(), _b->y() - _a->y());
        return vec_temp;
    }

    double length() const {
        return sqrt( ( vp().x() * vp().x() ) + ( vp().y() * vp().y() ) );
    }

    double dot(const TwoDimensionalVector *vec) const {
        // x1 * x2 + y1 * y2 (dot product)
        return ( vp().x() * vec->vp().x()) + ( vp().y() * vec->vp().y() );
    }

    double cross(const TwoDimensionalVector *vec) const {
        //  x1 * y2 - y1 * x2 (cross product)
        return ( vp().x() * vec->vp().y() ) - ( vp().y() * vec->vp().x() );
    }

    std::string info() const {
        char buffer[128];
        sprintf(buffer, "Vector (%s, %s)", _a->info().c_str(), _b->info().c_str());
        return std::string(buffer);
    }
};