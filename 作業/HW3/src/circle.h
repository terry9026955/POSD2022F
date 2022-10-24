#pragma once

#include <string>
#include <cmath>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;

public:
    Circle(TwoDimensionalVector *radiusVec): _radiusVec(radiusVec) {
        if (radiusVec->length() == 0) {
            throw std::string("This is not a Circle");
        }
    }
    ~Circle() {}

    double radius() const {
        return _radiusVec->length();
    }

    double area() const override {
        // pi * r^2
        return M_PI * this->radius() * this->radius();
    }

    double perimeter() const override {
        // 2 * pi * r
        return M_PI * this->radius() * 2;
    }

    // max length 256
    std::string info() const override {
        char buffer[256];
        sprintf(buffer, "Circle (%s)", _radiusVec->info().c_str());
        return std::string(buffer);

        // 原始寫法:
        // std::string strp1_x = std::to_string(_radiusVec->get_p1_x());
        // std::string strp1_y = std::to_string(_radiusVec->get_p1_y());
        // std::string strp2_x = std::to_string(_radiusVec->get_p2_x());
        // std::string strp2_y = std::to_string(_radiusVec->get_p2_y());

        // decimalplace(strp1_x, 2);
        // decimalplace(strp1_y, 2);
        // decimalplace(strp2_x, 2);
        // decimalplace(strp2_y, 2);
    }

    
    // HW3
    std::set<const Point*> getPoints() {
        return std::set<const Point*>{new Point(_radiusVec->a()->x() + radius(), _radiusVec->a()->y() + radius()), new Point(_radiusVec->a()->x() - radius(), _radiusVec->a()->y() - radius())};
    };

    void accept(ShapeVisitor* visitor) {
        visitor->visitCircle(this);
    };
};