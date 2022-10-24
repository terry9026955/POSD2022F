#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2): _v1(v1), _v2(v2) {
        if (v1->cross(v2) == 0) {
            throw std::string("error: can not init a triangle with 2 parallel vectors");
        }

        if (!(v1->a() == v2->a() || v1->a() == v2->b() || v1->b() == v2->a() || v1->b() == v2->b())) {
            throw std::string("error: there should be exact one equal point between v1 and v2 in a triangle");
        }
    }
    ~Triangle() {}

    double area() const override {
        return abs(_v1->cross(_v2) / 2);
    }

    double perimeter() const override {
        TwoDimensionalVector *v3;
        if (_v1->a() ==_v2->a()) {
            v3 = new TwoDimensionalVector(_v1->b(), _v2->b());
        }
        if (_v1->a() ==_v2->b()) {
            v3 = new TwoDimensionalVector(_v1->b(), _v2->a());
        }
        if (_v1->b() ==_v2->a()) {
            v3 = new TwoDimensionalVector(_v1->a(), _v2->b());
        }
        if (_v1->b() ==_v2->b()) {
            v3 = new TwoDimensionalVector(_v1->a(), _v2->a());
        }
        double v3Length = v3->length();
        delete(v3);
        return _v1->length() + _v2->length() + v3Length;
    }

    // max length 256
    std::string info() const override {
        char buffer[256];
        sprintf(buffer, "Triangle (%s, %s)", _v1->info().c_str(), _v2->info().c_str());
        return std::string(buffer);
    }
    

    // HW3
    std::set<const Point*> getPoints() {
        std::set<const Point*> points{_v1->a(), _v1->b()};
        if (_v1->a() == _v2->a() || _v1->b() == _v2->a()) {
            points.insert(_v2->b());
        } else {
            points.insert(_v2->a());
        }
 
        return points;
    };

    void accept(ShapeVisitor* visitor) {
        visitor->visitTriangle(this);
    };
};