#pragma once
#include "./shape.h"
#include "./find_first_visitor.h"

class Square : public Shape
{
public:
    Square(double lx, double ly, double length)
        : _lx(lx), _ly(ly), _length(length) {}

    double area() const override
    {
        return _length * _length;
    }

    void accept(FindFirstVisitor &visitor) override
    {
        visitor.visitSquare(this);
    }

private:
    double _lx;
    double _ly;
    double _length;
};