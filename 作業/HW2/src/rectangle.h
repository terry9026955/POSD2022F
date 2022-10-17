#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) : _lengthVec(lengthVec), _widthVec(widthVec) {
        if (lengthVec->length() <= 0 || widthVec->length() <= 0 || _lengthVec->dot(_widthVec) != 0){    // 內積=0是垂直
            throw std::string("This is not a Rectangle");
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
        return this->length() * this->width();
    }

    double perimeter() const override {
        return 2 * (this->length() + this->width());
    }

    std::string info() const override {
        // 點一
        std::string strp1_x = std::to_string(_lengthVec->get_p1_x());
        std::string strp1_y = std::to_string(_lengthVec->get_p1_y());
        std::string strp2_x = std::to_string(_lengthVec->get_p2_x());
        std::string strp2_y = std::to_string(_lengthVec->get_p2_y());

        decimalplace(strp1_x, 2);
        decimalplace(strp1_y, 2);
        decimalplace(strp2_x, 2);
        decimalplace(strp2_y, 2);

        // 點二
        std::string strp3_x = std::to_string(_widthVec->get_p1_x());
        std::string strp3_y = std::to_string(_widthVec->get_p1_y());
        std::string strp4_x = std::to_string(_widthVec->get_p2_x());
        std::string strp4_y = std::to_string(_widthVec->get_p2_y());

        decimalplace(strp3_x, 2);
        decimalplace(strp3_y, 2);
        decimalplace(strp4_x, 2);
        decimalplace(strp4_y, 2);

        return "Rectangle (Vector ((" + strp1_x + ", " + strp1_y + "), (" + strp2_x + ", " + strp2_y + ")), Vector ((" + strp3_x + ", " + strp3_y + "), (" + strp4_x + ", " + strp4_y + ")))";
    }

    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i + index + 1);
                break;
            }
        }
    }


    Iterator* createDFSIterator() override {
        return new NullIterator();
    }

    Iterator* createBFSIterator() override {
        return new NullIterator();
    }
};