#pragma once

#include <cmath>

#include <iostream>
using namespace std;

class Point
{
private:
    const double _x = 0.0;
    const double _y = 0.0;

public:
    Point(double x, double y): _x(x), _y(y) {}
    ~Point() {}

    double x() const {  // point x
        return _x;
    }

    double y() const {  // point y
        return _y;
    }

    bool operator==(const Point &pt) const {    // Operator overloading
        return (int(this->x()) == int(pt.x())) && (int(this->y()) == int(pt.y()));
    } 

    std::string info() const {
        double _rx = round(_x * 100.0) / 100.0 ;
        double _ry = round(_y * 100.0) / 100.0 ;
        std::string strx = std::to_string(_rx);
        std::string stry = std::to_string(_ry);
        decimalplace(strx, 2);
        decimalplace(stry, 2);
        return "(" + strx + ", " + stry + ")";
    }

    // 額外的小數點後2位處理
    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i + index + 1);   // Deletes all characters after 2 decimal places
                break;
            }
        }
    }
};
