#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2) {
        // 外積=0是平行
        if((_v1->cross(_v2) == 0) || _v1->length() <= 0 || _v2->length() <= 0) {   
            throw string ("This is not a Triangle");
        }
        // 檢查重疊點 (XY座標一一比對)
        if( (_v1->a()->x() == _v2->a()->x() && _v1->a()->y() == _v2->a()->y()) ||   
            (_v1->a()->x() == _v2->b()->x() && _v1->a()->y() == _v2->b()->y()) || 
            (_v1->b()->x() == _v2->a()->x() && _v1->b()->y() == _v2->a()->y()) ||
            (_v1->b()->x() == _v2->b()->x() && _v1->b()->y() == _v2->b()->y()) ) {
            ;
        } else {
            throw std::string("This is not a Triangle");
        }
    }
    ~Triangle() {}

    double area() const override {
        // 三角形面積: 外積 / 2 
        double cross_vector = _v1->cross(_v2);
        double ans = cross_vector / 2;
        return fabs(ans);   // 取絕對值
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
        return _v1->length() + _v2->length() + v3->length();
    }

    std::string info() const override {
        // 點一
        std::string strp1_x = std::to_string(_v1->get_p1_x());
        std::string strp1_y = std::to_string(_v1->get_p1_y());
        std::string strp2_x = std::to_string(_v1->get_p2_x());
        std::string strp2_y = std::to_string(_v1->get_p2_y());

        decimalplace(strp1_x, 2);
        decimalplace(strp1_y, 2);
        decimalplace(strp2_x, 2);
        decimalplace(strp2_y, 2);

        // 點二
        std::string strp3_x = std::to_string(_v2->get_p1_x());
        std::string strp3_y = std::to_string(_v2->get_p1_y());
        std::string strp4_x = std::to_string(_v2->get_p2_x());
        std::string strp4_y = std::to_string(_v2->get_p2_y());

        decimalplace(strp3_x, 2);
        decimalplace(strp3_y, 2);
        decimalplace(strp4_x, 2);
        decimalplace(strp4_y, 2);

        return "Triangle (Vector ((" + strp1_x + ", " + strp1_y + "), (" + strp2_x + ", " + strp2_y + ")), Vector ((" + strp3_x + ", " + strp3_y + "), (" + strp4_x + ", " + strp4_y + ")))";
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