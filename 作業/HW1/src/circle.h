#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"

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

    double radius() const {     // 半徑
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

    std::string info() const override {
        std::string strp1_x = std::to_string(_radiusVec->get_p1_x());
        std::string strp1_y = std::to_string(_radiusVec->get_p1_y());
        std::string strp2_x = std::to_string(_radiusVec->get_p2_x());
        std::string strp2_y = std::to_string(_radiusVec->get_p2_y());

        decimalplace(strp1_x, 2);
        decimalplace(strp1_y, 2);
        decimalplace(strp2_x, 2);
        decimalplace(strp2_y, 2);

        return "Circle (Vector ((" + strp1_x + ", " + strp1_y + "), (" + strp2_x + ", " + strp2_y + ")))";
    }

    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i + index + 1);
                break;
            }
        }
    }
};