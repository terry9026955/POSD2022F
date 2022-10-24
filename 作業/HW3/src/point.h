#pragma once

#include <cmath>
#include <sstream>
#include <string>

class Point
{
private:
    const double _x;
    const double _y;

public:
    Point(double x, double y): _x(x), _y(y){}
    ~Point(){}

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    bool operator==(const Point &pt) const {
        return round(_x * 100) / 100 == round(pt.x() * 100) / 100 && round(_y * 100) / 100 == round(pt.y() * 100) / 100;
    }

    // HW3
    // For getPoints()
    Point operator-(const Point &pt) const {
        return Point(_x-pt.x(), _y-pt.y());
    }

    Point operator+(const Point &pt) const {
        return Point(_x+pt.x(), _y+pt.y());
    }

    // max length: 128
    std::string info() const {
        char buffer[128];
        sprintf(buffer, "(%.2f, %.2f)", round(_x * 100) / 100, round(_y * 100) / 100);
        return std::string(buffer);
    }
};
