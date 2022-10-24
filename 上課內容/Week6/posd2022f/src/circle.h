#pragma once
#include <cmath>
#include "./shape.h"
#include "./iterator.h"
#include "./null_iterator.h"
#include "./find_first_visitor.h"

class Circle : public Shape {
    public:
        Circle(double x, double y, double radius){
            this->x = x;
            this->y = y;
            this->radius = radius;
        }

        double area() const override {
            return M_PI * radius * radius;
        }

        bool include(double const px, double const py) const override {
            return (px - x) * (px - x) + (py - y) * (py - y) == radius * radius;  
        }

        Iterator* createIterator () {
            return new NullIterator();
        }

        void accept(FindFirstVisitor& visitor) override {
            visitor.visitCircle(this);
        }

    private:
        double x;
        double y;
        double radius;
};

