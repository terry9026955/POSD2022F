#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec): _lengthVec(lengthVec), _widthVec(widthVec) {
        // if (abs(lengthVec->cross(widthVec) - lengthVec->length() * widthVec->length()) >= 0.001) {
        //     throw std::string("error: can not init a rectangle without 2 vertical vectors");
        // }
        if (!(lengthVec->a() == widthVec->a() || lengthVec->a() == widthVec->b() || lengthVec->b() == widthVec->a() || lengthVec->b() == widthVec->b())) {
            throw std::string("error: there should be exact one equal point between v1 and v2 in a rectangle");
        }
    }
    ~Rectangle() {}

    double length() const {
        return _lengthVec->length();
    }

    double width() const {
        return _widthVec->length();
    }

    double area() const override {
        return length() * width();
    }

    double perimeter() const override {
        return (length() + width()) * 2;
    }


    // max length 256
    std::string info() const override {
        char buffer[256];
        sprintf(buffer, "Rectangle (%s, %s)", _lengthVec->info().c_str(), _widthVec->info().c_str());
        return std::string(buffer);
    }


    // HW3
    std::set<const Point*> getPoints() {
        std::set<const Point*> points{_lengthVec->a(), _lengthVec->b()};
        if (_lengthVec->a() == _widthVec->a() || _lengthVec->b() == _widthVec->a()) {
            points.insert(_widthVec->b());
            if (_lengthVec->a() == _widthVec->a()) {  
                points.insert(new Point(*_lengthVec->b()+*_widthVec->b()-*_lengthVec->a()));
            } else {
                points.insert(new Point(*_widthVec->b() + *_lengthVec->a() - *_lengthVec->b()));
            }
        } else {
            points.insert(_widthVec->a());
            if (_lengthVec->a() == _widthVec->b()) {
                points.insert(new Point(*_lengthVec->b()+*_widthVec->a()-*_lengthVec->a()));
            } else {
                points.insert(new Point(*_lengthVec->a()+*_widthVec->a()-*_lengthVec->b()));
            }
        }
        return points;
    }

    void accept(ShapeVisitor* visitor) {
        visitor->visitRectangle(this);
    };
};