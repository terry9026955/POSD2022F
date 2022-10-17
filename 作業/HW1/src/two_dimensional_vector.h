#pragma once

#include <cmath>
#include "point.h"

#include <iostream>
using namespace std;

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

    // Getter: 點一與點二的 X 和 Y 座標
    double get_p1_x() const {
        return _a->x();
    }

    double get_p1_y() const {
        return _a->y();
    }

    double get_p2_x() const {
        return _b->x();
    }

    double get_p2_y() const {
        return _b->y();
    }
    // Getter

    double length() const { // 座標相減求長度
        double len1 = _a->x() - _b->x();
        double len2 = _a->y() - _b->y();
        double len = sqrt(pow(len1,2)+pow(len2,2));
        return len;
    }

    double dot(const TwoDimensionalVector *vec) const {
        // x1 * x2 + y1 * y2 (dot product)
        
        // 自己的點座標
        double myp1_x = this->a()->x();
        double myp1_y = this->a()->y();
        double myp2_x = this->b()->x();
        double myp2_y = this->b()->y();
        //自己的向量座標
        double myvec_x = myp2_x-myp1_x; // X向量 (x1)
        double myvec_y = myp2_y-myp1_y; // Y向量 (x2)

        // vec 的點座標
        double x1 = vec->a()->x();
        double x2 = vec->a()->y();
        double y1 = vec->b()->x();
        double y2 = vec->b()->y();
        // vec 的向量座標
        double vec_x = y1-x1;           // X向量 (y1)
        double vec_y = y2-x2;           // Y向量 (y2)
        
        return myvec_x * vec_x + myvec_y * vec_y;
    }

    double cross(const TwoDimensionalVector *vec) const {
        //  x1 * y2 - y1 * x2 (cross product)
        // 自己的點座標
        double myp1_x = this->a()->x();
        double myp1_y = this->a()->y();
        double myp2_x = this->b()->x();
        double myp2_y = this->b()->y();
        //自己的向量座標
        double myvec_x = myp2_x-myp1_x; // X向量 (x1)
        double myvec_y = myp2_y-myp1_y; // Y向量 (x2)

        // vec 的點座標
        double x1 = vec->a()->x();
        double x2 = vec->a()->y();
        double y1 = vec->b()->x();
        double y2 = vec->b()->y();
        // vec 的向量座標
        double vec_x = y1-x1;           // X向量 (y1)
        double vec_y = y2-x2;           // Y向量 (y2)
        
        return myvec_x * vec_y - vec_x * myvec_y;
    }

    std::string info() const {
        std::string strp1_x = std::to_string(this->get_p1_x());
        std::string strp1_y = std::to_string(this->get_p1_y());
        std::string strp2_x = std::to_string(this->get_p2_x());
        std::string strp2_y = std::to_string(this->get_p2_y());
        decimalplace(strp1_x, 2);
        decimalplace(strp1_y, 2);
        decimalplace(strp2_x, 2);
        decimalplace(strp2_y, 2);
        //std::cout << "Vector ((" << this->get_p1_x() << ", " << this->get_p1_y() << "), (" << this->get_p2_x() << "," << this->get_p2_y() << "))" << endl;
        return "Vector ((" + strp1_x + ", " + strp1_y + "), (" + strp2_x + ", " + strp2_y + "))";
    }

    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i + index + 1);
                break;
            }
        }
    }

    // TwoDimensionalVector substract(const TwoDimensionalVector *vec) const { 
    //     // x1-x2, y1-y2
    //     TwoDimensionalVector sub_result(this->_a - vec->a(), this->_b - vec->b());
    //     return sub_result;
    // }
};